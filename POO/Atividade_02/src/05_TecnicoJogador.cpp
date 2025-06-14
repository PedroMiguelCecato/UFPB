#include <iostream>
#include <05_TecnicoJogador.h>

TecnicoJogador::TecnicoJogador(string n, int i, double s, string p, int g, int e, double bd)
    : Jogador(n, i, s, p, g), Tecnico(n, i, s, e), bonus_duplo(bd) {}

double TecnicoJogador::getBonusDuplo() const {
        return bonus_duplo;
    }
void TecnicoJogador::setBonusDuplo(double bd) {
    bonus_duplo = bd;
}

double TecnicoJogador::calcular_salario() const{
    return Jogador::calcular_salario() + Tecnico::calcular_salario() + bonus_duplo;
}