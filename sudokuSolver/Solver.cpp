// Program to solve a 9x9 soduko puzzle
// Date: 2/21/2017
// Author: Will Fritz

// libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Global vairables
const int ROW_N = 9;
const int COL_N = 9;

// struct for an individual cell
struct Cell {
    int value;
    // frist value represents number 1, then 2, the the pattern continues 
    // until 9. These will be usedto see what values are still available
    // avl stands for available
    bool avl[ROW_N];
};

// function prototypes
void fillBool(Cell[ROW_N][COL_N]);
void elimRow(Cell[ROW_N][COL_N], int, int);
void elimCol(Cell[ROW_N][COL_N], int, int);
void elimGridHelp(Cell[ROW_N][COL_N], int, int);
void elimGrid(Cell[ROW_N][COL_N], int, int, int, int);
void fillValues(Cell[ROW_N][COL_N]); 
bool complete(Cell[ROW_N][COL_N]);
void display(Cell[ROW_N][COL_N]);
void singletonR(Cell[ROW_N][COL_N], int, int);
void singletonC(Cell[ROW_N][COL_N], int, int);
//void singletonG(Cell[ROW_N][COL_N], int, int, int, int);

// main funciton
int main(){
    // opening input file to populate board
    string inputFile;
    ifstream ifs;
    bool validFile = false;
    while (!validFile){
        cout << "Please enter the file name of the puzzle you wish to ";
        cout << "solve:\n";
        cin >> inputFile;
        ifs.open(inputFile.c_str());
        
        // checks for error when reading file
        if (!ifs) 
            cout << "\nError opening, try again.\n";
        else
            validFile = true;
    }
    
    // populating board
    Cell board[ROW_N][COL_N];
    int value;
    for (int i = 0; i < ROW_N; i++){
        for (int j = 0; j < COL_N; j++){
            ifs >> value;
            board[i][j].value = value;
            for (int k = 0; k < ROW_N; k++){
                board[i][j].avl[k] = true; 
            }
        }
    }
    
    //for (int i = 0; i < 30; i++){
    //display(board);
    //cout << endl;
    bool holdWhile = false;
    while (!holdWhile){
        fillBool(board);
        fillValues(board);
        holdWhile = complete(board);
    }

    display(board);
    //cout << endl;
    
    return 0;
}

// fills the the availability array for each cell
void fillBool(Cell b[ROW_N][COL_N]){
    for (int i = 0; i < ROW_N; i++){
        for (int j = 0; j < COL_N; j++){
            if (b[i][j].value != 0){ // for spots that are known
                for (int k = 0; k < ROW_N; k++)
                    b[i][j].avl[k] = false;
                b[i][j].avl[b[i][j].value-1] = true;
            }    
            else { // for spots that are unknown
                elimRow(b, i, j);
                elimCol(b, i, j);
                elimGridHelp(b, i, j);
                singletonR(b, i, j);
                singletonC(b, i, j);
            }
        }
    }
}                              

// Specifically checks all possible row values for given cell         
void elimRow(Cell b[ROW_N][COL_N], int row, int col){
    for (int n = 0; n < COL_N; n++){
        if (n == col) continue;    
        else if (b[row][n].value != 0)
            b[row][col].avl[b[row][n].value-1] = false;
    }
}

// Specifically eliminates all possible column values for given cell
void elimCol(Cell b[ROW_N][COL_N], int row, int col){
    for (int m = 0; m < COL_N; m++){
        if (m == row) continue;    
        else if (b[m][col].value != 0)
            b[row][col].avl[b[m][col].value-1] = false;
    }
}

// helper function for elimGrid and singletonG. It chooses the center point of specific grid
// depending on the location of the cell we wish to check
void elimGridHelp(Cell b[ROW_N][COL_N], int row, int col){
    if (row >= 0 && row <= 2){
        if (col >= 0 && col <= 2){
            elimGrid(b, row, col, 1, 1); // grid 1
            //singletonG(b, row, col, 1, 1);
        }
        else if (col >= 3 && col <= 5){ 
            elimGrid(b, row, col, 1, 4); // grid 2
            //singletonG(b, row, col, 1, 4);
        }
        else{ 
            elimGrid(b, row, col, 1, 7); // grid 3
            //singletonG(b, row, col, 1, 7);
        }
    }
    else if (row >= 3 && row <= 5){ 
        if (col >= 0 && col <= 2){ 
            elimGrid(b, row, col, 4, 1); // grid 4
            //singletonG(b, row, col, 4, 1);
        }
        else if (col >= 3 && col <= 5){ 
            elimGrid(b, row, col, 4, 4); // grid 5
            //singletonG(b, row, col, 4, 4);
        }
        else{ 
            elimGrid(b, row, col, 4, 7); // grid 6
            //singletonG(b, row, col, 4, 7);
        }
    }
    else {
        if (col >= 0 && col <= 2){ 
            elimGrid(b, row, col, 7, 1); // grid 7
            //singletonG(b, row, col, 7, 1);
        }
        else if (col >= 3 && col <= 5){
            elimGrid(b, row, col, 7, 4); // grid 8
            //singletonG(b, row, col, 7, 4);
        }
        else{ 
            elimGrid(b, row, col, 7, 7); // grid 9
            //singletonG(b, row, col, 7, 7);
        }
    }
}

// Specifically eliminates all possible grid values for given cell
void elimGrid(Cell b[ROW_N][COL_N], int row, int col, int centx, int centy){
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            if (b[centx+i][centy+j].value != 0){ 
                if ((centx+i != row) || (centy+j != col))
                    b[row][col].avl[b[centx+i][centy+j].value-1] = false;
            }
        }
    }
}

// uses the availability vector to fill in values on the board
void fillValues(Cell b[ROW_N][COL_N]){
    int counter;
    int value; // will be used to populate correct cell
    for (int i = 0; i < ROW_N; i++){
        for (int j = 0; j < COL_N; j++){
            counter = 0;
            for (int k = 0; k < ROW_N; k++){
                if (b[i][j].avl[k]){ 
                    counter++;
                    value = k + 1;
                }
            }
            if (counter == 1) b[i][j].value = value;
            counter = 0;
        }
    }
}
            
// Checks if all values are filled in 
bool complete(Cell b[ROW_N][COL_N]){
    for (int i = 0; i < ROW_N; i++){
        for (int j = 0; j < COL_N; j++){
            if (b[i][j].value == 0) return false;
        }
    }
    return true;
}

void display(Cell b[ROW_N][COL_N]){
    for (int i = 0; i < ROW_N; i++){
        for (int j = 0; j < COL_N; j++){
            cout << b[i][j].value << ' ';
        }
        cout << endl;
    }
} 

void singletonR(Cell b[ROW_N][COL_N], int row, int col){
    int pos; // keeps position of something available
    for (int i = 0; i < ROW_N; i++){
        if (b[row][col].avl[i]){
            pos = i;
            for (int j = 0; j < ROW_N; j++)
                if (b[j][col].avl[i] && j != row) pos = -1;
            if (pos != -1) b[row][col].value = pos + 1;
        }
    }
}

void singletonC(Cell b[ROW_N][COL_N], int row, int col){
    int pos; // keeps position of something available
    for (int i = 0; i < COL_N; i++){
        if (b[row][col].avl[i]){
            pos = i;
            for (int j = 0; j < COL_N; j++)
                if (b[row][j].avl[i] && j != col) pos = -1;
            if (pos != -1) b[row][col].value = pos + 1;
        }
    }
}

/*
// Specifically eliminates all possible grid values for given cell
void singletonG(Cell b[ROW_N][COL_N], int row, int col, int centx, int centy){
    int pos; // keeps position of something available
    for (int m = 0; m < ROW_N; m++){
        if (b[row][col].avl[m]){
            pos = m;
            for (int i = -1; i < 2; i++){
                for (int j = -1; j < 2; j++){
                    if (b[centx+i][centy+j].avl[i]){ 
                         if ((centx+i != row) || (centy+j != col))
                            pos = -1;
                    }
                }
            }
            if (pos != -1) b[row][col].value = pos + 1;
        }            
    }
}
*/

            








