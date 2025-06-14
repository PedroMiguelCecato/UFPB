# Makefile para o Sistema de Gerenciamento de Campeonato de Futebol
# Diretórios
INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I$(INCLUDE_DIR)

# Arquivos de cabeçalho e código-fonte
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Objetos gerados para cada arquivo-fonte
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Nome do executável
EXEC = main

# Alvo padrão para compilar todo o projeto
all: $(BUILD_DIR) $(EXEC)

# Cria o diretório build, caso não exista
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Gera o executável a partir dos objetos
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar os arquivos-fonte em arquivos-objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Executa o programa após compilar
run: all
	./$(EXEC)

# Recompila o projeto
rebuild: clean all
