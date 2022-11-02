import math
import os
import psutil
from queue import PriorityQueue
import func_timeout


# Euclidean distance
def h(point_a: tuple, point_b: tuple):
    return math.sqrt((point_a[0] - point_b[0]) ** 2 + (point_a[1] - point_b[1]) ** 2)


def a_star_limited(m):
    return func_timeout.func_timeout(30*60, a_star, args=[m])  # limit time of search to 30


def a_star(m) -> dict:
    start = (m.rows, m.cols)

    g = {cell: float('inf') for cell in m.grid}
    g[start] = 0

    f = {cell: float('inf') for cell in m.grid}
    f[start] = 0 + h(start, (1, 1))

    states = list()

    queue = PriorityQueue()
    queue.put((f[start], h(start, (1, 1)), start))

    a_path = {}


    while not queue.empty():
        if psutil.Process(os.getpid()).memory_info().rss > 1024 ** 3:
            raise MemoryError("Memory limit exceeded")

        current = queue.get()[2]

        if current not in states:
            states.append(current)
        if current == (1, 1):
            print(f'A* {len(states)}')
            break

        for dir in 'ESNW':
            if m.maze_map[current][dir] == 1:
                if dir == 'E':
                    neighbour = (current[0], current[1] + 1)
                elif dir == 'W':
                    neighbour = (current[0], current[1] - 1)
                elif dir == 'N':
                    neighbour = (current[0] - 1, current[1])
                else:
                    neighbour = (current[0] + 1, current[1])

                temp_g_score = g[current] + 1
                temp_f_score = temp_g_score + h(neighbour, start)

                if temp_f_score < f[neighbour]:
                    g[neighbour] = temp_g_score
                    f[neighbour] = temp_f_score
                    queue.put((temp_f_score, h(neighbour, start), neighbour))
                    a_path[neighbour] = current

    forward_path = {}
    cell = (1, 1)
    while cell != start:
        forward_path[a_path[cell]] = cell
        cell = a_path[cell]
    return forward_path
