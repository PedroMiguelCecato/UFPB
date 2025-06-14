#include <iostream>
#include <string>
using namespace std;

void atributos_Pais(string* np, string* nc){
    cout << "Continente: ";
    cin >> *nc;
    cout << "Pais: ";
    cin >> *np;
}

void atributos_Modalidade(string* nm, unsigned int* gp){
    cout << "Modalidade: ";
    cin >> *nm;
    cout << "Quantidade de participantes por equipe: ";
    cin >> *gp;
}

void atributos_Atleta(string* na){
    cout << "Nome do atleta: ";
    cin >> *na;
}

void atributos_Medalha(string* t, int* a){
    cout << "Tipo de medalha: ";
    cin >> *t;
    cout << "Ano: ";
    cin >> *a;
}