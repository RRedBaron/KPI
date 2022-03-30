a, b = list(map(int, input('Enter the a, b: ').split()))
print(1) #1 - делитель любого целого числа
fib1 = fib2 = 1
last = 0
while fib2 < b:
    fib1, fib2 = fib2, fib1 + fib2
    for i in range(a, b + 1):
        if i % fib2 == 0:
            if last != fib2:
                print(fib2)
                last = fib2
