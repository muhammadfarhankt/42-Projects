import typing
import abc


class InvalidDataError(Exception):
    pass


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self._data: dict[int, str] = {}
        self._current_input = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if len(self._data) > 0:
            oldest = min(self._data.keys())
            return (oldest, self._data.pop(oldest))
        else:
            return (-1, "Error: No data available")


class NumericProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, list):
            return all(
                (isinstance(x, (int, float)) and not isinstance(x, bool))
                for x in data
            )
        else:
            return (
                isinstance(data, (int, float))
                and not isinstance(data, bool)
            )

    def ingest(
        self,
        data:  int | float | list[int] | list[float] | list[int | float]
    ) -> None:
        if self.validate(data):
            if isinstance(data, (int, float)):
                self._data[self._current_input] = str(data)
                self._current_input += 1
            else:
                for item in data:
                    self._data[self._current_input] = str(item)
                    self._current_input += 1
        else:
            raise InvalidDataError("Improper numeric data")


class TextProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, list):
            return all(isinstance(x, str) for x in data)
        else:
            return isinstance(data, str)

    def ingest(self, data:  str | list[str]) -> None:
        if self.validate(data):
            if isinstance(data, str):
                self._data[self._current_input] = data
                self._current_input += 1
            else:
                for item in data:
                    self._data[self._current_input] = item
                    self._current_input += 1
        else:
            raise InvalidDataError("Improper text data")


class LogProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if not isinstance(data, list):
            data_list = [data]
        else:
            data_list = data
        if all((isinstance(x, dict) and len(x) == 2) for x in data_list):
            for d in data_list:
                if (
                    not all(isinstance(x, str) for x in d.values())
                    or "log_level" not in d
                    or "log_message" not in d
                ):
                    return False
            return True
        else:
            return False

    def ingest(self, data:  dict[str, str] | list[dict[str, str]]) -> None:
        if self.validate(data):
            if isinstance(data, dict):
                s = f"{data['log_level']}: {data['log_message']}"
                self._data[self._current_input] = s
                self._current_input += 1
            else:
                for item in data:
                    s = f"{item['log_level']}: {item['log_message']}"
                    self._data[self._current_input] = s
                    self._current_input += 1
        else:
            raise InvalidDataError("Improper log data")


def test_num() -> None:
    print("\nTesting Numeric Processor...")
    num = NumericProcessor()
    print(f" Trying to validate input '42': {num.validate(42)}")
    print(f" Trying to validate input 'Hello': {num.validate('Hello')}")
    print(" Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num.ingest('foo')
    except InvalidDataError as e:
        print(f" Got exception: {e}")
    num_data = [1, 2, 3, 4, 5]
    print(f" Processing data: {num_data}")
    num.ingest(num_data)
    print(" Extracting 3 values...")
    for _ in range(3):
        output = num.output()
        print(f" Numeric value {output[0]}: {output[1]}")


def test_text() -> None:
    print("\nTesting Text Processor...")
    text = TextProcessor()
    print(f" Trying to validate input '42': {text.validate(42)}")
    text_data = ['Hello', 'Nexus', 'World']
    print(f" Processing data: {text_data}")
    text.ingest(text_data)
    print(" Extracting 1 value...")
    output = text.output()
    print(f" Text value {output[0]}: {output[1]}")


def test_log() -> None:
    print("\nTesting Log Processor...")
    log = LogProcessor()
    print(f" Trying to validate input 'Hello': {log.validate('Hello')}")
    log_data = [{'log_level': 'NOTICE', 'log_message': 'Connection to server'},
                {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}]
    print(f" Processing data: {log_data}")
    log.ingest(log_data)
    print(" Extracting 2 values...")
    for _ in range(2):
        output = log.output()
        print(f" Log entry {output[0]}: {output[1]}")


def main() -> None:
    print("=== Code Nexus - Data Processor ===")
    test_num()
    test_text()
    test_log()


if __name__ == "__main__":
    main()
