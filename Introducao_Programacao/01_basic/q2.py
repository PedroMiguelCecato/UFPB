s = input("Sexo da pessoa (M/F): ")
h = float(input("Altura da pessoa: "))

if s.upper() == 'M':
    p = (72.7 * h) - 58
    print(f"O peso ideal para um homem com {h}m de altura é {p:.2f}kg.")
else:
    p = (62.1 * h) - 44.7
    print(f"O peso ideal para uma mulher com {h}m de altura é {p:.2f}kg.")