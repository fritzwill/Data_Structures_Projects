// base class header that descirbes a type of candy. The candy will have a
// name and and and int to go along with it. The int will represent how many
// pieces of candy are in each standard package
// Date: 2/6/2017
// Author: Will Fritz

#ifndef CANDY_h
#define CANDY_h

#include <string>

using namespace std;

class candy{
    public:
        candy(string = "empty", int = 0); // constructor
        
        virtual void print() = 0; // =0 -> abstract class. print function
        
        string getName(); // get functions
        int getPieces();
    private:
        string name; // two pivate data members
        int pieces;
};
        
#endif
        
    
