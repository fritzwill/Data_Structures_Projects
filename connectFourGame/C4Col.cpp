// Implementation for c4col class
// Date: 1/24/2017
// Author: Will Fritz

#include <iostream>
#include "C4Col.h"

using namespace std;

// Default Constructor
C4Col::C4Col(){
    numDiscs = 0;
    maxDiscs = 6;
    Discs = new char[6];
    for (int i = 0; i < 6; i++) Discs[i] = ' ';
}

C4Col::~C4Col(){
    delete [] Discs;
}

// 1 will mean it is full, 0 will mean it is not
int C4Col::isFull(){
    if (numDiscs == maxDiscs) return 1;
    else return 0;
}

// Return char of specific position. Also, checks bounds
char C4Col::getDisc(int pos){
    if (pos > maxDiscs || pos < 0){
        cout << "Error, number not within bounds" << endl;
    }
    else return Discs[pos];
}

// return maxDiscs private attribute
int C4Col::getMaxDiscs(){
    return maxDiscs;
}


void C4Col::addDiscs(char newDisc){
    numDiscs++; // increase numDiscs to check if within bounds
    if (isFull() == 1){
        cout << "The column is full! You cannot add a disc there" << endl;
        numDiscs--;//set back to original val since not within maxDiscs bound
    }
    else{
        // put newDisc in spot one less than numDiscs
        numDiscs--;
        Discs[numDiscs] = newDisc;
        numDiscs++; //put numDiscs at correct value
    }
}          
