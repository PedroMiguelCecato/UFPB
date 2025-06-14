#include <01_Pessoa.h>
#include <iostream>
#include <string>
using namespace std;

class Juiz : public Pessoa {
protected:
    int partidas_arb;

public:
    // Construtor que inicializa os atributos
    Juiz(string n, int i, int pa);

    // Gets e sets
    int getPartidasArbitradas() const;
    void setPartidasArbitradas(int pa);

    // Método para incrementar o número de partidas arbitradas
    void incrementar_partidas_arbitradas();

    // Implementação do método exibir_informacoes() que exibe o número de partidas arbitradas
    void exibir_info() const override;
};