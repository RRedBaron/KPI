import math
x1 = float(input("Введите х1: "))
y1 = float(input("Введите y1: "))
x2 = float(input("Введите x2: "))
y2 = float(input("Введите y2: "))
x3 = float(input("Введите х3: "))
y3 = float(input("Введите y3: "))
dist1 = math.hypot(x1, y1)
dist2 = math.hypot(x2, y2)
dist3 = math.hypot(x3, y3)
if dist1 <= dist2:
    if dist1 <= dist3:
        print("Т.1 - ближайшая к началу координат")
    else: print("Т.3 - ближайшая к началу координат")
else:
    if dist2 <= dist3:
        print("Т.2 - ближайшая к началу координат")
    else: print("Т.3 - ближайшая к началу координат")
