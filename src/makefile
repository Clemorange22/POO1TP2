CXX = g++
CXXFLAGS = -g
all: main.o
	g++ main.o Catalogue.o Interface.o ListeParcours.o Trajet.o TrajetSimple.o TrajetCompose.o Parcours.o -o main

main.o: Interface.o 


Interface.o : Catalogue.o ListeParcours.o Parcours.o
Catalogue.o: Trajet.o TrajetSimple.o TrajetCompose.o Parcours.o ListeParcours.o

ListeParcours.o: Parcours.o

Parcours.o: Trajet.o TrajetSimple.o TrajetCompose.o

clean:
	rm main.o Catalogue.o Interface.o ListeParcours.o Trajet.o TrajetSimple.o TrajetCompose.o main.o Parcours.o

run: all
	./main