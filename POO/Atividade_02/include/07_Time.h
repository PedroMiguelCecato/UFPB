#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <04_Tecnico.h>
using namespace std;

class Time {
protected:
    string nome;
    Tecnico* tecnico;  // Ponteiro para o técnico
    vector<Jogador> jogadores;  // Vetor de jogadores
    int pontuacao;

public:
    // Construtor 
    Time(string n, Tecnico* t);

    // Gets 
    string getNome() const;
    Tecnico* getTecnico() const;
    int getPontuacao() const;
    vector<Jogador>& getJogadores();

    // Sets
    void setNome(string n);
    void setTecnico(Tecnico* t);
    void setPontuacao(int p);
    

    // Adicionar um jogador ao time
    void adicionar_jogador(const Jogador& j);

    // Registrar o resultado
    void registrar_resultado(char resultado);

    // Método para exibir as informações do time
    void exibir_informacoes() const;
    bool operator<(const Time& outro) const;
};