#include <01_Pessoa.h>
#include <iostream>
#include <string>
using namespace std;

class MembroClube : public Pessoa{
protected:
    double salario;

public:
    // Contrutor
    MembroClube(string n, int i, double s);

    // Gets e sets para o atributo salário
    double getSalario() const;
    void setSalario(double s);

    // Método virtual puro calcular_salario
    virtual double calcular_salario() const = 0;

    // Sobrecarga do operador << para exibir informações do membro do clube
    friend ostream& operator<<(ostream& os, const MembroClube& membro) {
        os << "Nome: " << membro.nome << "\nIdade: " << membro.idade 
           << "\nSalário: " << membro.salario;
        return os;
    }

    void exibir_info() const override {
        cout << *this << endl; 
    }
};