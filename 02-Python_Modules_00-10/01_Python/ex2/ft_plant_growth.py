class Plant():
    def __init__(self, name: str, height: float, age_in_days: int) -> None:
        self.name = name.capitalize()
        self.height = height
        self.age_in_days = age_in_days
        self.grow_speed = self.get_grow_speed()
        self.growth: float = 0

    def show(self) -> None:
        print(
            f"{self.name}: {self.height:.1f}cm, "
            f"{self.age_in_days} days old"
        )

    def get_grow_speed(self) -> float:
        grow_speed: float = 0.8
        if self.age_in_days > 0 and self.height > 0:
            grow_speed = round(self.height / self.age_in_days, 1)
        return grow_speed

    def grow(self) -> None:
        self.height = round(self.height + self.grow_speed, 1)
        self.growth = round(self.growth + self.grow_speed, 1)

    def age(self) -> None:
        self.age_in_days += 1


def simulate_week(plant: Plant) -> None:
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        plant.grow()
        plant.age()
        plant.show()
    print(f"Growth this week: {plant.growth}cm")


def main() -> None:
    rose = Plant("Rose", 25, 30)
    rose.show()
    simulate_week(rose)


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    main()
