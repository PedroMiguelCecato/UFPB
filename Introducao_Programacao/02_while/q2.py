valor = float(input("Valor (digite -1 para sair): "))
valores = [valor]

while valor != -1:
    valor = float(input("Valor (digite -1 para sair): "))
    if valor != -1:
        valores.append(valor)

print("Valor mais baixo registrado:", min(valores))
print("Valor mais alto registrado:", max(valores))