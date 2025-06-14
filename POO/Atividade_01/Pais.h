#include <iostream>
#include <string>
using namespace std;

class Pais{
private:
    string nomePais;
    string nomeContinente;

public: 
    //construtor parametrizado e não parametrizado
    Pais(const string& nome, const string& continente)
        : nomePais(nome), nomeContinente(continente) {}
    
    Pais() {}
    
    //destrutor
    ~Pais() {}

    //funções para receber e retornar o nome e continente inicializados
    void set_nome(const string& nome){this->nomePais = nome;}
    string get_nome() {return nomePais;}

    void set_continente(const string& continente){this->nomeContinente = continente;}
    string get_continente() {return nomeContinente;}
    
    //função para exibir os dados do país
    void exibe_pais(){
        cout << "Continente: " << nomeContinente << endl << "Pais: " << nomePais << endl;
    }
};