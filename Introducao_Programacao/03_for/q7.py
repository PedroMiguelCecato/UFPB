n = int(input("Numero a verificar se ah primo: "))

if n < 2:
    print(f"{n} nao eh primo")
else:
    cont = 2
    for i in range(2, n):
        if n % i == 0:
            cont += 1
        
    if cont > 2:
        print(f"{n} nao eh primo")
    else:
        print(f"{n} eh primo")