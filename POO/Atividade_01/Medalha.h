#include <iostream>
#include <string>
#include "Atleta.h"

class Medalha{
private:
    std::string tipoMedalha;
    int anoMedalha;
    Atleta* atletaMedalha;

public:
    //contrutor parametrizado e não parametrizado
    Medalha(std::string tipo, int ano, Atleta* atleta)
        : tipoMedalha(tipo), anoMedalha(ano), atletaMedalha(atleta) {}
    
    Medalha() {}
    
    //destrutor
    ~Medalha() {}

    //funções para receber e retornar tipo, ano, atleta, modalidade
    void set_tipo(std::string tipo) {this->tipoMedalha = tipo;}
    std::string get_tipo() {return tipoMedalha;}

    void set_ano(int ano) {this->anoMedalha = ano;}
    int get_ano() {return anoMedalha;}

    void set_atleta(Atleta* atleta) {this->atletaMedalha = atleta;}
    Atleta* get_atleta() {return atletaMedalha;}

    //função para exibir dados da medalha
    void exibe_medalha() {
        atletaMedalha->exibe_atleta();
        std::cout << "Ano: " << anoMedalha << std::endl << "Medalha: " << tipoMedalha << std::endl;
    }
};