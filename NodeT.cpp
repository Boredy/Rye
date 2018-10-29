#include "NodeT.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

NodeT::NodeT(string x) {
    def = "";
    data = x;
    left = NULL;
    right = NULL;
    parent = NULL;
    height = 1;
}

NodeT::NodeT(string x, string d) {
    def = d;
    data = x;
    left = NULL;
    right = NULL;
    parent = NULL;
    height = 1;
}

NodeT::~NodeT() {
    if ((left != NULL) || (right != NULL)) {
        cout << "deleting may leave dangling SNodes" << endl;
    }
}

void NodeT::printNode() {
    cout <<"|"<<data<<"("<<height <<"): "<<def <<endl;
}
