import random


if __name__ == "__main__":
    print("=== Game Data Alchemist ===\n")
    players = [
        "Alice",
        "bob",
        "Charlie",
        "dylan",
        "Emma",
        "Gregory",
        "john",
        "kevin",
        "Liam"
    ]
    print(f"Initial list of players: {players}")
    players_cap = [x.capitalize() for x in players]
    print(f"New list with all names capitalized: {players_cap}")
    players_cap_only = [x for x in players if x == x.capitalize()]
    print(f"New list of capitalized names only: {players_cap_only}")
    scores = {x: random.randint(0, 999) for x in players_cap}
    print(f"\nScore dict: {scores}")
    average = sum(scores.values()) / len(scores)
    print(f"Score average is {average:.2f}")
    high_scores = {x: scores[x] for x in scores if scores[x] > average}
    print(f"High scores: {high_scores}")
