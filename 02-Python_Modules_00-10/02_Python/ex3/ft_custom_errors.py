class GardenError(Exception):
    def __init__(self, message: str = "Unknown plant error") -> None:
        self.message = message
        super().__init__(self.message)


class PlantError(GardenError):
    def __init__(self, *message: str) -> None:
        super().__init__(*message)


class WaterError(GardenError):
    def __init__(self, *message: str) -> None:
        super().__init__(*message)


def test_plant_error(plant_data: int) -> None:
    if plant_data < 10:
        raise PlantError()
    else:
        print("Plant is fine")


def test_water_error(water_data: int) -> None:
    if water_data < 10:
        raise WaterError("Not enough water in the tank!")
    else:
        print("Water is fine")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===", end="\n\n")
    print("Testing PlantError...")
    try:
        test_plant_error(1)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    print()

    print("Testing WaterError...")
    try:
        test_water_error(1)
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    print()

    print("Testing catching all garden errors...")
    try:
        test_plant_error(1)
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        test_water_error(1)
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    print()

    print("All custom error types work correctly!")
