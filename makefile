CC=g++ -std=c++11
SRC=src/
BIN=bin/
OBJ=obj/
INC=inc/

OPTS= -lsfml-graphics -lsfml-window -lsfml-system -I $(INC)

tamalol: $(OBJ)main.o $(OBJ)Game.o $(OBJ)GameController.o $(OBJ)tamagotchi.o
	$(CC) $(OBJ)main.o $(OBJ)Game.o $(OBJ)GameController.o $(OBJ)tamagotchi.o -o tamalol $(OPTS)

$(OBJ)main.o: $(SRC)main.cpp
	$(CC) -c $(SRC)main.cpp -o $(OBJ)main.o $(OPTS)

$(OBJ)tamagotchi.o: $(SRC)tamagotchi.cpp $(INC)entity.h $(INC)EventsManager.h $(INC)tamagotchi.h
	$(CC) -c $(SRC)tamagotchi.cpp -o $(OBJ)tamagotchi.o $(OPTS)

$(OBJ)GameController.o: $(SRC)GameController.cpp $(INC)GameEngine.h
	$(CC) -c $(SRC)GameController.cpp -o $(OBJ)GameController.o $(OPTS)

$(OBJ)Game.o: $(SRC)Game.cpp $(INC)GameEngine.h $(INC)tamagotchi.h
	$(CC) -c $(SRC)Game.cpp -o $(OBJ)Game.o $(OPTS)

clean:
	rm -rf $(OBJ)*.o

run:
	./tamalol

cnr: clean tamalol run

