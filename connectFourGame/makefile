C4game: C4game.o C4Col.o C4Board.o
	g++ -o C4game C4game.o C4Col.o C4Board.o

C4game.0: C4game.cpp
	g++ -c C4game.cpp

C4Board.o: C4Board.cpp C4Board.h
	g++ -c C4Board.cpp

C4Col.o: C4Col.cpp C4Col.h
	g++ -c C4Col.cpp

clean:
	rm C4game *.o
