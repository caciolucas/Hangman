.DEFAULT_GOAL := all

OBJECTS=build/Word.o build/HangmanGame.o

build/Word.o: src/Word.cpp include/Word.h
	g++ -Iinclude src/Word.cpp -c -o build/Word.o

build/HangmanGame.o: src/HangmanGame.cpp include/HangmanGame.h
	g++ -Iinclude src/HangmanGame.cpp -c -o build/HangmanGame.o


objects: $(OBJECTS)

jogo_da_forca: objects src/main.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/main.cpp -o build/jogo_da_forca

clean:
	rm build/*.o

all: jogo_da_forca clean

run:
	./build/jogo_da_forca