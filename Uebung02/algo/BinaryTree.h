//
// Created by Alexander Tampier on 15.04.18.
//

#ifndef UEBUNG02_FILEINPUT_H
#define UEBUNG02_FILEINPUT_H
#define COUNT 10

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Node.h"

using namespace std;

class BinaryTree {
public:

    BinaryTree(const vector<int> &keys) : keys(keys) {
        this->root = new Node();
        this->keys = keys;
        this->avl = true;

        initialize();
    }

    virtual ~BinaryTree() {
        if (root) delete root;
    }

    void initialize() {
        this->root->setKey(keys.front());
        this->keys.erase(keys.begin());

        for (int &key:this->keys) {
            insert(this->root, key);
        }
    }

    struct Node *newNode(int key) {
        struct Node *temp = new Node;
        temp->setKey(key);
        temp->setLeft(NULL);
        temp->setRight(NULL);

        return temp;
    };

    /*
     * root: cached root at current position
     * key: given value to insert into tree
     */
    void insert(Node *current, int key) {
        //check if node to insert is greater than already existing key node
        if (current->getKey() > key) {
            //check if the left node from the current node is not null
            // .. if so then check to insert the node related to this left node
            if (current->getLeft() != NULL)
                insert(current->getLeft(), key);
                //if node is null insert it to the left side from the given current node
            else
                current->setLeft(newNode(key));
            //check if node to insert is less than already existing key node
        } else if (current->getKey() < key) {
            //check if the right node from the current node is not null
            // .. if so then check to insert the node related to this right node
            if (current->getRight() != NULL)
                insert(current->getRight(), key);
                //if node is null insert it to the right side from the given current node
            else
                current->setRight(newNode(key));
        }
    }

    // compute height of the tree
    int getHeight(Node *root) {
        if (root == NULL)
            return 0;

        // find the height of each subtree
        int leftHeight = getHeight(root->getLeft());
        int rightHeight = getHeight(root->getRight());

        return 1 + max(leftHeight, rightHeight);
    }

    //bal(k) = h(rechter Teilbaum) - h(linker Teilbaum)
    int getBalance(Node *root) {
        if (root == NULL)
            return 0;
        else {
            int rightBalance = getBalance(root->getRight());
            int leftBalance = getBalance(root->getLeft());
        }

        int balance = getHeight(root->getRight()) - getHeight(root->getLeft());

        if (balance > 1 || balance < -1) {
            cout << "bal(" << root->getKey() << ") = " << balance << " (AVL violation!)" << endl;
            this->avl = false;
        } else
            cout << "bal(" << root->getKey() << ") = " << balance << endl;

        return balance;
    }

    // Returns maximum value in a given Binary Tree
    int findMax(Node *root) {
        // Base case
        if (root == NULL)
            return INT_MIN;

        // Return maximum of 3 values:
        // 1) Root's data 2) Max in Left Subtree
        // 3) Max in right subtree
        int result = root->getKey();
        int leftResult = findMax(root->getLeft());
        int rightResult = findMax(root->getRight());

        if (leftResult > result)
            result = leftResult;
        if (rightResult > result)
            result = rightResult;

        return result;
    }

    // Returns minimum value in a given Binary Tree
    int findMin(Node *root) {
        // Base case
        if (root == NULL)
            return INT_MAX;

        // Return minimum of 3 values:
        // 1) Root's data 2) Max in Left Subtree
        // 3) Max in right subtree
        int currentResult = root->getKey();
        int leftResult = findMin(root->getLeft());
        int rightResult = findMin(root->getRight());

        if (leftResult < currentResult)
            currentResult = leftResult;
        if (rightResult < currentResult)
            currentResult = rightResult;

        return currentResult;
    }

    /*
     * Get the arithmetic mean of the BST
     */
    double getAverage(Node *root){
        return (double)sum(root)/getElements(root);
    }

    /*
     * Get the number of elements the BST has
     */
    int getElements(Node *current){
        if(!current) return 0;
        return 1 + getElements(current->getRight()) + getElements(current->getLeft());
    }

    /*
     * Calculates the sum from the given node element
     */
    int sum(Node *current){
        if(!current) return 0;
        return current->getKey() + sum(current->getRight()) + sum(current->getLeft());
    }

    void printTree(struct Node* curr,int depth)
    {

        int i;
        if(curr==NULL)return;
        printf("\t");
        for(i=0;i<depth;i++)
            if(i==depth-1)
                printf("%s\u2014\u2014\u2014",rec[depth-1]?"\u0371":"\u221F");
            else
                printf("%s   ",rec[i]?"\u23B8":"  ");
        printf("%d\n",curr->getKey());
        rec[depth]=1;
        printTree(curr->getLeft(),depth+1);
        rec[depth]=0;
        printTree(curr->getRight(),depth+1);
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

    friend ostream &operator<<(ostream &os, BinaryTree &tree) {
        string avl = tree.isAvl() ? "yes" : "no";
        os << "avl: " << avl << endl;
        os << "min: " << tree.findMin(tree.getRoot())<<endl;
        os << "max: " << tree.findMax(tree.getRoot())<<endl;
        os << "average: " << tree.getAverage(tree.getRoot())<<endl;
        return os;
    }

    Node *getRoot() const {
        return root;
    }

    bool isAvl() const {
        return avl;
    }

private:
    bool avl;
    Node *root;
    vector<int> keys;
    int rec[1000006];
};


#endif //UEBUNG02_FILEINPUT_H
