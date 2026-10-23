class Plant():
    def __init__(self, name: str, _height: float, _age_in_days: int) -> None:
        self.name = name.capitalize()
        self._height = _height
        self._age_in_days = _age_in_days
        self.grow_speed = self.get_grow_speed()
        self.growth: float = 0

    def show(self) -> None:
        print(
            f"{self.name}: {self._height:.1f}cm, "
            f"{self._age_in_days} days old"
        )

    def get_grow_speed(self) -> float:
        grow_speed: float = 0.8
        if self._age_in_days > 0 and self._height > 0:
            grow_speed = round(self._height / self._age_in_days, 1)
        return grow_speed

    def grow(self) -> None:
        self._height = round(self._height + self.grow_speed, 1)
        self.growth = round(self.growth + self.grow_speed, 1)

    def age(self) -> None:
        self._age_in_days += 1

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age_in_days

    def set_height(self, new_height: float) -> None:
        if new_height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = new_height
            print(f"{self.name}: Height updated: {new_height:.1f}cm")

    def set_age(self, new_age: int) -> None:
        if new_age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age_in_days = new_age
            print(f"{self.name}: Age updated: {new_age} days")


def simulate_week(plant: Plant) -> None:
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        plant.grow()
        plant.show()
    print(f"Growth this week: {plant.growth}")


def main() -> None:
    rose = Plant("Rose", 15.0, 10)
    print("Plant created: ", end="")
    rose.show()
    print()
    rose.set_height(25.0)
    rose.set_age(30)
    print()
    rose.set_height(-5)
    rose.set_age(-5)
    print()
    print("Current state: ", end="")
    rose.show()


if __name__ == "__main__":
    print("=== Garden Security System ===")
    main()
