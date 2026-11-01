import typing
import abc


class InvalidDataError(Exception):
    pass


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self._name = "Data Processor"
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

    def print_stats(self) -> None:
        print(f"{self._name}: total {self._current_input} items processed,"
              f" remaining {len(self._data)} on processor")


class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()
        self._name = "Numeric Processor"

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
    def __init__(self) -> None:
        super().__init__()
        self._name = "Text Processor"

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
    def __init__(self) -> None:
        super().__init__()
        self._name = "Log Processor"

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


class ExportPlugin(typing.Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("CSV Output:")
        if len(data) < 1:
            print("No data available")
        else:
            export = data.copy()
            last = export.pop()
            for item in export:
                print(f"{item[1]},", end="")
            print(last[1])


class JSONExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("JSON Output:")
        if len(data) < 1:
            print("No data available")
        else:
            export = data.copy()
            last = export.pop()
            print('{', end='')
            for item in export:
                print(f'"item_{item[0]}": "{item[1]}", ', end='')
            print(f'"item_{last[0]}": "{last[1]}"', end='')
            print('}')


class DataStream:
    def __init__(self) -> None:
        self._procs: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._procs.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for item in stream:
            processed = False
            for proc in self._procs:
                if proc.validate(item):
                    proc.ingest(item)
                    processed = True
                    break
            if not processed:
                print("DataStream error"
                      f" - Can't process element in stream: {item}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if len(self._procs) < 1:
            print("No processor found, no data")
        else:
            for proc in self._procs:
                proc.print_stats()

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self._procs:
            export: list[tuple[int, str]] = []
            for _ in range(nb):
                output = proc.output()
                if output[0] >= 0:
                    export.append(output)
            plugin.process_output(export)


def test_csv(stream: DataStream) -> None:
    log1 = {
        'log_level': 'WARNING',
        'log_message': 'Telnet access! Use ssh instead'
    }
    log2 = {
        'log_level': 'INFO',
        'log_message': 'User wil is connected'
    }
    data1 = [
        'Hello world',
        [3.14, -1, 2.71],
        [log1, log2],
        42,
        ['Hi', 'five']
    ]
    print(f"\nSend first batch of data on stream: {data1}\n")
    stream.process_stream(data1)
    stream.print_processors_stats()
    print("\nSend 3 processed data from each processor to a CSV plugin:")
    csv = CSVExportPlugin()
    stream.output_pipeline(3, csv)
    print("")
    stream.print_processors_stats()


def test_json(stream: DataStream) -> None:
    log3 = {
        'log_level': 'ERROR',
        'log_message': '500 server crash'
    }
    log4 = {
        'log_level': 'NOTICE',
        'log_message': 'Certificate expires in 10 days'
    }
    data2 = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [log3, log4],
        [32, 42, 64, 84, 128, 168],
        'World hello'
    ]
    print(f"\nSend another batch of data: {data2}\n")
    stream.process_stream(data2)
    stream.print_processors_stats()
    print("\nSend 5 processed data from each processor to a JSON plugin:")
    json = JSONExportPlugin()
    stream.output_pipeline(5, json)
    print("")
    stream.print_processors_stats()


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===")
    print("\nInitialize Data Stream...\n")
    stream = DataStream()
    stream.print_processors_stats()
    print("\nRegistering Processors")
    num = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    stream.register_processor(num)
    stream.register_processor(text)
    stream.register_processor(log)
    test_csv(stream)
    test_json(stream)


if __name__ == "__main__":
    main()
