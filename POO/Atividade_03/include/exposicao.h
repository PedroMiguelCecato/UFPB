#ifndef EXPOSICAO_H
#define EXPOSICAO_H

#include <string>
#include "evento.h"

class Exposicao : public Evento {
private:
    std::string tipo_de_arte;

public:
    // Construtor
    Exposicao(const std::string& nome, int idade, const std::string& tipo);

    // Sobrescrever calcula_preco()
    double calcula_preco() const override;

    // Métodos set e get para tipo_de_arte
    void set_tipo(const std::string& tipo);
    std::string get_tipo() const;
};

#endif // EXPOSICAO_H
