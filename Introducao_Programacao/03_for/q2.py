deposito_inicial = float(input("Digite o valor do depósito inicial: "))
taxa_juros = float(input("Digite a taxa de juros mensal (em %): ")) / 100

for mes in range(1, 25):
    deposito = deposito_inicial * (1 + taxa_juros)
    ganho = deposito - deposito_inicial
    deposito_inicial = deposito

    print(f"Mês {mes}: Depósito = R$ {deposito:.2f}, Ganho = R$ {ganho:.2f}")