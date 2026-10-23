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
            print(f"{self.name}: Height updated: {new_height}")

    def set_age(self, new_age: int) -> None:
        if new_age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age_in_days = new_age
            print(f"{self.name}: Age updated: {new_age}")


class Flower(Plant):
    def __init__(
            self, name: str, _height: float, _age_in_days: int,
            color: str) -> None:
        super().__init__(name, _height, _age_in_days)
        self.color = color
        self.is_blooming = False

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")
        if self.is_blooming:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")

    def bloom(self) -> None:
        print(f"[asking the {self.name.lower()} to bloom]")
        self.is_blooming = True


class Tree(Plant):
    def __init__(
            self, name: str, _height: float, _age_in_days: int,
            trunk_diameter: float) -> None:
        super().__init__(name, _height, _age_in_days)
        self.trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.trunk_diameter:.1f} cm")

    def produce_shade(self) -> None:
        print(f"[asking the {self.name.lower()} to produce shade]")
        print(f"Tree {self.name} now produces a shade of {self._height:.1f} \
        long and {self.trunk_diameter:.1f}cm wide.")


class Vegetable(Plant):
    def __init__(
            self, name: str, _height: float, _age_in_days: int,
            harvest_season: str) -> None:
        super().__init__(name, _height, _age_in_days)
        self.harvest_season = harvest_season.capitalize()
        self.nutritional_value = 0

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self.harvest_season}")
        print(f"Nutritional value: {self.nutritional_value}")

    def grow(self) -> None:
        super().grow()
        super().age()
        self.nutritional_value += 1


def simulate_week(plant: Plant) -> None:
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        plant.grow()
        plant.show()
    print(f"Growth this week: {plant.growth}")


def main() -> None:
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    rose.bloom()
    rose.show()
    print()
    print("=== Tree")
    oak = Tree("Oak", 200, 365, 5)
    oak.show()
    oak.produce_shade()
    print()
    print("=== Vegetable")
    tomato = Vegetable("tomato", 5, 10, "april")
    tomato.show()
    days = 20
    print(f"[make {tomato.name} grow and age for {days} days]")
    while days > 0:
        days -= 1
        tomato.grow()
    tomato.show()
    print()


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    main()
    print("=== End of Program ===")
