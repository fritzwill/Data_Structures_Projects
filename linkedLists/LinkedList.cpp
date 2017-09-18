// Creating a linked list data structure using structs and templating
// Date: 2/7/2017
// Author: Will Fritz


#include <iostream>
#include <string>
using namespace std;

template <typename T> // Templated struct
struct Node {
    T value;
    Node<T> * next;
    Node<T>(T val) { value = val; next = NULL;}
};

template <typename T>
struct List {
    Node<T> * head;
    void pushFront(const T);
    void print();
    List<T> addNumberLists(List<T> &, List<T> &);
    List();
    ~List();
};

// Constructor
template <typename T>
List<T>::List(){
    head = NULL;
}

// Destructor
template <typename T>
List<T>::~List(){
    Node<T> * helper;
    Node<T> * helperNext;
    helper = head;
    while (helper != NULL){
        helperNext = helper->next;
        delete helper;
        helper = helperNext;
    }
    head = NULL;
}

// adds a node to the fron of the list
template <typename T>
void List<T>::pushFront(const T b){
    //cout << "push front   " << b << endl;
    Node<T> * temp = new Node<T>(b);
    temp->next = head;
    head = temp;
    //cout << "push front2 :) " << endl;
}

// print function that prints the head first
template <typename T>
void List<T>::print(){
    Node<T> * helper;
    helper = head;
    while (helper != NULL){
        cout << helper->value;
        helper = helper->next;
    }
    cout << endl;
}


// main function to utilize templated LinkedList class. This driver uses
// functions from the List struct

// prototype for function
template <typename T>
List<T> addNumberLists(List<T> &, List<T> &);

int main() {
    string numString1 = "";
    string numString2 = "";
    char tempS1, tempS2;
    
    while (cin >> numString1 >> numString2) {
        List<int> a;
        List<int> b;
        //cout << "String 1: " << numString1 << endl;
        //cout << "String 2: " << numString2 << endl; 
        // populating and printing for List a
        for (int i = 0; i < numString1.size(); i++){
            tempS1 = numString1[i];
            //cout << " a " << tempS1 << endl;
            a.pushFront(tempS1 - '0');
            //a.pushFront(5);
            //cout << "end of for1" << endl;
        }
        
        //cout << "Numer one: ";
        //a.print();
        
        int bsize = numString2.size();
        
        //cout << "size of b: " <<  bsize << endl;        
        // populating and printing for List b
        for (int j=0; j < bsize; j++){
            tempS2 = numString2[j];
            //cout << " b " << tempS2 << endl;
            b.pushFront(tempS2 - '0');
            //b.pushFront(2);
            //cout << "end of for2" << endl;
        }

        //cout << "Number 2: ";
        //b.print();
        List<int> sum = addNumberLists(a, b);
        sum.print();
        //cout << "end of while" << endl;
    }
}

// takes in two lsits and returns a list that is the sum of the two lists
// entered
template <typename T>
List<T> addNumberLists(List<T> &a, List<T> &b){
    // initializing helper pointers
    Node<T> * helperA;
    Node<T> * helperB;
    helperA = a.head;
    helperB = b.head;
    T helperVal = 0;
    T helperRem = 0;

    List<T> output; // new output List

    while (helperA != NULL || helperB != NULL){
        // check for NULL
        if (helperA == NULL) helperVal += 0;
        else helperVal += helperA->value;

        if (helperB == NULL) helperVal += 0;
        else helperVal += helperB->value;
        
        // find remainder and value
        helperRem = helperVal/10;
        helperVal = helperVal%10;

        output.pushFront(helperVal);
        helperVal = helperRem; // reset with remainder
        
        // set to the next node 
        if (helperA != NULL)  helperA = helperA->next;
        if (helperB != NULL)  helperB = helperB->next;
    }
    if (helperRem != 0) output.pushFront(helperRem);
    return output;
}
      
