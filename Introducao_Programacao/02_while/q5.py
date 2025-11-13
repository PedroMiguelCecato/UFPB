divida = float(input("Digite o valor da dívida: R$ "))
juros_mensal = float(input("Digite a taxa de juros mensal (em %): ")) / 100
pagamento_mensal = float(input("Digite o valor do pagamento mensal: R$ "))
meses = 0
pagamento_total = 0

while divida > 0:
    divida += divida * juros_mensal

    if divida < pagamento_mensal:
        pagamento_mensal = divida

    pagamento_total += pagamento_mensal    
    divida -= pagamento_mensal
    meses += 1

print(f"Total pago: R$ {pagamento_total:.2f}")
print(f"Meses para quitar a dívida: {meses} meses")