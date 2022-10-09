class FileReader:
    def __init__(self, path: str):
        self.path = path
        self.f = open(path, "rb")
        self.current = self.f.read(4)
        self.next = self.f.read(4)

    def close(self):
        self.f.close()

    def __iter__(self):
        return self

    def __next__(self):
        tmp = self.current
        self.current = self.next
        self.next = self.f.read(4)
        return tmp