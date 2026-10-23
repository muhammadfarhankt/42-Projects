def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    input_values = ["25", "abc"]
    for value in input_values:
        print(f"\nInput data is '{value}'")
        try:
            result = input_temperature(value)
            print(f"Temperature is now {result}°C")
        except ValueError as e:
            print(f"Caught input_temperature error: {e}")
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    print("=== Garden Temperature ===")
    test_temperature()
