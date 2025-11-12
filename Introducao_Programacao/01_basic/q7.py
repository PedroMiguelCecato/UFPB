pagamento = input("Digite a forma de pagamento (dinheiro, cheque): ").strip().lower()
valor = float(input("Digite o valor da compra: "))

if pagamento == "dinheiro" and valor >= 100:
    valor_final = valor - (valor * 0.1)
    print(f"Desconto de 10% aplicado. Valor final: R$ {valor_final:.2f}")
elif pagamento == "cheque" or pagamento == "dinheiro":
    print(f"Valor final: R$ {valor:.2f}")
else:
    print("Forma de pagamento inválida.")