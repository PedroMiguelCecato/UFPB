valor = float(input("Valor da compra: R$ "))
pagamento = input("Forma de pagamento (dinheiro, cartao ou cheque): ").strip().lower()

if pagamento == "dinheiro" and valor >= 100:
    valor_final = valor - (valor * 0.1)
    print(f"Desconto de 10% aplicado. Valor final: R$ {valor_final:.2f}")
elif pagamento == "cheque" or pagamento == "dinheiro":
    print(f"Valor final: R$ {valor:.2f}")
elif pagamento == "cartao":
    forma = input("Débito ou crédito? ").strip().lower()
    if forma == "crédito":
        parcelas = int(input("Número de parcelas (1, 2 ou 3): "))
        if parcelas >= 1 and parcelas <= 3:
            print(f"Valor final: R$ {valor:.2f} em {parcelas} parcelas de R$ {valor/parcelas:.2f} cada.")
        else:
            print("Número de parcelas inválido.")
    elif forma == "débito":
        print(f"Valor final: R$ {valor:.2f} no débito.")
    else:
        print("Forma de pagamento inválida.")
else:
    print("Forma de pagamento inválida.")