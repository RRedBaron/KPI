from graph_io import graph


class Interior:
    def __init__(self, chromosome):
        self.chromosome = chromosome
        self.f = self.max_clique(chromosome)

    def __lt__(self, other):
        return self.f < other.f

    def __gt__(self, other):
        return self.f > other.f

    def __le__(self, other):
        return self.f <= other.f

    def __ge__(self, other):
        return self.f >= other.f

    def __repr__(self):
        return f"{self.f}"

    def __eq__(self, other):
        return self.chromosome == other.chromosome

    def update(self, chromosome):
        self.chromosome = chromosome
        self.f = self.max_clique(chromosome)

    @staticmethod
    def max_clique(chromosome):
        nodes = []
        for i, gene in enumerate(chromosome):
            if gene:
                nodes.append(i + 1)
        for node in nodes:
            for neighbour in nodes:
                if node == neighbour:
                    continue
                else:
                    if neighbour not in graph[node]:
                        return 0
        return len(nodes)
