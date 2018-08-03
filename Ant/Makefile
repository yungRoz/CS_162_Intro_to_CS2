all: ant

ant: main.o moveAnt.o integerValidation.o menu.o
	g++ main.o moveAnt.o integerValidation.o menu.o -o ant

main.o: main.cpp
	g++ -c main.cpp

moveAnt.o: moveAnt.cpp
	g++ -c moveAnt.cpp

integerValidation.o: integerValidation.cpp
	g++ -c integerValidation.cpp

menu.o : menu.cpp
	g++ -c menu.cpp

clean:
	rm -rf *o ant

