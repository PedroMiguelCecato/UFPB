#include <iostream>
#include <string>
#include <vector>
#include "Pais.h"
#include "Modalidade.h"

class Atleta{
private:
    std::string nomeAtleta;
    Pais* paisAtleta;
    std::vector<Modalidade*> modalidadesAtleta;

public:
    //construtor parametrizado e não parametrizado
    Atleta(const std::string nome, Pais* pais)
        : nomeAtleta(nome), paisAtleta(pais) {}

    Atleta() {}
    
    //destrutor com valor
    ~Atleta() {
        for (Modalidade* modalidade : modalidadesAtleta) {
            delete modalidade;
        }
    }

    //funções para receber, retornar o nome, pais e modalidade do atleta
    void set_nome(const std::string nome) {this->nomeAtleta = nome;}
    std::string get_nome() {return nomeAtleta;}

    void set_pais(Pais* pais) {this->paisAtleta = pais;}
    Pais* get_pais() {return paisAtleta;}

    void set_modalidade(Modalidade* modalidade) {
        modalidadesAtleta.push_back(modalidade);
    }
    std::vector<Modalidade*> get_modalidade() {return modalidadesAtleta;}

    //função para exibir informações do atleta
    void exibe_atleta() {
        paisAtleta->exibe_pais();
        std::cout << "Atleta: " << nomeAtleta << std::endl;
        for (Modalidade* modalidade : modalidadesAtleta) {
            modalidade->exibe_modalidade();
        }
    }
};