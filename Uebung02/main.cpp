#include <iostream>
#include "binaryTree.h"

int main() {
    std::string path;
    std::cout << "filename: ";
    std::cin >> path;
    binaryTree::readFromFile(path.c_str());
    return 0;
}