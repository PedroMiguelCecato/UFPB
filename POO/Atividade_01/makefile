CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: olimpico

olimpico: main.o Pais.o Modalidade.o Atleta.o Medalha.o
	$(CXX) $(CXXFLAGS) -o olimpico main.o Pais.o Modalidade.o Atleta.o Medalha.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Pais.o: Pais.cpp
	$(CXX) $(CXXFLAGS) -c Pais.cpp

Modalidade.o: Modalidade.cpp
	$(CXX) $(CXXFLAGS) -c Modalidade.cpp

Atleta.o: Atleta.cpp
	$(CXX) $(CXXFLAGS) -c Atleta.cpp

Medalha.o: Medalha.cpp
	$(CXX) $(CXXFLAGS) -c Medalha.cpp

clean:
	rm -f *.o olimpico