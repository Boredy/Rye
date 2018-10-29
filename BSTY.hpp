//
//  BSTY.hpp
//  TREE_LAB
//
//  Created by D@ on 10/19/18.
//  Copyright © 2018 Max Luu. All rights reserved.
//

#ifndef BSTY_hpp
#define BSTY_hpp
#include "NodeT.hpp"
#include <string>
using namespace std;

class BSTY {
    NodeT *root;
    bool mine = true;
    string alpha[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

public:
    BSTY();
    bool insertit(string x);
    bool insertit(string x, string d);
    void adjustHeights(NodeT *n);
    void printTreeIO();
    void printTreeIO(NodeT *n);
    void printTreePre();
    void printTreePre(NodeT *n);
    void printTreePost();
    void printTreePost(NodeT *n);
    void myPrint();
    void myPrint(NodeT *n);
    NodeT *find(string x);
    NodeT *rotateRight(NodeT *n);
    NodeT *rotateLeft(NodeT *n);
    int findBalance(NodeT *n);
    
    //Extra Credit
    void myPrintEC();
    void myPrintEC(NodeT *n);
    bool remove(string s);
    void removeRoot();
    void remove1(NodeT *n);
    void remove2(NodeT *n);
    void remove3(NodeT *n);
    NodeT *findMin(NodeT *n);
};

#endif /* BSTY_hpp */
