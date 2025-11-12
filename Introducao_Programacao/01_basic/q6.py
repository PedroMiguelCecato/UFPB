nota1 = float(input("Digite a primeira nota: "))
nota2 = float(input("Digite a segunda nota: "))

media = (nota1 + nota2) / 2

if media <= 4.0:
    print("E")
elif media <= 6.0:
    print("D")
elif media <= 7.5:
    print("C")
elif media <= 9.0:
    print("B")
elif media <= 10.0:
    print("A")
else:
    print("Nota inválida")