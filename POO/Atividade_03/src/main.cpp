#include <iostream>
#include "artista.h"
#include "exposicao.h"
#include "show.h"
#include "gerenciador_de_eventos.h"



int main() {
    // Criando alguns artistas
    Artista artista1("Artista A", 30);
    Artista artista2("Artista B", 25);
    Artista artista3("Artista C", 40);

    // Criando eventos
    Show* show1 = new Show("Show de Rock", 5, "Rock");
    Exposicao* exposicao1 = new Exposicao("Exposicao de Arte Moderna", 3, "Arte Moderna");

    // Adicionando artistas aos eventos
    *show1 + artista1;
    *show1 + artista2;
    *exposicao1 + artista3;

    // Criando o gerenciador de eventos
    Gerenciador_de_Eventos gerenciador;

    // Adicionando eventos ao gerenciador
    gerenciador + show1;
    gerenciador + exposicao1;

    // Ordenando eventos pela idade
    gerenciador.ordenar_eventos();

   // Exibindo informações dos eventos
    std::cout << "Eventos gerenciados:\n";
    for (Evento* ev : gerenciador.get_lista_de_eventos()) {
        std::cout << "Nome: " << ev->get_nome() << ", Idade: " << ev->get_idade() << ", Preco: " << ev->calcula_preco() << "\n";
    }


    // Removendo um evento
    gerenciador - show1;

    // Limpando a memória
    delete show1;
    delete exposicao1;

    return 0;
}

/*
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}*/
