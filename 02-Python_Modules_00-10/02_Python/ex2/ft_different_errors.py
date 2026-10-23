def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def garden_operations(operation_number: int) -> None:
    if (operation_number == 0):
        input_temperature("abc")
    elif (operation_number == 1):
        1 / 0
    elif (operation_number == 2):
        open("/non/existent/file")
    elif (operation_number == 3):
        "abc" + operation_number
    else:
        print("Operation completed successfully")


def test_error_types(operation_number: int) -> None:
    try:
        print(f"Testing operation {operation_number}...")
        garden_operations(operation_number)
    except ValueError as e:
        print(f"Caught ValueError: {e}")
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {e}")
    except FileNotFoundError as e:
        print(f"Caught FileNotFoundError: {e}")
    except TypeError as e:
        print(f"Caught TypeError: {e}")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    for i in range(5):
        test_error_types(i)
    print("\nAll error types tested successfully!")
