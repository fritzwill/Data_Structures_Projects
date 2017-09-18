// Given a undirected graph (inputed using distance matrix from stdin) the
// program is suppossed to output the total weight of the minimum spanning
// tree and then the edges of the minnimum spanning tree represented by
// the two vertices
// Date: 5/5/2017
// Author: Will Fritz

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>
#include <list>
#include <limits.h>
#include <stdio.h>

using namespace std;

int main(){
    string alph = "ABCDEFGHIJKLMONPQRSTUVWXYZ";
    string line;
    int weight, nEdges;
    getline(cin, line); // get first line
    bool readLine = true;
    while (readLine){ // run until readLine is false
        // read into dist matrix
        istringstream ipp(line);
        ipp >> nEdges; // the first line is just a number
        int dist[nEdges][nEdges];
        for (int i = 0; i < nEdges; i++){
            getline(cin, line);
            istringstream iss(line); // to get each word
            for (int j = 0; j < nEdges; j++){
                iss >> weight;
                if (weight == -1) dist[i][j] = 0; // no edge
                else dist[i][j] = weight;
            }
        }
        
        // finding smallest weight
        
        int mst[nEdges];
        int key[nEdges]; // for min weight 
        bool visited[nEdges]; // vetices not in MST
        
        // initialize
        for (int i = 0; i < nEdges; i++){
            key[i] = INT_MAX;
            visited[i] = false;
        }
        
        key[0] = 0;
        mst[0] = -1;

        for (int i = 0; i < nEdges - 1; i++){
            // want the min key of vertex that hasn't been used
            int min = INT_MAX;
            int minIndex;
            for (int j = 0; j < nEdges; j++){
                if (!visited[j] && key[j] < min){
                    min = key[j];
                    minIndex = j;
                }
            }
            visited[minIndex] = true;
            for (int j = 0; j < nEdges; j++){
                if (dist[minIndex][j] && !visited[j] && dist[minIndex][j] < key[j]){
                    mst[j] = minIndex;
                    key[j] = dist[minIndex][j];
                }
            }
            
        }
        int tot = 0;
        for (int i = 1; i < nEdges; i++) tot += dist[i][mst[i]];
        cout << tot << endl;
        list<pair<char, char>> edges;
        for (int i = 1; i < nEdges; i++) 
            edges.push_back({alph[mst[i]], alph[i]});
        for (auto &it : edges){
            if (it.first > it.second){
                int tmp = it.first;
                it.first = it.second;
                it.second = tmp;
            }
        }
        edges.sort();
        for (auto &it : edges) cout << it.first << it.second << endl;
        
        // checks to see if theres more to input
        if (getline(cin, line)) cout << endl;
        else readLine = false;
    }
    return 0;
}
            
        
