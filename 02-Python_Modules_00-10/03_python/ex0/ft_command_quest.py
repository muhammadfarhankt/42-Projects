import sys


if __name__ == "__main__":
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    arg_length = len(sys.argv)
    if arg_length == 1:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {arg_length-1}")
    i = 1
    while i < arg_length:
        print(f"Argument {i}: {sys.argv[i]}")
        i += 1
    print(f"Total arguments: {arg_length}\n")
