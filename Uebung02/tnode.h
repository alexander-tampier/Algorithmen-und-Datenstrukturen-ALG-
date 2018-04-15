//
// Created by Alexander Tampier on 15.04.18.
//

#ifndef UEBUNG02_TNODE_H
#define UEBUNG02_TNODE_H

using namespace std;

class tnode {

public:

    tnode() {
        key = 0;
        left = NULL;
        right = NULL;
    }

    int getKey() const {
        return key;
    }

    void setKey(int key) {
        tnode::key = key;
    }

    tnode *getLeft() const {
        return left;
    }

    void setLeft(tnode *left) {
        tnode::left = left;
    }

    tnode *getRight() const {
        return right;
    }

    void setRight(tnode *right) {
        tnode::right = right;
    }

private:
    int key;
    tnode *left;
    tnode *right;
};


#endif //UEBUNG02_TNODE_H
