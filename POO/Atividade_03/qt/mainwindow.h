#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gerenciador_de_eventos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void adicionarEvento();    // Adiciona novo evento
    void removerEvento();      // Remove evento selecionado
    void adicionarArtista();   // Adiciona artista ao evento
    void removerArtista();     // Remove artista do evento
    void listarEventos();      // Lista todos os eventos
    void listarArtistas();     // Lista todos os artistas do evento selecionado
    void ordenarEventos();     // Ordena eventos por idade
    void ordenarArtistas();    // Ordena artistas por idade

private:
    Ui::MainWindow *ui;
    Gerenciador_de_Eventos gerenciador;
};

#endif // MAINWINDOW_H