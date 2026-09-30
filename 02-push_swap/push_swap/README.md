*This project has been created as part of the 42 curriculum by mfarhan.*

# push_swap

Push Swap is a program that takes as argument a space separated list of numbers and outputs a list of commands that can be used to sort them. 

Sort a random list of integers using the smallest number of moves, 2 stacks and a limited set of operations.

Algorithm Used : Turk algorithm

## Description

You start with two empty stacks: **a** and **b**. You are given a random list of integers via command line arguments.
<br />

Only these moves are allowed:
- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.
<br />

At the end, **stack b** must empty empty and all integers must be in **stack a**, sorted in ascending order. <br />
<br />

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` executable in the project root.

### Cleaning

```bash
make clean
make fclean
make re
```

### Execution

Run the program with a list of integers:

```bash
./push_swap 3 2 1
./push_swap "3 2 1"
```

The output is the sequence of operations needed to sort the stack.

### Checker

You can verify the generated instructions with the provided checker:

```bash
./push_swap 3 2 1 | ./checker_linux 3 2 1
```

```bash
ARG='72 773 439 646 '; ./push_swap $ARG | ./checker_linux $ARG
```


# Resources

* [Push Swap Visualizer](https://push-swap42-visualizer.vercel.app)
* [ChatGPT](https://chatgpt.com)
* [Push Swap Tester](https://github.com/gemartin99/Push-Swap-Tester)
* [GeeksforGeeks — Sorting Algorithms](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)


# AI Usage

AI was used to help create this README file and assist with explaining certain algorithms.