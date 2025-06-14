#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "exposicao.h"
#include "show.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->adicionarButton, &QPushButton::clicked, this, &MainWindow::adicionarEvento);
    connect(ui->removerButton, &QPushButton::clicked, this, &MainWindow::removerEvento);
    connect(ui->adicionarArtistaButton, &QPushButton::clicked, this, &MainWindow::adicionarArtista);
    connect(ui->removerArtistaButton, &QPushButton::clicked, this, &MainWindow::removerArtista);
    connect(ui->listarButton, &QPushButton::clicked, this, &MainWindow::listarEventos);
    connect(ui->ordenarButton, &QPushButton::clicked, this, &MainWindow::ordenarEventos);
    connect(ui->listarArtistasButton, &QPushButton::clicked, this, &MainWindow::listarArtistas);
    connect(ui->ordenarArtistasButton, &QPushButton::clicked, this, &MainWindow::ordenarArtistas);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::adicionarEvento() {
    QString tipoEvento = ui->tipoComboBox->currentText();
    QString nomeEvento = ui->nomeLineEdit->text();
    int idadeEvento = ui->idadeSpinBox->value();

    if (tipoEvento == "Exposição") {
        QString tipoArte = ui->tipoArteLineEdit->text();
        Exposicao* exposicao = new Exposicao(nomeEvento.toStdString(), idadeEvento, tipoArte.toStdString());
        gerenciador.adicionar_evento(exposicao);
    } else if (tipoEvento == "Show") {
        QString generoMusical = ui->generoMusicalLineEdit->text();
        Show* show = new Show(nomeEvento.toStdString(), idadeEvento, generoMusical.toStdString());
        gerenciador.adicionar_evento(show);
    }

    QMessageBox::information(this, "Sucesso", "Evento adicionado com sucesso!");
}

void MainWindow::removerEvento() {
    QListWidgetItem* item = ui->eventosListWidget->currentItem();
    if (item) {
        // Encontrar e remover o evento do gerenciador
        QString nomeEvento = item->text().split(" - ").first();
        for (Evento* ev : gerenciador.get_lista_de_eventos()) {
            if (QString::fromStdString(ev->get_nome()) == nomeEvento) {
                gerenciador.remover_evento(ev);
                break;
            }
        }
        delete item;
        QMessageBox::information(this, "Sucesso", "Evento removido com sucesso!");
    }
}

void MainWindow::adicionarArtista() {
    QListWidgetItem* item = ui->eventosListWidget->currentItem();
    if (item) {
        QString nomeEvento = item->text().split(" - ").first();
        for (Evento* ev : gerenciador.get_lista_de_eventos()) {
            if (QString::fromStdString(ev->get_nome()) == nomeEvento) {
                QString nomeArtista = ui->nomeArtistaLineEdit->text();
                int idadeArtista = ui->idadeArtistaSpinBox->value();
                Artista artista(nomeArtista.toStdString(), idadeArtista);
                *ev + artista;
                QMessageBox::information(this, "Sucesso", "Artista adicionado com sucesso!");
                listarArtistas();
                return;
            }
        }
    }
}

void MainWindow::removerArtista() {
    QListWidgetItem* eventoItem = ui->eventosListWidget->currentItem();
    QListWidgetItem* artistaItem = ui->artistasListWidget->currentItem();

    if (eventoItem && artistaItem) {
        QString nomeEvento = eventoItem->text().split(" - ").first();
        QString nomeArtista = artistaItem->text().split(" - ").first();

        for (Evento* ev : gerenciador.get_lista_de_eventos()) {
            if (QString::fromStdString(ev->get_nome()) == nomeEvento) {
                for (const Artista& artista : ev->get_artistas()) {
                    if (QString::fromStdString(artista.get_nome()) == nomeArtista) {
                        *ev - artista;
                        delete artistaItem;
                        QMessageBox::information(this, "Sucesso", "Artista removido com sucesso!");
                        return;
                    }
                }
            }
        }
    }
}

void MainWindow::listarEventos() {
    ui->eventosListWidget->clear();
    for (const auto& evento : gerenciador.get_lista_de_eventos()) {
        QString descricao = QString::fromStdString(evento->get_nome()) + " - Idade: " + QString::number(evento->get_idade());
        ui->eventosListWidget->addItem(descricao);
    }
}

void MainWindow::listarArtistas() {
    ui->artistasListWidget->clear();
    QListWidgetItem* eventoItem = ui->eventosListWidget->currentItem();
    if (eventoItem) {
        QString nomeEvento = eventoItem->text().split(" - ").first();
        for (Evento* ev : gerenciador.get_lista_de_eventos()) {
            if (QString::fromStdString(ev->get_nome()) == nomeEvento) {
                for (const Artista& artista : ev->get_artistas()) {
                    QString descricao = QString::fromStdString(artista.get_nome()) + " - Idade: " + QString::number(artista.get_idade());
                    ui->artistasListWidget->addItem(descricao);
                }
                break;
            }
        }
    }
}

void MainWindow::ordenarEventos() {
    gerenciador.ordenar_eventos();
    listarEventos();
}

void MainWindow::ordenarArtistas() {
    QListWidgetItem* eventoItem = ui->eventosListWidget->currentItem();
    if (eventoItem) {
        QString nomeEvento = eventoItem->text().split(" - ").first();
        for (Evento* ev : gerenciador.get_lista_de_eventos()) {
            if (QString::fromStdString(ev->get_nome()) == nomeEvento) {
                std::vector<Artista> artistas = ev->get_artistas();
                std::sort(artistas.begin(), artistas.end());
                ui->artistasListWidget->clear();
                for (const Artista& artista : artistas) {
                    QString descricao = QString::fromStdString(artista.get_nome()) + " - Idade: " + QString::number(artista.get_idade());
                    ui->artistasListWidget->addItem(descricao);
                }
                return;
            }
        }
    }
}