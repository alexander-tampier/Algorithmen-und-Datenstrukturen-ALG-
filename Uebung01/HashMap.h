//
// Created by Alexander Tampier on 03.03.18.
//

#ifndef UEBUNG01_HASHMAP_H
#define UEBUNG01_HASHMAP_H

#include <iostream>
#include <cstddef>
#include "HashEntry.h"

const int TABLE_SIZE = 128;

template<typename K, typename V>
class HashMap {
private:
    HashEntry<K, V> **table;

public:
    //Constructor for initializing table with hashEntry array .. contains entries -> aktien
    HashMap() {
        table = new HashEntry<K, V> *[TABLE_SIZE]();
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }
    //Destructor for destroying all entries
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }

    //get a related value for a specific key and modify memory address
    V get(const K &key) {
        int hash = (hashCode(const_cast<char*>(key.c_str()))%TABLE_SIZE);

        while (table[hash] != NULL && table[hash]->getKey() != key) {
            //Lineares Sondieren
            hash = (hash + 1) % TABLE_SIZE;
        }

        if (table[hash] == NULL)
            return 0;
        else
            return table[hash]->getValue();
    }

    //insert key, value to map
    void put(const K &key, const V &value) {
        int hash = (hashCode(const_cast<char*>(key.c_str()))%TABLE_SIZE);
        //int hash = (key % TABLE_SIZE);

        while (table[hash] != NULL && table[hash]->getKey() != key) {
            //Lineares Sondieren
            hash = (hash + 1) % TABLE_SIZE;
        }

        if (table[hash] != NULL)
            delete table[hash];

        table[hash] = new HashEntry<K, V>(key, value);

    }

    int hashCode(char *myString){
        int n = sizeof(myString)/sizeof(char)-1;

        int hash = 0;
        //hash = s[0] + 31^(n-1) + s[1] + 31^(n-2) + ... + s[n-1]
        //hash += static_cast<int>(myString[i])*pow(31, n-(i+1));
        for (int i = 0; i<n; i++) {
            hash = 31*hash + (int)myString[i];
        }

        return hash;
    }

};


#endif //UEBUNG01_HASHMAP_H
