n = int(input("Numero de pessoas na turma: "))
soma_idades = 0

for i in range(n):
    idade = int(input(f"Idade da pessoa {i + 1}: "))
    soma_idades += idade

media_idade = soma_idades / n
print(f"A média de idade da turma é: {media_idade:.2f}")

if media_idade <= 25:
    print("Turma jovem")
elif 26 <= media_idade <= 60:
    print("Turma adulta")
else:
    print("Turma idosa")