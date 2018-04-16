//
// Created by Alexander Tampier on 15.04.18.
//

#ifndef UEBUNG02_TNODE_H
#define UEBUNG02_TNODE_H

using namespace std;

class Node {

public:

    Node() {
        key = 0;
        left = NULL;
        right = NULL;
    }

    virtual ~Node() {
        if(left) delete left;
        if(right) delete right;
    }

    int getKey() const {
        return key;
    }

    void setKey(int key) {
        Node::key = key;
    }

    Node *getLeft() const {
        return left;
    }

    void setLeft(Node *left) {
        Node::left = left;
    }

    Node *getRight() const {
        return right;
    }

    void setRight(Node *right) {
        Node::right = right;
    }

private:
    int key;
    Node *left;
    Node *right;
};


#endif //UEBUNG02_TNODE_H
