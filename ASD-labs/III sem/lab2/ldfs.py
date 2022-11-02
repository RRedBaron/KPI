import os
import func_timeout
import psutil


def LDFS_limited(m, limit):
    return func_timeout.func_timeout(30 * 60, LDFS, args=[m, limit])  # limit time of search to 30


def LDFS(m, limit):
    it = 0
    max_stack = 0
    stops = 0

    start = (m.rows, m.cols)
    stack = [(start, [start])]
    states = []
    while stack:
        if psutil.Process(os.getpid()).memory_info().rss > 1024 ** 3:  # limit memory use to 1 Gb
            raise MemoryError("1 Gb memory exceeded")
        it += 1
        if len(stack) > max_stack:
            max_stack = len(stack)

        curr, path = stack.pop()
        if curr not in states:
            states.append(curr)
        if len(path) - 1 == limit:
            stops += 1
            continue
        if curr == (1, 1):
            st = len(states)
            print(f'LDFS {st} \nNumber of stops: {stops}')
            return path
        stack += expand(m, curr, path)
    print(f'LDFS\n')
    return []


def expand(m, curr, path):
    directions = {"E": lambda x: (x[0], x[1] + 1),
                  "W": lambda x: (x[0], x[1] - 1),
                  "N": lambda x: (x[0] - 1, x[1]),
                  "S": lambda x: (x[0] + 1, x[1])}
    neighbours = []
    for d in "ENSW":
        if m.maze_map[curr][d]:
            neighbour = directions[d](curr)
            if neighbour not in path:
                neighbours += (neighbour, path + [neighbour]),
    return neighbours
