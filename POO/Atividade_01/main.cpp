#include <iostream>
#include <string>
#include "Medalha.h"
#include "Funcoes.h"
using namespace std;

int main() {
    // Criando uma variável da classe País
    string nomePais, nomeContinente;
    atributos_Pais(&nomePais, &nomeContinente);
    Pais pais(nomePais, nomeContinente); //poderia ser inicializado sem parâmetros e usado o método set nas variáveis criadas
    
    // Criando uma variável da classe Modalidade
    string nomeModal;
    unsigned int gpModal;
    atributos_Modalidade(&nomeModal, &gpModal);
    Modalidade modalidade(nomeModal, gpModal);

    // Criando uma variável da classe Atleta
    string nomeAtleta;
    atributos_Atleta(&nomeAtleta);
    Atleta atleta(nomeAtleta, &pais);
    atleta.set_modalidade(&modalidade); //inicializando uma instância da classe atleta e adicionando sua modalidade

    // Criando uma variável da classe Medalha
    string tipoMedal;
    int anoMedal;
    atributos_Medalha(&tipoMedal, &anoMedal); 
    Medalha medalha(tipoMedal, anoMedal, &atleta);

    std::cout << endl;
    medalha.exibe_medalha();

    return 0;
}