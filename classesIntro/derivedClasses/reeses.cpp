// Implementation for derived class resees. reeses is derived from candy
// class
// Date: 2/6/2017
// Author: Will Fritz

#include <iostream>
#include <string>
#include "reeses.h" // header for this class
#include "candy.h" // header for base class

using namespace std;

// constructor
reeses::reeses(string nameVal, int piecesVal, string typeVal): candy(nameVal, piecesVal), type(typeVal){}


void reeses::print(){
    cout << "\nTwo great tastes that tast great together!" << endl;
    cout << "(peanut butter and chocolate if you didn't know [:)" << endl;
    cout << "Name: " << getName() << endl; // name is private, thus getName()
    cout << "Pieces: " << getPieces() << endl;
    cout << "Type: " << type << endl;
}

