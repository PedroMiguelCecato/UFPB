#include <iostream>
#include <string>
using namespace std;

class Modalidade{
private:
    string nomeModalidade;
    unsigned int gruposModalidade;

public:
    //contrutor parametrizado e não parametrizado
    Modalidade(const string nome, unsigned int grupos)
        : nomeModalidade(nome), gruposModalidade(grupos) {}
    
    Modalidade() {}

    //destrutor
    ~Modalidade() {}

    //funções para receber e retornar o nome e atributo inicializados
    void set_nome(const string& nome){this->nomeModalidade = nome;}
    string get_nome() {return nomeModalidade;}

    void set_atributo(int grupos){this->gruposModalidade = grupos;}
    unsigned int get_grupos() {return gruposModalidade;}

    //função para exibir os dados de modalidade
    void exibe_modalidade(){
        if (gruposModalidade == 1) {
            cout << "Modalidade: " << nomeModalidade << " (Individual)" << endl;    
        }else{
            cout << "Modalidade: " << nomeModalidade << " (Coletivo, " << gruposModalidade << " pessoas)" << endl;
        }
    }
};