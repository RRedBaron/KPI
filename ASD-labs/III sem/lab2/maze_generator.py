from pyamaze import maze


def create_maze(height: int, width: int) -> maze:
    my_maze = maze(height, width)
    my_maze.CreateMaze(loopPercent=0)
    return my_maze
