#include <02_MembroClube.h>
#include <iostream>
#include <string>
using namespace std;

class Jogador : public MembroClube {
protected:
    string posicao;
    int gols_marcados;

public:
    // Construtor 
    Jogador(string n, int i, double s, string p, int g) 
        : MembroClube(n, i, s), posicao(p), gols_marcados(g) {}

    // Métodos Gets
    string getPosicao() const;
    int getGolsMarcados() const;

    // Métodos Sets
    void setPosicao(string p);
    void setGolsMarcados(int g);

    // Implementação de calcular_salario()
    double calcular_salario() const override;

    // Sobrecarga do operador < para comparar jogadores pelo número de gols
    bool operator<(const Jogador& outro) const;

    // Sobrecarga do operador << para exibir as informações do jogador
    friend ostream& operator<<(ostream& os, const Jogador& jogador) {
        os << "Nome: " << jogador.nome << "\nIdade: " << jogador.idade
           << "\nPosição: " << jogador.posicao << "\nGols Marcados: " << jogador.gols_marcados
           << "\nSalário Calculado: " << jogador.calcular_salario();
        return os;
    }

    void exibir_info() const override {
        cout << *this << endl;
    }
};