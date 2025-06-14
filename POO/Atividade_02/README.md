# Segunda atividade da cadeira de Programação Orientada a Objetos

Este projeto implementa um sistema simples de gerenciamento de campeonatos de clubes esportivos, incluindo times, jogadores, técnicos e juízes. O projeto é organizado em classes como `Pessoa`, `MembroClube`, `Jogador`, `Tecnico`, `TecnicoJogador`, `Juiz`, `Time`, `Jogo`, e `Campeonato`.

## Classes e Funcionalidades Principais

- **Pessoa**: Classe abstrata base para representar uma pessoa com nome e idade.
- **MembroClube**: Classe abstrata derivada de `Pessoa` para representar membros de um clube.
- **Jogador**: Deriva de `MembroClube`, representa um jogador, com atributos como posição e gols marcados.
- **Tecnico**: Deriva de `MembroClube`, representa um técnico, com anos de experiência.
- **TecnicoJogador**: Usa herança múltipla de `Jogador` e `Tecnico`, para representar uma pessoa que desempenha ambos os papéis.
- **Juiz**: Deriva de `Pessoa`, representa um juiz com número de partidas arbitradas.
- **Time**: Representa um time de futebol com jogadores e um técnico.
- **Jogo**: Representa um jogo entre dois times e o juiz que apita a partida.
- **Campeonato**: Gerencia um campeonato com times e jogos.

## Compilando o Projeto

Para compilar o projeto, é necessário ter o compilador `g++` instalado. O projeto usa um `Makefile` para automatizar o processo de compilação.

1. Certifique-se de que os arquivos `.cpp` estão na pasta `src` e os cabeçalhos `.h` estão na pasta `include`.
2. Execute o comando:

    ```bash
    make
    ```

Esse comando irá compilar todos os arquivos fonte e gerar um executável chamado `campeonato`.

### Limpando os Arquivos Compilados

Para remover os arquivos compilados (`.o`) e o executável, use o comando:

```bash
make clean