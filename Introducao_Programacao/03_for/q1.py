valor = float(input("Digite um valor para ver sua tabuada até 10: "))

for i in range(1, 11):
    resultado = valor * i
    print(f"{valor} x {i} = {resultado}")