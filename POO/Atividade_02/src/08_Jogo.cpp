#include <iostream>
#include <08_Jogo.h>

Jogo::Jogo(Time* casa, Time* visitante, Juiz* juiz) 
    : time_casa(casa), time_visitante(visitante), juiz_principal(juiz), 
      gols_time_casa(0), gols_time_visitante(0) {}

Time* Jogo::getTimeCasa() const {
    return time_casa;
}
Time* Jogo::getTimeVisitante() const {
    return time_visitante;
}
Time* Jogo::getTimeVisitante() const {
    return time_visitante;
}
Juiz* Jogo::getJuizPrincipal() const {
    return juiz_principal;
}
int Jogo::getGolsTimeCasa() const {
    return gols_time_casa;
}
int Jogo::getGolsTimeVisitante() const {
    return gols_time_visitante;
}

void Jogo::setTimeCasa(Time* casa) {
    time_casa = casa;
}
void Jogo::setTimeVisitante(Time* visitante) {
    time_visitante = visitante;
}
void Jogo::setJuizPrincipal(Juiz* juiz) {
    juiz_principal = juiz;
}

void Jogo::registrar_resultado(int gols_casa, int gols_visitante) {
    gols_time_casa = gols_casa;
    gols_time_visitante = gols_visitante;

    if (gols_casa > gols_visitante) {
        time_casa->registrar_resultado('V');
        time_visitante->registrar_resultado('D');
    } else if (gols_casa < gols_visitante) {
        time_casa->registrar_resultado('D');
        time_visitante->registrar_resultado('V');
    } else {
        time_casa->registrar_resultado('E');
        time_visitante->registrar_resultado('E');
    }
}

void Jogo::exibir_informacoes() const {
    cout << "Jogo entre " << time_casa->getNome() << " e " << time_visitante->getNome() << "\n";
    cout << "Resultado: " << gols_time_casa << " x " << gols_time_visitante << "\n";
    cout << "Juiz: " << (juiz_principal ? juiz_principal->getNome() : "Sem Juiz") << endl;
}