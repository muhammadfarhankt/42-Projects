import typing
import random


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    players = [
        "alice",
        "bob",
        "charlie",
        "dylan",
    ]
    actions = [
        "move",
        "grab",
        "use",
        "swim",
        "run",
        "climb",
        "release",
        "eat",
        "sleep",
    ]
    while True:
        player = random.choice(players)
        action = random.choice(actions)
        yield (player, action)


def consume_event(
        event_list: list[tuple[str, str]]
) -> typing.Generator[tuple[str, str], None, None]:
    while len(event_list) > 0:
        consumed = random.choice(event_list)
        event_list.remove(consumed)
        yield consumed


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    event_generator = gen_event()
    for i in range(1000):
        name, action = next(event_generator)
        print(f"Event {i}: Player {name} did action {action}")
    event_list = []
    for i in range(10):
        current = next(event_generator)
        event_list.append(current)
    print(f"Built list of 10 events: {event_list}")
    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {event_list}")
