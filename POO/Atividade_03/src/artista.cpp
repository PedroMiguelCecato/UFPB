#include "artista.h"

// Construtor
Artista::Artista(const std::string& nome, int idade) 
    : nome_do_artista(nome), idade_do_artista(idade) {}

// Métodos set e get
void Artista::set_nome(const std::string& nome) {
    nome_do_artista = nome;
}

std::string Artista::get_nome() const {
    return nome_do_artista;
}

void Artista::set_idade(int idade) {
    idade_do_artista = idade;
}

int Artista::get_idade() const {
    return idade_do_artista;
}

// Sobrecarga do operador <
bool Artista::operator<(const Artista& other) const {
    return idade_do_artista < other.idade_do_artista;
}
