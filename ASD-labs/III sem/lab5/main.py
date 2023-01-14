from genetic_algorithm_utils import *
from utils import *


def main():
    iteration = 100_000
    crossover_func = two_point_crossover
    mutation_func = randomly_flip_one_bit
    local_func = add_adjacent_node_by_heuristic

    a, b, c = 100000, 100000, 100000
    population = create_population()
    record = max([i.f for i in population])
    for i in range(iteration):
        if not i % 10_000:
            print(i)

        parents = max_and_rand(population)
        child = crossover_func(*parents)

        if rand.random() <= 0.25:
            mutation_func(child.chromosome)

        if not child.f:
            continue

        local_func(child.chromosome)

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
            population.append(child)
            delete_rand_min(population)

    return a, b, c


if __name__ == '__main__':
    main()
