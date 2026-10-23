*This project was created as part of the 42 curriculum by mfarhan.*

# Python Module 01 — Code Cultivation

Object-oriented garden systems.

## Description

An introduction to object-oriented Python, progressing from a simple script to plant hierarchies with encapsulated data and per-object statistics.

## Requirements

- Python 3.10 or later.
- No third-party packages are needed to run the exercises.
- `flake8` and `mypy` are optional development tools for linting and type checking.

## Setup

```bash
git clone https://github.com/<name>/<repo>.git
```

The commands below use a Linux, macOS, or WSL shell and `python3`.

## Exercises

| Exercise | File | Purpose |
| --- | --- | --- |
| ex0 | [ft_garden_intro.py](ex0/ft_garden_intro.py) | Display plant information and introduce the main guard. |
| ex1 | [ft_garden_data.py](ex1/ft_garden_data.py) | Represent plants with a reusable Plant class. |
| ex2 | [ft_plant_growth.py](ex2/ft_plant_growth.py) | Simulate seven days of growth and aging. |
| ex3 | [ft_plant_factory.py](ex3/ft_plant_factory.py) | Create and display five plants with different initial values. |
| ex4 | [ft_garden_security.py](ex4/ft_garden_security.py) | Validate height and age through setters and getters. |
| ex5 | [ft_plant_types.py](ex5/ft_plant_types.py) | Specialize plants as Flower, Tree, and Vegetable. |
| ex6 | [ft_garden_analytics.py](ex6/ft_garden_analytics.py) | Add nested statistics, Seed, and static/class methods. |

## Usage

Each exercise is an independent script with its own demonstration. From the repository root:

```bash
python3 ex0/ft_garden_intro.py
python3 ex1/ft_garden_data.py
python3 ex2/ft_plant_growth.py
python3 ex3/ft_plant_factory.py
python3 ex4/ft_garden_security.py
python3 ex5/ft_plant_types.py
python3 ex6/ft_garden_analytics.py
```

The demonstrations use predefined data and do not require interactive input.

## Implementation notes

- Each exercise contains its own class definitions so it can run independently.
- Protected attributes and validation are introduced in exercise 4.
- Exercise 5 demonstrates inheritance, `super()`, method overrides, blooming, shade production, and vegetable nutrition.
- Exercise 6 uses a nested `Statistics` class to count growth, aging, and display calls. Trees also count shade calls.
- `Plant.anonymous()` creates a plant with default information; `Plant.check_year_old()` displays an age comparison.
- `Seed` extends `Flower`, demonstrating an inheritance chain.

## Code quality

Create a virtual environment and install the development tools:

```bash
python3 -m venv .venv
source .venv/bin/activate
python3 -m pip install flake8 mypy
```

From the repository root:

```bash
python3 -m flake8 ex*/*.py
python3 -m mypy --strict --explicit-package-bases ex*/*.py
```

Type checking covers all seven exercise files.