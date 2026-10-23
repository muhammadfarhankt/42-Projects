class Plant:
    def __init__(self, name: str, _height: float, _age_in_days: int) -> None:
        self.name = name.capitalize()
        self._height = _height
        self._age_in_days = _age_in_days
        self.grow_speed = self.get_grow_speed()
        self.growth: float = 0
        self.stats: Plant.Stats = self.Stats()

    def show(self) -> None:
        print(f"{self.name}: {self._height:.1f}cm"
              f", {self._age_in_days} days old")
        self.stats.show_call_count += 1

    def get_grow_speed(self) -> float:
        grow_speed: float = 0.8
        if self._age_in_days > 0 and self._height > 0:
            grow_speed = round(self._height / self._age_in_days, 1)
        return grow_speed

    def grow(self) -> None:
        self._height = round(self._height + self.grow_speed, 1)
        self.growth = round(self.growth + self.grow_speed, 1)
        self.stats.grow_call_count += 1

    def age(self) -> None:
        self._age_in_days += 1
        self.stats.age_call_count += 1

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

    @staticmethod
    def verify_age(days: int) -> bool:
        return days > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0, 0)

    class Stats:
        def __init__(self) -> None:
            self.grow_call_count = 0
            self.age_call_count = 0
            self.show_call_count = 0

        def show(self) -> None:
            print(
                f"Stats: {self.grow_call_count} grow, "
                f"{self.age_call_count} age, "
                f"{self.show_call_count} show"
            )


class Flower(Plant):
    def __init__(
            self,
            name: str,
            _height: float,
            _age_in_days: int,
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


class Seed(Flower):
    def __init__(
        self,
        name: str,
        _height: float,
        _age_in_days: int,
        color: str,
        number_of_seeds: int,
    ) -> None:
        super().__init__(name, _height, _age_in_days, color)
        self.number_of_seeds = number_of_seeds
        self.current_number_of_seeds: int = 0

    def bloom(self) -> None:
        super().bloom()
        self.current_number_of_seeds = self.number_of_seeds

    def show(self) -> None:
        super().show()
        print(f"Seeds: {self.current_number_of_seeds}")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        _height: float,
        _age_in_days: int,
        trunk_diameter: float
    ) -> None:
        super().__init__(name, _height, _age_in_days)
        self.trunk_diameter = trunk_diameter
        self.stats: Tree.TreeStats = self.TreeStats()

    class TreeStats(Plant.Stats):
        def __init__(self) -> None:
            super().__init__()
            self.shade_call_count = 0

        def show(self) -> None:
            super().show()
            print(f" {self.shade_call_count} shade")

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.trunk_diameter:.1f} cm")

    def produce_shade(self) -> None:
        print(f"[asking the {self.name.lower()} to produce shade]")
        print(
            f"Tree {self.name} now produces a shade of "
            f"{self._height:.1f}cm long and "
            f"{self.trunk_diameter:.1f}cm wide."
        )
        self.stats.shade_call_count += 1


class Vegetable(Plant):
    def __init__(
        self, name: str, _height: float, _age_in_days: int, harvest_season: str
    ) -> None:
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


def show_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant.stats.show()


def main() -> None:
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.verify_age(30)}")
    print(f"Is 400 days more than a year? -> {Plant.verify_age(400)}")
    print()
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    show_statistics(rose)

    print("[asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    show_statistics(rose)
    print()
    print("=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    show_statistics(oak)
    oak.produce_shade()
    show_statistics(oak)
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
    print("=== Seed")
    sunflower = Seed("Sunflower", 80, 45, "yellow", 42)
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.age()
    sunflower.bloom()
    sunflower.show()
    show_statistics(sunflower)
    print()
    print("=== Anonymous")
    new_plant = Plant.create_anonymous()
    new_plant.show()
    show_statistics(new_plant)
    print()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    main()
