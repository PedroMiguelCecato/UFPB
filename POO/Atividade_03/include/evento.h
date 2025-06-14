#ifndef EVENTO_H
#define EVENTO_H

#include <string>
#include <vector>
#include <stdexcept>
#include "artista.h"

class Evento {
private:
    std::string nome_do_evento;
    int idade_do_evento;
    std::vector<Artista> lista_de_artistas;

public:
    // Construtor
    Evento(const std::string& nome, int idade);

    // Métodos set e get
    void set_nome(const std::string& nome);
    std::string get_nome() const;

    void set_idade(int idade);
    int get_idade() const;

    std::vector<Artista> get_artistas() const;

    // Método virtual puro
    virtual double calcula_preco() const = 0;

    // Sobrecarga do operador <
    bool operator<(const Evento& other) const;

    // Sobrecarga dos operadores + e -
    Evento& operator+(const Artista& art);
    Evento& operator-(const Artista& art);
};

#endif // EVENTO_H
