// Implementaion of the base class candy. to get public functions and a 
// print function
// Date: 2/6/2017
// Author: Will Fritz

#include "candy.h"
#include <iostream>
#include <string>

using namespace std;

// base class pointer
candy::candy(string nameVal, int piecesVal){
    name = nameVal;
    pieces = piecesVal;
}

// print format
void candy::print(){
    cout << "\nName: " << name << endl;
    cout << "Pieces: " << pieces << endl;
}

// get for name of candy
string candy::getName(){
    return name;
}

// get for number of pieces of candy
int candy::getPieces(){
    return pieces;
}
