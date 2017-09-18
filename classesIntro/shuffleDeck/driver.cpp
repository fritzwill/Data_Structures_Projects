// Initial driver to test CardDeck. It should creat a deck of 10, print it,
// then shuffle and print it again
// Date: 2/7/2017
// Author: Will Fritz

#include "CardDeck.h"
#include <cstdlib>
#include <iostream>

int main(){
    srand(time(NULL));
    CardDeck cards(10); // 10 cards
    cout << cards; // overloaded << so should work
    cards.shuffle();
    cout << cards; // should be different from first print
    return 0;
}
    
