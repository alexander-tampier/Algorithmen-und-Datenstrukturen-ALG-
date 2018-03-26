//
// Created by Alexander Tampier on 26.03.18.
//

#ifndef UEBUNG01_HASHCODE_H
#define UEBUNG01_HASHCODE_H

#include <iostream>

// Default hash function class
template <typename K>
struct HashCode{
    unsigned int operator()(const K &key) const
    {
        char *myString = const_cast<char *>(key.c_str());

        int n = sizeof(myString) / sizeof(myString[0]) - 1;

        int hash = 0;
        //hash = s[0] + 31^(n-1) + s[1] + 31^(n-2) + ... + s[n-1]
        //hash += static_cast<int>(myString[i])*pow(31, n-(i+1));
        for (int i = 0; i < n; i++) {
            hash = 31 * hash + (int) myString[i];
        }

        return hash;
    }
};

#endif //UEBUNG01_HASHCODE_H
