#include <03_Jogador.h>
#include <iostream>
#include <string>
using namespace std;

class Tecnico : public MembroClube {
protected:
    int experiencia; // Anos de experiência como técnico

public:
    // Construtor 
    Tecnico(string n, int i, double s, int e = 0);

    // Gets e sets 
    int getExperiencia() const;
    void setExperiencia(int e);

    // Implementação de calcular_salario()
    double calcular_salario() const override;

    // Sobrecarga do operador << para exibir as informações do técnico
    friend ostream& operator<<(ostream& os, const Tecnico& tecnico) {
        os << "Nome: " << tecnico.nome << "\nIdade: " << tecnico.idade
           << "\nAnos de Experiência: " << tecnico.experiencia
           << "\nSalário Calculado: " << tecnico.calcular_salario();
        return os;
    }

    void exibir_info() const override {
        cout << *this << endl;
    }
};