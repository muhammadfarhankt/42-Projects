import sys


def get_inventory(args: list[str]) -> dict[str, int]:
    inventory = {}
    for item in args[1:]:
        pair = item.split(':')
        if len(pair) != 2:
            print(f"Error - invalid parameter '{pair[0]}'")
            continue
        name = pair[0].strip()
        quantity = pair[1].strip()
        if name not in inventory:
            try:
                inventory[name] = int(quantity)
            except ValueError as e:
                print(f"Quantity error for '{name}': {e}")
        else:
            print(f"Redundant item '{name}' - discarding")
    return inventory


def print_inventory_stats(inventory: dict[str, int]) -> None:
    item_list = list(inventory.keys())
    print(f"Item list: {item_list}")

    total_quant = sum(inventory.values())
    print(f"Total quantity of the {len(inventory)} items: {total_quant}")

    for item in inventory:
        if total_quant == 0:
            percentage = 0.0
        else:
            percentage = inventory[item] / total_quant * 100
        print(f"Item {item} represents {percentage:.1f}%")

    items = list(inventory.keys())
    most = items[0]
    least = items[0]

    for item in items:
        if inventory[item] > inventory[most]:
            most = item
        if inventory[item] < inventory[least]:
            least = item

    print(f"Item most abundant: {most}",
          f"with quantity {inventory[most]}")
    print(f"Item least abundant: {least}",
          f"with quantity {inventory[least]}")


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory = get_inventory(sys.argv)
    if len(inventory) < 1:
        print("No arguments provided!")
    else:
        print(f"Got inventory: {inventory}")
        print_inventory_stats(inventory)
        inventory["magic_item"] = 1
        print(f"Updated inventory: {inventory}")
