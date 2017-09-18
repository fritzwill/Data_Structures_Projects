// main driver function that utilizes the nas class candy and the derived
// classes: reeses and snickers
// Date: 2/6/2017
// Author: Will Fritz

#include "candy.h"
#include "reeses.h"
#include "snickers.h"
#include <iostream>

int main(){
    reeses cup("Reeses",4,"King");
    snickers bar;

    candy * base_ptr = &cup;
    snickers * derived_ptr = &bar;

    base_ptr->print();
    derived_ptr->print();
    
    base_ptr = &bar;
    base_ptr->print();
    return 0;
}
