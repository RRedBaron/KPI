import random as rand
from interior import Interior
from graph_io import graph


#
#   Mutation
#
def randomly_flip_one_bit(chromosome):
    i = rand.randint(0, len(chromosome) - 1)
    chromosome = list(chromosome)
    chromosome[i] = 0 if chromosome[i] else 1
    return chromosome


def randomly_flip_interval_bits(chromosome):
    point1 = rand.randint(0, len(chromosome) - 2)
    point2 = rand.randint(point1, len(chromosome))

    for i in range(point1, point2):
        chromosome[i] = 0 if chromosome[i] else 1
    return chromosome


#
#   Local
#
def get_nodes_from_chromosome(chromosome):
    nodes = []
    for i, gene in enumerate(chromosome):
        if gene:
            nodes.append(i + 1)
    return nodes


def add_random_adjacent_node(chromosome):
    nodes = get_nodes_from_chromosome(chromosome)
    rand.shuffle(nodes)
    for node in nodes:
        neighbours = graph[node]
        rand.shuffle(neighbours)
        for neighbour in neighbours:
            if neighbour in nodes:
                continue
            # if nodes in clique are all in neighbours of the neighbour of the node
            if set(nodes) <= set(graph[neighbour]):
                chromosome = list(chromosome)
                chromosome[neighbour - 1] = 1
                return chromosome
    return None


def add_adjacent_node_by_heuristic(chromosome):
    nodes = get_nodes_from_chromosome(chromosome)
    neighbours = []
    for node in nodes:
        neighbours += graph[node]
    neighbours = list(set(neighbours))
    rand.shuffle(neighbours)
    for neighbour in sorted(neighbours, key=lambda x: len(graph[x])):
        if neighbour in nodes:
            continue
        # if nodes in clique are all in neighbours of the neighbour of the node
        if set(nodes) <= set(graph[neighbour]):
            chromosome = list(chromosome)
            chromosome[neighbour - 1] = 1
            return chromosome
    return None


#
#   Crossover
#
def even_crossover(parent1, parent2):
    chromosome = []
    for x, y in zip(parent1.chromosome, parent2.chromosome):
        chromosome += rand.choice([x, y]),
    return Interior(chromosome)


def one_point_crossover(parent1, parent2):
    point = rand.randint(0, len(parent1.chromosome) - 1)
    offspring = Interior(parent1.chromosome[:point + 1] + parent2.chromosome[point + 1:])
    return offspring


def two_point_crossover(parent1, parent2):
    point1 = rand.randint(0, len(parent1.chromosome) // 2)
    point2 = rand.randint(point1, len(parent2.chromosome) - 1)
    offspring = Interior(
        parent1.chromosome[:point1 + 1] + parent2.chromosome[point1 + 1:point2 + 1] + parent1.chromosome[point2 + 1:])
    return offspring
