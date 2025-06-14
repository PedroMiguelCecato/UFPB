#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>
using namespace std;

class Artista {
private:
    string nome_do_artista;
    int idade_do_artista;

public:
    // Construtor
    Artista(const string& nome, int idade);

    // Métodos set e get
    void set_nome(const string& nome);
    string get_nome() const;

    void set_idade(int idade);
    int get_idade() const;

    // Sobrecarga do operador <
    bool operator<(const Artista& other) const;
};

#endif // ARTISTA_H