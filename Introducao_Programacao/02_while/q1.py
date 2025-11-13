soma = 0
i = 1

while (i <= 500):
    if (i % 2 != 0) and (i % 3 == 0):
        soma += i
    i += 1

print(soma)