//
//  NodeT.hpp
//  TREE_LAB
//
//  Created by D@ on 10/19/18.
//  Copyright © 2018 Max Luu. All rights reserved.
//

#ifndef NodeT_hpp
#define NodeT_hpp

#include <string>
using namespace std;

class NodeT {
    friend class BSTY;

public:
    string def;
    string data;
    int height;
    NodeT *left;
    NodeT *right;
    NodeT *parent;
    
    NodeT(string x);
    NodeT(string x, string d);
    ~NodeT();
    void printNode();
};
#endif /* NodeT_hpp */
