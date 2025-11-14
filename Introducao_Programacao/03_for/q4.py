base = base_inicial = float(input("Digite a base: "))
expo = int(input("Digite o expoente (inteiro não negativo): "))

for i in range(1, expo):
    base *= base_inicial

print(f"{base_inicial}^{expo} = {base}")