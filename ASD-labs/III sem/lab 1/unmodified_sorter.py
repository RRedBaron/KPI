import time
import os
from random import randint
from file_manager import FileReader


class NaturalMergeSort:
    def __init__(self, filename_a: str, filename_b: str, filename_c: str):
        self.filename_a = filename_a
        self.filename_b = filename_b
        self.filename_c = filename_c
        self.clear(filename_b)
        self.clear(filename_c)

    def create_random_file(self, n: int, max_n: int):
        start_time = time.time()
        with open(self.filename_a, "wb") as a:
            for i in range(n):
                a.write(randint(1, max_n).to_bytes(4, byteorder="big"))
        print(f"File generating time: {time.time() - start_time}sec")

    def natural_sort(self):
        start_time = time.time()
        while not self.is_sorted():
            self.find_sequences()
            self.merge()

        print(f"Sorting time: {time.time() - start_time} sec")

    def __str__(self):
        text = "File A:" + self.read(self.filename_a) + '\n'
        if os.path.getsize(filename=self.filename_b):
            text += "File B:" + self.read(self.filename_b) + '\n'
        if os.path.getsize(filename=self.filename_c):
            text += "File C:" + self.read(self.filename_c)
        return text

    def find_sequences(self):
        a = FileReader(self.filename_a)
        b = open(self.filename_b, "wb")
        c = open(self.filename_c, "wb")

        i = True
        while a.current:
            b.write(a.current) if i else c.write(a.current)
            if a.current > a.next:
                i = not i
            next(a)

        a.close(), b.close(), c.close()

    def merge(self):
        a = open(self.filename_a, "wb")
        b = FileReader(self.filename_b)
        c = FileReader(self.filename_c)
        while b.current and c.current:
            if b.current <= b.next and c.current <= c.next:
                if b.current <= c.current:
                    a.write(next(b))
                else:
                    a.write(next(c))
            elif b.current >= b.next and c.current <= c.next:
                while c.current <= c.next:
                    if b.current <= c.current:
                        a.write(next(b))
                        while c.current <= c.next:
                            a.write(next(c))
                        a.write(next(c))
                        break
                    else:
                        a.write(next(c))
            elif c.current >= c.next and b.current <= b.next:
                while b.current <= b.next:
                    if c.current <= b.current:
                        a.write(next(c))
                        while b.current <= b.next:
                            a.write(next(b))
                        a.write(next(b))
                        break
                    else:
                        a.write(next(b))
            else:
                if c.current <= b.current:
                    a.write(c.current)
                    a.write(b.current)
                else:
                    a.write(b.current)
                    a.write(c.current)
                next(c), next(b)

        if not b.current and c.current:
            while c.current:
                a.write(next(c))
        elif not c.current and b.current:
            while b.current:
                a.write(next(b))

        a.close(), b.close(), c.close()

    def is_sorted(self) -> bool:
        a = FileReader(self.filename_a)
        while a.next:
            if a.current > a.next:
                a.close()
                return False
            next(a)
        a.close()
        return True

    @staticmethod
    def read(path: str) -> str:
        s = str()
        file = FileReader(path)

        for i in range(60):
            if not file.current:
                break
            s += str(int.from_bytes(file.current, byteorder="big")) + " "
            next(file)

        file.close()
        return s

    @staticmethod
    def clear(filename: str):
        open(filename, "wb").close()
