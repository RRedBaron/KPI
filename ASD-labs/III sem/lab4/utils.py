import networkx as nx
from random import shuffle


def generate_random_graph():
    graph_generator = nx.watts_strogatz_graph(300, 30, 1)
    graph = {}
    for edge in graph_generator.edges:
        u, v = edge
        u += 1
        v += 1
        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []
        graph[u].append(v)
        graph[v].append(u)
    return graph


def are_colors_in_neighbours(color, neighbours, coloring):
    if neighbours:
        for neighbour in neighbours:
            if neighbour in coloring and coloring[neighbour] == color:
                return True
    return False


def initial_coloring(graph):
    coloring = {node: 0 for node in graph.keys()}
    graph = list(graph.items())
    shuffle(graph)
    max_color = 0
    for node, neighbours in graph:
        for color in range(1, 10000):
            if not are_colors_in_neighbours(color, neighbours, coloring):
                coloring[node] = color
                if color > max_color:
                    max_color += 1
                break
    return coloring, max_color
