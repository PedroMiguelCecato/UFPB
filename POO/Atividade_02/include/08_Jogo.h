#include <iostream>
#include <string>
#include <06_Juiz.h>
#include <07_Time.h>
using namespace std;

class Jogo {
protected:
    Time* time_casa;
    Time* time_visitante;
    Juiz* juiz_principal;
    int gols_time_casa;
    int gols_time_visitante;

public:
    // Construtor 
    Jogo(Time* casa, Time* visitante, Juiz* juiz);

    // Gets
    Time* getTimeCasa() const;
    Time* getTimeVisitante() const;
    Time* getTimeVisitante() const;
    Juiz* getJuizPrincipal() const;
    int getGolsTimeCasa() const;
    int getGolsTimeVisitante() const;

    // Sets
    void setTimeCasa(Time* casa);
    void setTimeVisitante(Time* visitante);
    void setJuizPrincipal(Juiz* juiz);

    // Registrar o resultado do jogo 
    void registrar_resultado(int gols_casa, int gols_visitante);

    // Método para exibir as informações do jogo
    void exibir_informacoes() const;
};