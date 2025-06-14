#include <iostream>
#include <06_Juiz.h>

Juiz::Juiz(string n, int i, int pa) : Pessoa(n, i), partidas_arb(pa) {}

int Juiz::getPartidasArbitradas() const {
    return partidas_arb;
}

void Juiz::setPartidasArbitradas(int pa) {
    partidas_arb = pa;
}

void Juiz::incrementar_partidas_arbitradas() {
    partidas_arb++;
}

void Juiz::exibir_info() const {
    cout << "Nome: " << nome << "\nIdade: " << idade
         << "\nPartidas Arbitradas: " << partidas_arb << endl;
}