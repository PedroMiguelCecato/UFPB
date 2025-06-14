#include "evento.h"
#include <algorithm>

// Construtor
Evento::Evento(const std::string& nome, int idade) 
    : nome_do_evento(nome), idade_do_evento(idade) {
    if (idade < 0) {
        throw std::invalid_argument("Idade não pode ser negativa.");
    }
}

// Métodos set e get
void Evento::set_nome(const std::string& nome) {
    nome_do_evento = nome;
}

std::string Evento::get_nome() const {
    return nome_do_evento;
}

void Evento::set_idade(int idade) {
    if (idade < 0) {
        throw std::invalid_argument("Idade não pode ser negativa.");
    }
    idade_do_evento = idade;
}

int Evento::get_idade() const {
    return idade_do_evento;
}

std::vector<Artista> Evento::get_artistas() const {
    return lista_de_artistas;
}

// Sobrecarga do operador <
bool Evento::operator<(const Evento& other) const {
    return idade_do_evento < other.idade_do_evento;
}

// Sobrecarga dos operadores + e -
Evento& Evento::operator+(const Artista& art) {
    lista_de_artistas.push_back(art);
    return *this;
}

Evento& Evento::operator-(const Artista& art) {
    lista_de_artistas.erase(
        std::remove_if(lista_de_artistas.begin(), lista_de_artistas.end(),
                       [&art](const Artista& a) { return a.get_nome() == art.get_nome(); }),
        lista_de_artistas.end());
    return *this;
}
