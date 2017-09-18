// Implementation for C4Board class
// Date: 1/30/2017
// Author: Will Fritz


#include <iostream>
#include <iomanip>
#include "C4Board.h"

using namespace std;

// Default Constructor
C4Board::C4Board(){
    numCols = 7;
    board = new C4Col[10];
}

C4Board::~C4Board(){
    delete [] board;
}

void C4Board::display(){
    cout << endl;
    for (int i = board[0].getMaxDiscs()-1; i >= -1; i--){
        for (int j = 0; j < numCols; j++){
            if (i == -1) cout << "  " << j+1 << " "; // last row display #'s
            else if (j == numCols-1)
                cout << "| " << board[j].getDisc(i) << " |\n"; // end of col
            else cout << "| " << board[j].getDisc(i) << " ";
        }
    }
}


void C4Board::play(){
    int playerSel; // determines where player puts piece
    int turn = 0; // keeps track of what turn it is
    bool playGame = true; // keeps the game going
    bool validInput; // makes sure user makes valid input
    
    // Opening phrase to be displayed once
    cout << "Welcome to connect 4! The first player who decides to go will ";
    cout << "will be marking 'X' on the board and the second will be ";
    cout << "marking 'O' on the board\n";

    while(playGame){
        display(); // display the board after every turn
        
        // instructions for each player
        validInput = false; // must be reset everytime
        
        // Player 1
        if ((turn%2)+1 == 1){ 
            cout << "\nPlayer 1, select where you want to place your piece ";
            cout << "\n(1-7) or press -1 to quit: ";
            while(!validInput){
                cin >> playerSel; // reads user input
                if (playerSel == -1) return;
                else if (playerSel > 7 || playerSel < 0)
                    cout << "\nMust be a number 1-7(or -1), try again: "; 
                else{   
                    board[playerSel-1].addDiscs('X'); // adds 'X' since P1  
                    validInput = true; 
                }
            }
        // Player 2
        } else { 
            cout << "\nPlayer 2, select where you want to place your piece ";
            cout << "\n(1-7) or press -1 to quit: "; 
            while(!validInput){
                cin >> playerSel; // reads user input
                if (playerSel == -1) return;
                else if (playerSel > 7 || playerSel < 0)
                    cout << "\nMust be a number 1-7(or -1), try again: ";
                else {
                    board[playerSel-1].addDiscs('O'); // adds 'O' since P
                    validInput = true;
                }
            }
        }
        // Checking if either player wins
        if (checkWin(board, 'X')){
            display();
            cout << "\n\nPlayer 1 wins!!, press -1 to quit the game: ";
            while(playGame){
                cin >> playerSel; 
                if (playerSel == -1) playGame = false;
            }
        }
        if (checkWin(board, 'O')){
            display();
            cout << "\n\nPLayer 2 wins!!, press -1 to quit the game: ";
            while(playGame){ 
                cin >> playerSel;
                if (playerSel = -1) playGame = false;
            }
        }
        turn++; // increase the value of turn 
    }
}

// Used to check if either player wins
bool C4Board::checkWin(C4Col board[], char player){
    int maxRow = board[0].getMaxDiscs(); // easier variable name (6)
    int consecH = 0; // how many consecutive characters horizntal
    int consecV = 0; // how many consecutive characters veritcal
    int consecD = 0; // how many consecutive characters diagonal
    
    for (int i = 0; i < maxRow; i++){
        for (int j = 0; j < numCols; j++){
            if (board[j].getDisc(i) == player){
                // if one match is found, consec for H and V should be 1
                consecH++;
                consecV++;
                consecD++;
                
                // Vertical check
                for (int k = 1; k <= maxRow-i-1; k++){
                    if (board[j].getDisc(i+k) == player) consecV++;
                    else break; // only track consecutive
                }
                for (int l = 1; l <= i; l++){
                    if (board[j].getDisc(i-l) == player) consecV++;
                    else break; // only track consecutive
                }

                // Horizonatal check
                for (int m = 1; m <= numCols-j-1; m++){
                    if (board[j+m].getDisc(i) == player) consecH++;
                    else break; // only tracks consecutive
                }
                for (int n = 1; n <= j; n++){
                    if (board[j-n].getDisc(i) == player) consecH++;
                    else break; // only tracks consecutive
                }
                
                // Diagonal check
                for (int q = 1; q <= maxRow-i-1; q++){
                    if (j+q > numCols-1) continue;
                    if (board[j+q].getDisc(i+q) == player) consecD++;
                    else break; // only tracks consecutive
                }
                for (int s = 1; s <= maxRow-i-1; s++){
                    if (j-s < 0) continue; 
                    if (board[j-s].getDisc(i+s) == player) consecD++; 
                    else break; // only tracks consecutive
                }
            }

            // final conditionals
            if (consecH == 4) return true;
            else if(consecV == 4) return true;
            else if(consecD == 4) return true;
            else{
                // reset all counters
                consecH = 0;
                consecV = 0;
                consecD = 0;
            }
        }
    }
    return false;
}

