candidatos = {"12":0, "34": 0, "56": 0}
eleitores = int(input("Digite o número de eleitores: "))

for i in range(eleitores):
    voto = input(f"Digite o número do candidato (12, 34, 56) que a {i+1}º pessoa escolheu: ")
    if voto in candidatos:
        candidatos[voto] += 1
    else:
        print("Voto inválido.")

print("Resultado da eleição:")
for candidato, votos in candidatos.items():
    print(f"Candidato {candidato}: {votos} votos")