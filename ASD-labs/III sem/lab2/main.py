from pyamaze import agent
from a_star import a_star_limited
from ldfs import LDFS_limited
from maze_generator import create_maze


def main():
    maze = create_maze(20, 20)

    # =====a_star_demo=====

    a_star_example = a_star_limited(maze)
    a = agent(maze, shape='arrow', filled=False, footprints=True, color='green')
    maze.tracePath({a: a_star_example}, delay=0)

    # =====ldfs_demo=====

    ldfs_example = LDFS_limited(maze, 1)
    if not ldfs_example:
        print('No path has been found on given depth')
    a = agent(maze, shape='square', filled=False, footprints=True, color='yellow')
    maze.tracePath({a: ldfs_example}, delay=0)

    maze.run()


if __name__ == '__main__':
    main()
