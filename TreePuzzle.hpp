#ifndef TREEPUZZLE_HPP_
#define TREEPUZZLE_HPP_
#include <stdlib.h>
#include <string.h>
#include "BSTY.hpp"

class treePuzzle {
    //1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26
    string alpha[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    
    BSTY *tree;
public:
    treePuzzle(int x, string sarr[], int k);
    treePuzzle(string fname,int k);
    void readFile2(string fname, int size);
    void runMine1(bool x);
    void runMine2();
    ~treePuzzle();
};



#endif /* TREEPUZZLE_HPP_ */
