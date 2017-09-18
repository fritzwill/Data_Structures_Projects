// Given name, value, and suite from stdin the program should return the names
// in order from highest to lowest
// Date: 3/21/17
// Author: Will Fritz

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <sstream>
#include <list>

using namespace std;

// struct to use to store inputs
struct cardHolder {
    string name;
    int rank;
    int suit;
};

// prototypes
bool compareRank(cardHolder &, cardHolder &);
void print(list<cardHolder> &);

int main (){
    int numHands, wordPos; 
    string line, word;
    getline(cin, line);
    while (line != "-1"){
        numHands = stoi(line); 
        list<cardHolder> out;
        for (int i = 0; i < numHands; i++){
            getline(cin, line);
            istringstream iss(line); // so we can get each word of the line
            wordPos = 0; 
            cardHolder filler;
            while (iss >> word){
                switch(wordPos){
                    case 0:
                        // name of person
                        filler.name = word;
                        break;
                    case 1: 
                        // Rank of card
                        if (word == "J") word = "11";
                        else if (word == "Q") word = "12";
                        else if (word == "K") word = "13";
                        else if (word == "A") word = "14";
                        filler.rank = stoi(word);    
                        break;
                    case 2:
                        // Rank of suit
                        if (word == "C") filler.suit = 1;
                        else if (word == "D") filler.suit = 2;
                        else if (word == "H") filler.suit = 3;
                        else if (word == "S") filler.suit = 4;
                        break;
                    default:
                        cout << "Error, invalid input\n";
                }
                wordPos++;
            }
            out.push_back(filler);
            
        }
        getline(cin, line);
        out.sort(&compareRank); // calls the rule
        print(out);
    }
    return 1;
}

// functions
bool compareRank(cardHolder &c1, cardHolder &c2){
    if (c1.rank == c2.rank) return c1.suit > c2.suit; // rank equal so suit
    return c1.rank > c2.rank;
}

void print(list<cardHolder> &c){
    for (auto it = c.begin(); it != --c.end(); it++)
        cout << it->name << ", ";
    list<cardHolder>::iterator i = --c.end();
    cout << i->name << endl;
}
            
    
    
    
    
