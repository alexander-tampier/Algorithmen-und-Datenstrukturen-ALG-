#include <iostream>
#include "binaryTree.h"

int main() {
    std::string path;
    std::cout << "filename: ";
    std::cin >> path;
    vector<int> values = binaryTree::readFromFile(path.c_str());
    binaryTree binaryTree(values);

    binaryTree.postorder(binaryTree.getHead(), 0);

    return 0;
}