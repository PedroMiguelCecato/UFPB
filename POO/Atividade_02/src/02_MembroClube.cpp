#include <iostream>
#include <02_MembroClube.h>

MembroClube::MembroClube(string n, int i, double s)
    : Pessoa(n, i), salario(s) {}

double MembroClube::getSalario() const{
    return salario;
}

void MembroClube::setSalario(double s) {
    salario = s;
}