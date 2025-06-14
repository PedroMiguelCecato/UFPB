#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <07_Time.h>
#include <08_Jogo.h>
using namespace std;

// Classe Time e Jogo (definidas anteriormente)
class Campeonato {
private:
    string nome_campeonato;
    vector<Time> times;
    vector<Jogo> jogos;

public:
    // Construtor 
    Campeonato(string nome);

    // Gets e sets 
    string getNomeCampeonato() const;
    void setNomeCampeonato(string nome);

    // Adicionar um time ao campeonato
    void adicionar_time(const Time& t) {
        times.push_back(t);
    }

    // Adicionar um jogo ao campeonato
    void adicionar_jogo(const Jogo& j);

    // Exibir a classificação dos times ordenados pela pontuação
    void exibir_classificacao() const;
};