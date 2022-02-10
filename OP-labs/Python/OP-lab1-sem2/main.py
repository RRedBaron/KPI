from functions import *


CreateTextFile("text.txt")
CreateTextFile("text2.txt")
rows = CreateTextFileWithSimilarRows("text3.txt")
print(f"Количество одинаковых строк в первом и втором файлах: {rows}\n")
PrintFile("text.txt")
PrintFile("text2.txt")
PrintFile("text3.txt")