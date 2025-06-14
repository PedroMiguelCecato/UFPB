#include <iostream>
#include <string>
using namespace std;

class Pessoa{
protected:
    string nome;
    int idade;
    static int cont_pessoa;

public:
    // Construtor e destrutor
    Pessoa(string n, int i);
    ~Pessoa();

    // Métodos Get
    string getNome() const;
    int getIdade() const;
    static int getContador();

    // Métodos Set
    void setNome(string n);
    void setIdade(int i);

    // Método virtual puro exibir_info
    virtual void exibir_info() const = 0;

    // Sobrecarga do operador == para comparar pessoas
    bool operator==(const Pessoa& outra) const;
};