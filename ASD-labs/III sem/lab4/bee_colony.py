from utils import *
from constant import *


class BeeColony:
    def __init__(self, coloring, f):
        self.coloring = coloring
        self.f = f

    def __lt__(self, other):
        return self.f.__lt__(other.f)

    @staticmethod
    def initialize_scouts(colony_graph, colony_scouts, n):
        while colony_scouts.qsize() < n:
            colony_scout = BeeColony(*initial_coloring(colony_graph))
            if colony_scout not in colony_scouts.queue:
                colony_scouts.put(colony_scout)

    @staticmethod
    def select_best_scouts(colony_scouts):
        best = []
        for i in range(BEST_SCOUTS_COUNT):
            best.append(colony_scouts.get())
        return best

    @staticmethod
    def _get_queue(colony_graph, local_foragers_n):
        queue = []
        for node, neighbours in sorted(list(colony_graph.items()), key=lambda x: len(x[1]), reverse=True):
            if len(queue) >= local_foragers_n:
                break
            for neighbour in neighbours:
                queue.append((node, neighbour))
        return queue

    @staticmethod
    def _get_results(colony_scout, queue, colony_graph):
        results = []
        for node, neighbour in queue:
            new_coloring = dict(colony_scout.coloring)
            new_coloring[neighbour], new_coloring[node] = new_coloring[node], new_coloring[neighbour]

            if are_colors_in_neighbours(new_coloring[node], colony_graph[node], new_coloring) or \
                    are_colors_in_neighbours(new_coloring[neighbour], colony_graph[neighbour], new_coloring):
                continue
            else:
                for color in range(1, colony_scout.f + 1):
                    if not are_colors_in_neighbours(color, colony_graph[neighbour], new_coloring):
                        new_coloring[neighbour] = color
                        results.append(BeeColony(new_coloring, len(set(new_coloring.values()))))
        return results

    @staticmethod
    def discover_neighbours(colony_scout, colony_graph, local_foragers_n):
        queue = BeeColony._get_queue(colony_graph, local_foragers_n)
        results = BeeColony._get_results(colony_scout, queue, colony_graph)
        return min(results, key=lambda x: x.f) if results else colony_scout

    @staticmethod
    def perform_local_search(colony_graph, new_colony_scouts, colony_scouts, n):
        for colony_scout in colony_scouts:
            colony_scout = BeeColony.discover_neighbours(colony_scout, colony_graph, n)
            new_colony_scouts.put(colony_scout)

    @staticmethod
    def add_best_scouts_to_queue(colony_scouts, best_colony_scouts):
        for colony_scout in best_colony_scouts:
            colony_scouts.put(colony_scout)
