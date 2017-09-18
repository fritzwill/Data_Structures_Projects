// treap.cpp: Treap Map

#include "map.h"

#include <climits>
#include <random>

// Prototypes - helper functions ------------------------------------------------------------------

int getMinTreeHeightHelp(Node *node);
int getMaxTreeHeightHelp(Node *node);
void preOrderTraversalHelp(Node *node);
Node *insert_t(Node *node, const std::string &key, const std::string &value);
Node *rotateRight(Node *node);
Node *rotateLeft(Node *node);
Node *search_t(Node *node, const std::string &key);
extern void dump_r(Node *node, std::ostream &os, DumpFlag flag);
int get_random();

// Methods ---------------------------------------------------------------------

void            TreapMap::insert(const std::string &key, const std::string &value) {
    root = insert_t(root, key, value);
    
}

const Entry     TreapMap::search(const std::string &key) {
    auto result = search_t(root, key);
    return (result == nullptr ? NONE : result->entry);
}

void            TreapMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root, os, flag);
}

int             TreapMap::getMaxTreeHeight(){
    return getMaxTreeHeightHelp(root);
}


int             TreapMap::getMinTreeHeight(){
    return getMinTreeHeightHelp(root);
}

void            TreapMap::preOrderTraversal(){
    preOrderTraversalHelp(root);
}

// Internal Functions ----------------------------------------------------------

// helper for recursive minHeight
int getMinTreeHeightHelp(Node *node){
    if (node == nullptr) return 0;
    // base case 
    if (node->left == nullptr && node->right == nullptr) return 1;
        
    // depth of right
    if (node->left == nullptr) 
        return (getMinTreeHeightHelp(node->right) + 1);
        
    // depth of left
    if (node->right == nullptr)
        return (getMinTreeHeightHelp(node->left) + 1);

    return std::min(getMinTreeHeightHelp(node->left),getMinTreeHeightHelp(node->right)) + 1;
}

// helper for recursive maxHeight
int getMaxTreeHeightHelp(Node *node){
    if (node == nullptr) return 0;
    else {
        // depth of left subtree
        int lSize = getMaxTreeHeightHelp(node->left);
        // depth of right subtree
        int rSize = getMaxTreeHeightHelp(node->right);
        
        // compare the values and pick larger
        if (lSize > rSize) return (lSize + 1);
        else return (rSize + 1);
    }
}

// helper function to for recursive pre order traversal
void preOrderTraversalHelp(Node *node){
    if (node == nullptr) return; // exit if empty
    std::cout << node->entry.first << ' '; // print
    preOrderTraversalHelp(node->left); // left subtree
    preOrderTraversalHelp(node->right); // right subtree
}

// helper function for recursive insert
Node *insert_t(Node *node, const std::string &key, const std::string &value){    
    // if null node, allocate for new node and return it
    if (node == nullptr) {
        return new Node{Entry(key, value), get_random(), nullptr, nullptr};
    }
    
    // replace if equal
    if (node->entry.first == key) {
        node->entry.second = value;
        return node;
    } 

    // key smaller than node
    if (key < node->entry.first) {
        // placed in left subtree
        node->left = insert_t(node->left, key, value);
        // chekc if heap needs to be fixed
        if (node->left->priority > node->priority)
            node = rotateRight(node);
    }
    // key greater than node
    else { 
        // placed in right subtree
        node->right = insert_t(node->right, key, value);
        // check if heap needs to be fixed
        if (node->right->priority > node->priority)
            node = rotateLeft(node);
    }
    // return the update node
    return node;
}

// helper function to right rotate subtree
Node *rotateRight(Node *node){
    Node *c = node->left;
    Node *T2 = c->right;
    
    // Rotation
    c->right = node;
    node->left = T2;
    return c; // new root
}

// helper function to left rotate subtree
Node *rotateLeft(Node *node){
    Node *c = node->right;
    Node *T2 = c->left;
    
    // Rotation
    c->left = node;
    node->right = T2;
    return c; // new root
}

// helper for recursive search  
Node *search_t(Node *node, const std::string &key){
    if (node == nullptr) {
        return nullptr;
    }
    
    if (node->entry.first == key) {
        return node;
    }
    
    if (node->entry.first > key) {
        return search_t(node->left, key);
    } else {
        return search_t(node->right, key);
    }
}

// random number generator
int get_random(){
    static std::random_device rd;
    static std::default_random_engine g(rd());
    static std::uniform_int_distribution<> d(1, INT_MAX);
    return d(g);
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
