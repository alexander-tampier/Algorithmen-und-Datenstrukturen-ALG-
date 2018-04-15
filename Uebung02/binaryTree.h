//
// Created by Alexander Tampier on 15.04.18.
//

#ifndef UEBUNG02_FILEINPUT_H
#define UEBUNG02_FILEINPUT_H


#include <fstream>
#include <iostream>
#include <vector>
#include "tnode.h"

class binaryTree {
private:
    tnode *head;

public:
    static void readFromFile(const char *path) {
        std::vector<int> numbers;
        std::ifstream file(path);
        int number;

        if (!file)
            throw "Import-error";

        while (file >> number)
            numbers.push_back(number);

        for (int &number:numbers)
            std::cout << number << std::endl;
    }

};


#endif //UEBUNG02_FILEINPUT_H
