//
// Created by Alexander Tampier on 15.04.18.
//

#ifndef UEBUNG02_FILEINPUT_H
#define UEBUNG02_FILEINPUT_H


#include <fstream>
#include <iostream>
#include <vector>
#include "tnode.h"

using namespace std;

class binaryTree {
public:

    binaryTree(const vector<int> &keys) : keys(keys) {
        this->keys = keys;
        this->head->setKey(keys.front());
        this->keys.erase(keys.begin());
    }

    virtual ~binaryTree() {
        head = nullptr;
        delete head;
    }

    struct tnode* newNode(int key)
    {
        struct tnode* temp = new tnode;
        temp->setKey(key);
        temp->setLeft(NULL);
        temp->setRight(NULL);

        return temp;
    };

    /*
     * head: cached head at current position
     * key: given value to insert into tree
     */
    void insert(tnode *head, int key){

        if(head==NULL){
            newNode(key);
        }
        
        if(this->head->getKey() > key){
            insert(this->head->getLeft(), key);
        }else{
            insert(this->head->getRight(), key);
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

private:
    tnode *head;
    vector<int> keys;

};


#endif //UEBUNG02_FILEINPUT_H
