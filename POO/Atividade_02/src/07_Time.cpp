#include <iostream>
#include <07_Time.h>

Time::Time(string n, Tecnico* t) : nome(n), tecnico(t), pontuacao(0) {}

string Time::getNome() const {
    return nome;
}

Tecnico* Time::getTecnico() const {
    return tecnico;
}

int Time::getPontuacao() const {
    return pontuacao;
}

vector<Jogador>& Time::getJogadores() {
    return jogadores;
}

void Time::setNome(string n) {
    nome = n;
}

void Time::setTecnico(Tecnico* t) {
    tecnico = t;
}

void Time::setPontuacao(int p) {
    pontuacao = p;
}

void Time::adicionar_jogador(const Jogador& j) {
    jogadores.push_back(j);
}

void Time::registrar_resultado(char resultado) {
    switch (resultado) {
    case 'V':  
        pontuacao += 3;
        break;
    case 'E':  
        pontuacao += 1;
        break;
    case 'D': 
        break;
    }
}

void Time::exibir_informacoes() const {
    cout << "Time: " << nome << "\nPontuação: " << pontuacao << "\nTécnico: "
         << (tecnico ? tecnico->getNome() : "Sem Técnico") << "\nJogadores:\n";
    for (const auto& jogador : jogadores) {
        cout << jogador.getNome() << " - Posição: " << jogador.getPosicao() << "\n";
    }
}

bool Time::operator<(const Time& outro) const {
    return pontuacao < outro.pontuacao;
}