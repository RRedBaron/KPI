import random as rand

import crossover
import local
import mutation
from graph_module import nodes_n
from individual import Individual


def create_population(population):
    for i in range(nodes_n):
        chromosome = [0 for _ in range(nodes_n)]
        chromosome[i] = 1
        population.append(Individual(chromosome))
    return 1


def max_and_rand(population):
    a = max(population)
    b = rand.choice(population)
    while a == b:
        b = rand.choice((population))

    return a, b


def delete_rand_min(population):
    minimum = []
    m = population[0].f
    for ind in population:
        if ind.f < m:
            minimum.clear()
            m = ind.f
            minimum.append(ind)
        elif ind.f == m:
            minimum.append(ind)
    population.remove(rand.choice(minimum))


def run(crossover_func, mutation_func, local_func):
    a, b, c = 100000, 100000, 100000
    population = []
    record = create_population(population)

    for i in range(100_000):
        if not i % 10_000:
            print(i)

        parents = max_and_rand(population)
        child = crossover_func(*parents)

        if rand.random() <= 0.25:
            mutation_func(child)

        if not child.f:
            continue

        local_func(child)

        if child.f > record:
            record = child.f
            print(i, record)
            if record == 15:
                a = i
            if record == 16:
                b = i
            if record >= 17:
                c = i
                break

        if child not in population:
            population += child,
            delete_rand_min(population)

    return a, b, c


if __name__ == '__main__':
    run(crossover.two_point, mutation.rand_change_one, local.add_adj_node_heuristic)
