x = 70000
y = 180000
anos = 0

while x < y:
    x += x * 0.035
    y += y * 0.015
    anos += 1

print(f"Serão necessários {anos} anos para que a população da cidade X ultrapasse ou iguale a população da cidade Y.")