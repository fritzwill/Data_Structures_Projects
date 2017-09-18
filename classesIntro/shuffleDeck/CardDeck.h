// Interface for CardDeck class
// Date: 1/31/2017
// Author: Will Fritz

#ifndef CARDDECK_h
#define CARDDECK_h

#include <iostream>

using namespace std;

class CardDeck {
        friend ostream &operator<<(ostream &, CardDeck &);// overload output
    public:
        CardDeck(int = 52);
        ~CardDeck();
       
        int getSize(); 
        void shuffle();
    private:
        int * deck;
        int size;
};       

#endif
