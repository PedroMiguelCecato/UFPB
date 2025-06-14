#include "exposicao.h"

// Construtor
Exposicao::Exposicao(const std::string& nome, int idade, const std::string& tipo) 
    : Evento(nome, idade), tipo_de_arte(tipo) {}

// Sobrescrever calcula_preco()
double Exposicao::calcula_preco() const {
    // Exemplo de cálculo de preço baseado na idade do evento, pode ser ajustado conforme a lógica desejada
    return get_idade() * 15.0; // Preço base de 15 por ano de idade do evento
}

// Métodos set e get para tipo_de_arte
void Exposicao::set_tipo(const std::string& tipo) {
    tipo_de_arte = tipo;
}

std::string Exposicao::get_tipo() const {
    return tipo_de_arte;
}
