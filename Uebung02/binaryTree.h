//
// Created by Alexander Tampier on 15.04.18.
//

#ifndef UEBUNG02_FILEINPUT_H
#define UEBUNG02_FILEINPUT_H


#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include "tnode.h"

using namespace std;

class binaryTree {
public:

    binaryTree(const vector<int> &keys) : keys(keys) {
        this->root = new tnode();
        this->keys = keys;

        initialize();
    }

    virtual ~binaryTree() {
        root = nullptr;
        delete root;
    }

    void initialize() {
        this->root->setKey(keys.front());
        this->keys.erase(keys.begin());

        for (int &key:this->keys) {
            insert(this->root, key);
        }
    }

    struct tnode *newNode(int key) {
        struct tnode *temp = new tnode;
        temp->setKey(key);
        temp->setLeft(NULL);
        temp->setRight(NULL);

        return temp;
    };

    /*
     * root: cached root at current position
     * key: given value to insert into tree
     */
    void insert(tnode *current, int key) {
        if (current->getKey() > key) {
            if(current->getLeft()!=NULL)
                insert(current->getLeft(), key);
            else
                current->setLeft(newNode(key));
        } else if (current->getKey() < key) {
            if(current->getRight()!=NULL)
                insert(current->getRight(), key);
            else
                current->setRight(newNode(key));
        }
    }

    void postorder(tnode *p, int indent) {
        if (p != NULL) {
            if (p->getRight()) {
                postorder(p->getRight(), indent + 4);
            }
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (p->getRight()) std::cout << " /\n" << std::setw(indent) << ' ';
            std::cout << p->getKey() << "\n ";
            if (p->getLeft()) {
                std::cout << std::setw(indent) << ' ' << " \\\n";
                postorder(p->getLeft(), indent + 4);
            }
        }
    }

    static vector<int> readFromFile(const char *path) {
        vector<int> numbers;
        ifstream file(path);
        int number;

        if (!file)
            throw "Import-error";

        while (file >> number)
            numbers.push_back(number);

        return numbers;
    }

    tnode *getHead() const {
        return root;
    }

private:
    tnode *root;
    vector<int> keys;

};


#endif //UEBUNG02_FILEINPUT_H
