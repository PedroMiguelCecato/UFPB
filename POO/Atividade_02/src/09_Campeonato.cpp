#include <iostream>
#include <09_Campeonato.h>

Campeonato::Campeonato(string nome) : nome_campeonato(nome) {}
    
string Campeonato::getNomeCampeonato() const {
    return nome_campeonato;
}

void Campeonato::setNomeCampeonato(string nome) {
    nome_campeonato = nome;
}

void Campeonato::adicionar_time(const Time& t) {
    times.push_back(t);
}

void Campeonato::exibir_classificacao() const {
    vector<Time> classificacao = times;  // Cria uma cópia para ordenar
    sort(classificacao.begin(), classificacao.end(), [](const Time& a, const Time& b) {
        return b.getPontuacao() < a.getPontuacao();  // Maior pontuação primeiro
    });

    cout << "Classificação do Campeonato " << nome_campeonato << ":\n";
    for (const auto& time : classificacao) {
        cout << time.getNome() << " - Pontuação: " << time.getPontuacao() << "\n";
    }
}