#ifndef SHOW_H
#define SHOW_H

#include <string>
#include "evento.h"

class Show : public Evento {
private:
    std::string genero_musical;

public:
    // Construtor
    Show(const std::string& nome, int idade, const std::string& genero);

    // Sobrescrever calcula_preco()
    double calcula_preco() const override;

    // Métodos set e get para genero_musical
    void set_genero(const std::string& genero);
    std::string get_genero() const;
};

#endif // SHOW_H
