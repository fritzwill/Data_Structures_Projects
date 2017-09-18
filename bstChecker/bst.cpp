// This program creates a binary tree given input from std input. 
// Then, check whether that tree is a binary search tree. It should do 
// this until there is no more input
// Author: Will Fritz
// Date: 3/2/2017

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// functions
bool checkTree(vector<int>);
void output(bool, int);

int main(){
    int fill, treeCount;
    treeCount = 1;
    vector<int> tree;
    string line;
    while (getline(cin, line)){ // until ctrl-d
        istringstream ss(line);
        ss >> fill;
        //cout << "throw away: " << fill << endl;
        while (ss >> fill){
            tree.push_back(fill); // populate vector
            //cout << "fill: " << fill << endl;
        }
        output(checkTree(tree), treeCount);
        tree.clear(); // clear vector so next line can be used
        treeCount++;
    }
    
}

bool checkTree(vector<int> t){
    int root, index, left, right;
    index = 0;
    for (auto it = t.begin(); it != t.end(); it++){
        //cout << "vector: " << *it << endl;
        root = *it;
        if (root == -1){
            index++;
            continue;
        }
        left = 2*index + 1;
        right = 2*index + 2;
        if (left + 1 > t.size()){
            index++;
            continue;
        }
        if (root < t[left]) return false;
        //cout << "Passed ffirst\n";
        if (right + 1 > t.size()){
            index++;
            continue;
        }
        if (root >= t[right] && t[right] != -1) return false;
        index++;
    }
    return true;
}

void output(bool b, int treeCount){
    if (b) cout << "Tree " << treeCount << " is a BST\n";
    else cout << "Tree " << treeCount << " is not a BST\n";
} 
