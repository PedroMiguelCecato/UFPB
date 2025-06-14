#ifndef GERENCIADOR_DE_EVENTOS_H
#define GERENCIADOR_DE_EVENTOS_H

#include <vector>
#include <algorithm>
#include "evento.h"

class Gerenciador_de_Eventos {
private:
    std::vector<Evento*> lista_de_eventos;

public:
    // Métodos para adicionar e remover eventos
    void adicionar_evento(Evento* ev);
    void remover_evento(Evento* ev);

    // Sobrecarga dos operadores + e -
    Gerenciador_de_Eventos& operator+(Evento* ev);
    Gerenciador_de_Eventos& operator-(Evento* ev);

    // Método para ordenar eventos pela idade
    void ordenar_eventos();

    // Método para obter a lista de eventos
    const std::vector<Evento*>& get_lista_de_eventos() const;
};

#endif // GERENCIADOR_DE_EVENTOS_H
