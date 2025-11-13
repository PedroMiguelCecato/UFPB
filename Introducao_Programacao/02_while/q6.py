produtos = {1:5.5, 2:2.3, 3:3.75, 4:6.8, 5:9.3}
total = 0
codigo = 1

while codigo != 0:
    codigo = int(input("Digite o código do produto (0 para sair): "))

    if codigo in produtos.keys():
        quantidade = int(input("Digite a quantidade desejada: "))
        total += produtos[codigo] * quantidade
    elif codigo != 0:
        print("Código inválido. Tente novamente.")
    else:
        break

print(f"Total a pagar: R$ {total:.2f}")