#include <iostream>
#include "BinaryTree.h"

int main() {
    std::string path;
    std::cout << "filename: ";
    std::cin >> path;
    vector<int> values = BinaryTree::readFromFile(path.c_str());
    BinaryTree binaryTree(values);
    //binaryTree.print2D(binaryTree.getRoot());
    binaryTree.getBalance(binaryTree.getRoot());
    cout<<binaryTree<<endl;

    return 0;
}