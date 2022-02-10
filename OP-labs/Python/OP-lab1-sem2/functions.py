def CreateTextFile(filename):
    with open(filename, "w") as inf:
        while(True):
            str = input()
            if str == "":
                return
            else:
                inf.write(str+'\n')


def CreateTextFileWithSimilarRows(filename):
    rows = 0
    with open(filename, "w") as ouf:
        with open("text.txt", "r") as inf1:
            text1 = inf1.readlines()
            with open("text2.txt", "r") as inf2:
                text2 = inf2.readlines()
                for i in text2:
                    if i in text1:
                        ouf.write(i)
                        rows += 1
    return rows


def PrintFile(filename):
    with open(filename) as file:
        print(f"{filename}:\n\n{''.join(file.readlines())}")
