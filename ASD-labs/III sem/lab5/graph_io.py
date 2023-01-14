import random as rand
from itertools import combinations


def generate_random_graph(num_nodes, probability, min_degree, max_degree):
    nodes = list(range(1, num_nodes + 1))
    adjacency_list = {node: [] for node in nodes}
    possible_edges = combinations(nodes, 2)

    # Only add edges that meet the criteria
    for u, v in possible_edges:
        if rand.random() < probability and len(adjacency_list[v]) < max_degree and len(adjacency_list[u]) < max_degree:
            adjacency_list[u].append(v)
            adjacency_list[v].append(u)

    # add nodes that meet the minimum degree criteria
    for node, neighbours in adjacency_list.items():
        while len(neighbours) < min_degree:
            potential_neighbor = rand.choice(nodes)
            if potential_neighbor not in neighbours:
                neighbours.append(potential_neighbor)
                adjacency_list[potential_neighbor].append(node)
    return adjacency_list


def dump_graph_to_file(graph, file_name):
    with open(file_name, "w") as f:
        f.write(str(graph))
    num_nodes = len(graph)
    return graph, num_nodes


def load_graph_from_file(file_name):
    with open(file_name, "r") as f:
        graph = eval(f.read())
    num_nodes = len(graph)
    return graph, num_nodes


graph, num_nodes = dump_graph_to_file(generate_random_graph(300, 0.90, 2, 30), "graph.txt")
