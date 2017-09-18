// Takes in info about a graph in the form:
//              NEDGES
//              SRC1 DST1
//              ...
//              NPATHS
//              SRC1 DST1
//              ...
// and outputs if the path is possible for all paths given after NPATHS
// Date: 4/26/2017
// Author: Will Fritz

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

// Adjacency list for representation of graph
typedef map<string, vector<string>> Graph;

// prototypes
bool isPath(string, string, Graph);
bool isMarked(list<string>, string);

int main (){
    int nEdges, nPaths, nGraphs;
    string line, src, dest;
    nGraphs = 0;
    // take in all input (multiple graphs)
    while (getline(cin, line)){
        if (nGraphs >= 1) cout << endl; // we don't want a leading newline, but we still want one btween graphs
        nGraphs++;
        nEdges = stoi(line);
        Graph newGraph;
        // populate graph
        for (int i = 0; i < nEdges; i++){
            getline(cin, line);
            istringstream iss(line); // so we can get each word of the line
            iss >> src;
            iss >> dest;
            newGraph[src].push_back(dest);
        }
        getline(cin, line);
        nPaths = stoi(line);
        // check given paths
        for (int i = 0;  i < nPaths; i++){
            getline(cin, line);
            istringstream iss(line);
            iss >> src;
            iss >> dest;
            if (isPath(src, dest, newGraph)){
                cout << "In Graph " << nGraphs << " there is a path from " << src << " to " << dest << endl;
            }
            else {
                cout << "In Graph " << nGraphs << " there is no path from " << src << " to " << dest << endl;
            }
        }
        getline(cin, line); // next nEdges
    }
}

// returns true if given source and destination have a path between eachother, false otherwise
// Utilizes a depth-first search                
bool isPath(string src, string dest, Graph g){
    string temp;
    list<string> marked;
    list<string> frontier;
    frontier.push_back(src);
    while (!frontier.empty()){
        temp = frontier.front();
        frontier.pop_front();
        if (isMarked(marked, temp)) continue;
        if (temp == dest) return true;
        marked.push_back(temp);
        for (auto it = g[temp].begin(); it != g[temp].end(); it++){
            frontier.push_back(*it);
        }
    }
    return false;
}

// out puts true if vector passed in contains string passed in
bool isMarked(list<string> marked, string check){
    for (auto it = marked.begin(); it != marked.end(); it++){
        if (*it == check) return true;
    }
    return false;
}
    
