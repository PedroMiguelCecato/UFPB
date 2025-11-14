n = int(input("Numero de iteracoes de Fibonacci: "))
a, b = 0, 1

if n < 1:
    n = 1

for _ in range(n):
    print(a)
    a, b = b, a + b