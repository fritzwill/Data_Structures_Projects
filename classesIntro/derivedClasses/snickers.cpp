// Implementation for derived class, snickers
// Date: 2/6/2017
// Author: Will Fritz

#include <iostream>
#include <string>
#include "snickers.h" // this class header
#include "candy.h" // base class header

snickers::snickers (string nameVal, int piecesVal) : candy(nameVal, piecesVal){}

void snickers::print() {
    cout << "\nYou're not you when you're hunry. Snickers satisfies" << endl;
    cout << "Name: " << getName() << endl; // private values, thus getName()
    cout << "Pieces: " << getPieces() << endl; // thus getPieces()
}
