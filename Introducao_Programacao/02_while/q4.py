n1 = float(input("Digite o primeiro numero: "))
n2 = float(input("Digite o segundo numero: "))
cont = 0

if n1 >= n2:
    while n1 >= n2:
        cont += 1
        n1 -+ n2
    
    print(f"Divisão: {cont}\nResto: {n1}")
else:
    while n2 >= n1:
        cont += 1
        n2 -+ n1
    
    print(f"Divisão: {cont}\nResto: {n2}")