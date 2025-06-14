#include <iostream>
#include "01_Pessoa.h"

int Pessoa::cont_pessoa = 0;

Pessoa::Pessoa(string n, int i) : nome(n), idade(i) {
    cont_pessoa++;
}

Pessoa::~Pessoa() {
    cont_pessoa--;
}

string Pessoa::getNome() const {
    return nome;
}

int Pessoa::getIdade() const {
    return idade;
}

int Pessoa::getContador() {
    return cont_pessoa;
}

void Pessoa::setNome(string n) {
    nome = n;
}

void Pessoa::setIdade(int i) {
    idade = i;
}

bool Pessoa::operator==(const Pessoa& outra) const {
    return (nome == outra.nome && idade == outra.idade);
}