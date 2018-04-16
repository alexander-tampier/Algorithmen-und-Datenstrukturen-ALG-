#include <iostream>
#include "algo/BinaryTree.h"

int main() {
    std::string path;
    std::cout << "filename: ";
    std::cin >> path;
    vector<int> values = BinaryTree::readFromFile(path.c_str());
    BinaryTree binaryTree(values);
    binaryTree.printTree(binaryTree.getRoot(),0);
    binaryTree.getBalance(binaryTree.getRoot());
    cout<<binaryTree<<endl;

    return 0;
}