salario = float(input("Salário por hora: "))
horas = float(input("Horas trabalhadas no mês: "))

salario_bruto = salario * horas
ir = salario_bruto * 0.11
inss = salario_bruto * 0.08
sindicato = salario_bruto * 0.05
salario_liquido = salario_bruto - ir - inss - sindicato

print(f"Salário bruto: R$ {salario_bruto:.2f}")
print(f"Imposto de Renda (11%): R$ {ir:.2f}")
print(f"INSS (8%): R$ {inss:.2f}")
print(f"Contribuição ao Sindicato (5%): R$ {sindicato:.2f}")
print(f"Salário líquido: R$ {salario_liquido:.2f}")