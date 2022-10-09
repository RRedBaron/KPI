from unmodified_sorter import NaturalMergeSort

example = NaturalMergeSort("a.bin", "b.bin", "c.bin")
example.create_random_file(1024**2*3, 1000000)
print(example)
example.natural_sort()
print(example)
