import sys
import typing


def display_file(file: typing.IO[str]) -> None:
    print("---\n")
    print(file.read())
    print("---\n")


def main() -> None:
    if len(sys.argv) < 2:
        print("Usage: ft_ancient_text.py <file>")
    else:
        print("=== Cyber Archives Recovery ===")
        file_name = sys.argv[1]
        print(f"Accessing file '{file_name}'")
        try:
            f = open(file_name, "r")
            display_file(f)
            f.close()
            print(f"File '{file_name}' closed.")
        except Exception as e:
            print(f"Error opening file '{file_name}': {e}")


if __name__ == "__main__":
    main()
