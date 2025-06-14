#include "gerenciador_de_eventos.h"

// Método para adicionar um evento
void Gerenciador_de_Eventos::adicionar_evento(Evento* ev) {
    lista_de_eventos.push_back(ev);
}

// Método para remover um evento
void Gerenciador_de_Eventos::remover_evento(Evento* ev) {
    lista_de_eventos.erase(std::remove(lista_de_eventos.begin(), lista_de_eventos.end(), ev), lista_de_eventos.end());
}

// Sobrecarga do operador +
Gerenciador_de_Eventos& Gerenciador_de_Eventos::operator+(Evento* ev) {
    adicionar_evento(ev);
    return *this;
}

// Sobrecarga do operador -
Gerenciador_de_Eventos& Gerenciador_de_Eventos::operator-(Evento* ev) {
    remover_evento(ev);
    return *this;
}

// Método para ordenar eventos pela idade
void Gerenciador_de_Eventos::ordenar_eventos() {
    std::sort(lista_de_eventos.begin(), lista_de_eventos.end(),
              [](Evento* a, Evento* b) { return *a < *b; });
}

const std::vector<Evento*>& Gerenciador_de_Eventos::get_lista_de_eventos() const {
    return lista_de_eventos;
}
