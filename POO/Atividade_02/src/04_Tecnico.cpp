#include <iostream>
#include <04_Tecnico.h>

Tecnico::Tecnico(string n, int i, double s, int e = 0) 
    : MembroClube(n, i, s), experiencia(e) {}

int Tecnico::getExperiencia() const {
        return experiencia;
    }
void Tecnico::setExperiencia(int e) {
    experiencia = e;
}

double Tecnico::calcular_salario() const{
    return salario + (experiencia * 200);
}