import random


class Player:

    def __init__(self, name: str, achievements: set[str]) -> None:
        self.name = name.capitalize()
        self.achievements = achievements


def gen_player_achievements(total: list[str]) -> set[str]:
    available = total.copy()
    achievements: set[str] = set()
    amount = random.randint(5, 14)
    while len(achievements) < amount:
        new_el = random.choice(available)
        available.remove(new_el)
        achievements.add(new_el)
    return achievements


def print_achievement_stats(players: list[Player], total: list[str]) -> None:
    all_ach: set[str] = set()
    comm_ach = set(total)
    for x in players:
        print(f"Player {x.name}: {x.achievements}")
        all_ach = all_ach.union(x.achievements)
        comm_ach = comm_ach.intersection(x.achievements)
    print(f"\nAll distinct achievements: {all_ach}")
    print(f"\nCommon achievements: {comm_ach}\n")
    for x in players:
        unique = x.achievements
        for y in players:
            if x != y:
                unique = unique.difference(y.achievements)
        print(f"Only {x.name} has: {unique}")
    print("\n")
    for x in players:
        print(f"{x.name} is missing: {set(total).difference(x.achievements)}")


if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")
    total = [
        "Crafting Genius",
        "Strategist",
        "World Savior",
        "Speed Runner",
        "Survivor",
        "Master Explorer",
        "Treasure Hunter",
        "Unstoppable",
        "First Steps",
        "Collector Supreme",
        "Untouchable",
        "Sharp Mind",
        "Boss Slayer",
        "Hidden Path Finder",
    ]
    alice = Player("Alice", gen_player_achievements(total))
    bob = Player("Bob", gen_player_achievements(total))
    charlie = Player("Charlie", gen_player_achievements(total))
    dylan = Player("Dylan", gen_player_achievements(total))

    players = [alice, bob, charlie, dylan]
    print_achievement_stats(players, total)
