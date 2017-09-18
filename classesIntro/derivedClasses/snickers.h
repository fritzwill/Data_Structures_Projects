// header for derived class called snickers. The base class for this is 
// candy. This class will have a virtual print function
// Date: 2/6/2017
// Author: Will Fritz

#ifndef SNICKERS_h
#define SNICKER_h

#include <string>
#include "candy.h" // header of base class

using namespace std;

class snickers : public candy { // snickers inherits from candy
    public:
        snickers(string = "Snickers", int = 1); // constructor
        virtual void print(); // virtual print function
};

#endif

