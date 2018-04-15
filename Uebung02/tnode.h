//
// Created by Alexander Tampier on 15.04.18.
//

#ifndef UEBUNG02_TNODE_H
#define UEBUNG02_TNODE_H

#endif //UEBUNG02_TNODE_H


class tnode {

public:

    tnode() {
        key = 0;
        left = nullptr;
        right = nullptr;
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
