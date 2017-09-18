main: main.o candy.o snickers.o reeses.o
	g++ -o main main.o candy.o snickers.o reeses.o

main.o: main.cpp
	g++ -c main.cpp

snickers.o: snickers.cpp snickers.h
	g++ -c snickers.cpp

reeses.o: reeses.cpp reeses.h
	g++ -c reeses.cpp

candy.o: candy.cpp candy.h
	g++ -c candy.cpp

clean:
	rm main *.o
