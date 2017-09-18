// Implementation for CardDeck class
// Date: 1/31/2017
// Author: Will Fritz

#include <cstdlib>
#include <iostream>
#include "CardDeck.h"

using namespace std;

// non-default constructor
CardDeck::CardDeck(int s){
    size = s;
    deck = new int [size]; // dynamic memory allocation
    for (int i = 0; i < size; i++)
        deck[i] = i;
}

// deconstructor
CardDeck::~CardDeck(){
    delete [] deck; // dynamic memory allocation
}

// returns private size member
int CardDeck::getSize(){
    return size;
}

// Uses Knuth's algorithm to shuffle deck (switch every element with a 
// random element
void CardDeck::shuffle(){
    int temp, randNum; // temp for swapping. randNum for what to swap
    for (int i = 0; i < size; i++){
        randNum = rand() % size; // rand between 0 and size-1
        temp = deck[randNum];
        deck[randNum] = deck[i];
        deck[i] = temp;
    }
}

// overloading << operator for output
ostream &operator<<( ostream &p, CardDeck &c) {
    for (int i = 0; i < c.getSize(); i++) {
        p << c.deck[i]; 
        if (i != c.getSize()-1) p << ", "; // no comma after last card
    }
    p << endl; // end-line
    return p; // allow for cout << (CardDeck instance)
}


    
