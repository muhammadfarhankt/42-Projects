import math


def get_player_pos() -> tuple[float, float, float]:
    temp_str = input("Enter new coordinates as floats in format 'x,y,z': ")
    temp_list = temp_str.split(',')
    try:
        x_str, y_str, z_str = temp_list
    except ValueError:
        print("Invalid syntax")
        return get_player_pos()
    coords = []
    for element in temp_list:
        stripped = element.strip()
        try:
            coords.append(float(stripped))
        except ValueError as e:
            print(f"Error on parameter '{stripped}': {e}")
            return get_player_pos()
    return (coords[0], coords[1], coords[2])


def calculate_distance(
        pos1: tuple[float, float, float],
        pos2: tuple[float, float, float]
) -> float:
    return math.sqrt((pos2[0]-pos1[0])**2 +
                     (pos2[1]-pos1[1])**2 + (pos2[2]-pos1[2])**2)


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print("\nGet a first set of coordinates")
    pos1 = get_player_pos()
    distance_center = calculate_distance(pos1, (0, 0, 0))
    print(f"Got a first tuple: ({pos1[0]:.1f}, {pos1[1]:.1f}, {pos1[2]:.1f})")
    print(f"It includes: X={pos1[0]:.1f}, Y={pos1[1]:.1f}, Z={pos1[2]:.1f}")
    print(f"Distance to center: {distance_center:.4f}")
    print("\nGet a second set of coordinates")
    pos2 = get_player_pos()
    distance_coords = calculate_distance(pos1, pos2)
    print(f"Distance between the 2 sets of coordinates: {distance_coords:.4f}")
