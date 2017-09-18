// derived class header called reeses. This class is derived from the candy
// class. This class will have a virtual print function, and an additional
// string to denote type of reeses
// Date: 2/6/2017
// Author: Will Fritz
#ifndef REESES_h
#define REESES_h

#include <string> 
#include "candy.h" // include header of base class

using namespace std;

class reeses : public candy { // reeses inherits from candy
    public:
        reeses(string = "Reeses", int = 2, string = "Regular");// constructor
        virtual void print(); // virtual print function
    private:
        string type; // king size vs regular vs bite size vs fastbreak
};

#endif
