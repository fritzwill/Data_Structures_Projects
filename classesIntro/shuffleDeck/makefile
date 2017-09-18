driver: driver.o CardDeck.o 
	g++ -o driver driver.o CardDeck.o

dirver.o: driver.cpp
	g++ -c driver.cpp

CarDeck.o: CardDeck.cpp CardDeck.h
	g++ -c CardDeck.cpp

clean:
	rm driver *.o
