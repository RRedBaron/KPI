from graph_io import num_nodes
from interior import Interior
import random as rand


def create_population():
    population = []
    for i in range(num_nodes):
        chromosome = [0 for _ in range(num_nodes)]
        chromosome[i] = 1
        population.append(Interior(chromosome))
    return population


def max_and_rand(population):
    a = max(population)
    b = rand.choice(population)
    while a == b:
        b = rand.choice(population)
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
