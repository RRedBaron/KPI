class Bee:
    def __init__(self, coloring, f):
        self.coloring = coloring
        self.f = f

    def __lt__(self, other):
        return self.f.__lt__(other.f)

    def __repr__(self):
        return f"\nFunction: {self.f} Coloring: {self.coloring}"