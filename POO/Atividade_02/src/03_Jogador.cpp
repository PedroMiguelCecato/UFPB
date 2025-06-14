#include <iostream>
#include <03_Jogador.h>

Jogador::Jogador(string n, int i, double s, string p, int g) 
    : MembroClube(n, i, s), posicao(p), gols_marcados(g) {}

string Jogador::getPosicao() const {
        return posicao;
    }
int Jogador::getGolsMarcados() const {
    return gols_marcados;
}

void Jogador::setPosicao(string p) {
        posicao = p;
    }
void Jogador::setGolsMarcados(int g) {
    gols_marcados = g;
}

double Jogador::calcular_salario() const{
    return salario + (gols_marcados * 100);
}

bool Jogador::operator<(const Jogador& outro) const {
    return gols_marcados < outro.gols_marcados;
}