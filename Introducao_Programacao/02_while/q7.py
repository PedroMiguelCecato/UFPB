n = float(input("Insira um numero positivo para calcular a raiz quadrada: "))
b = 2
p = (b + n/b)/2

while abs(p - b) >= 0.00001:
    b = p
    p = (b + n/b) / 2

print(f"A raiz quadrada de {n} é aproximadamente {p}")