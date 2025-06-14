#include <04_Tecnico.h>
#include <iostream>
#include <string>
using namespace std;

class TecnicoJogador : public Jogador, public Tecnico {
protected:
    double bonus_duplo;

public:
    // Construtor que inicializa os atributos
    TecnicoJogador(string n, int i, double s, string p, int g, int e, double bd);

    // Gets e sets
    double getBonusDuplo() const;
    void setBonusDuplo(double bd);

    // Implementação de calcular_salario()
    double calcular_salario() const override;

    // Sobrecarga do operador << para exibir as informações detalhadas do tecnico_jogador
    friend ostream& operator<<(ostream& os, const TecnicoJogador& tj) {
        os << "Nome: " << tj.Jogador::nome << "\nIdade: " << tj.Jogador::idade
           << "\nPosição: " << tj.posicao << "\nGols Marcados: " << tj.gols_marcados
           << "\nExperiência como Técnico: " << tj.experiencia
           << "\nBônus Duplo Papel: " << tj.bonus_duplo
           << "\nSalário Calculado: " << tj.calcular_salario();
        return os;
    }

    void exibir_info() const override {
        cout << *this << endl;
    }
};