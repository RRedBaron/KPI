def calculatefactorial(a):
    factorial = 1
    for i in range(1, a+1):
        factorial *= i
    return factorial


def amountofnumbers(k, n):
    return calculatefactorial(n)/calculatefactorial(n-k)


def maxof2(a, b):
    if a >= b: return a
    else: return b


a = maxof2(amountofnumbers(3, 5), maxof2(amountofnumbers(2, 4), amountofnumbers(4, 5)))
if a == amountofnumbers(3, 5):
    print("трьохзназначних чисел, що записуються цифрами 1, 2, 3, 4, 5")
elif a == amountofnumbers(2, 4):
    print("двозначних чисел, що записуються цифрами 2, 4, 6, 8")
else:
    print("чотирьохзначних чисел, що записуються цифрами 1, 3, 7, 8, 9")
