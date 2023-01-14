from queue import PriorityQueue
from bee_colony import BeeColony
from constant import *
from utils import *


def print_best_scout(scouts, iteration):
    if not iteration % 20:
        best = scouts.get()
        print(f"Iter: [{iteration}], best chromatic number: [{best.f}]")
        scouts.put(best)


def print_best_coloring(scouts):
    best = scouts.get()
    coloring = {k: v for k, v in sorted(best.coloring.items(), key=lambda item: item[0])}
    print(f"Best chromatic number: [{best.f}], graph coloring: {coloring}")


def main():
    graph = generate_random_graph()

    scouts = PriorityQueue()
    BeeColony.initialize_scouts(graph, scouts, INITIAL_SCOUTS_COUNT)

    for i in range(1000):
        if not i % 20:
            print_best_scout(scouts, i)

        best_scouts = BeeColony.select_best_scouts(scouts)
        random_scouts = scouts.queue

        # Create new scouts queue
        scouts = PriorityQueue()

        # Local search for best foragers
        BeeColony.perform_local_search(graph, scouts, best_scouts, BEST_FORAGERS_COUNT)

        # Local search for random foragers
        BeeColony.perform_local_search(graph, scouts, random_scouts, RANDOM_FORAGERS_COUNT)

        # Find best scouts
        best_scouts = BeeColony.select_best_scouts(scouts)

        # Create new scouts queue
        scouts = PriorityQueue()

        # Generate random scouts
        BeeColony.initialize_scouts(graph, scouts, RANDOM_SCOUTS_COUNT)

        # Add best scouts to the new scouts queue
        BeeColony.add_best_scouts_to_queue(scouts, best_scouts)

    print_best_coloring(scouts)


if __name__ == "__main__":
    main()
