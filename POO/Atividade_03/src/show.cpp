#include "show.h"

// Construtor
Show::Show(const std::string& nome, int idade, const std::string& genero) 
    : Evento(nome, idade), genero_musical(genero) {}

// Sobrescrever calcula_preco()
double Show::calcula_preco() const {
    // Exemplo de cálculo de preço baseado na idade do evento, pode ser ajustado conforme a lógica desejada
    return get_idade() * 10.0; // Preço base de 10 por ano de idade do evento
}

// Métodos set e get para genero_musical
void Show::set_genero(const std::string& genero) {
    genero_musical = genero;
}

std::string Show::get_genero() const {
    return genero_musical;
}
