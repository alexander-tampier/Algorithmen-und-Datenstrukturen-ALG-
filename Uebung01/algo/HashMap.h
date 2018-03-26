//
// Created by Alexander Tampier on 26.03.18.
//

#ifndef UEBUNG01_HASHMAP_H
#define UEBUNG01_HASHMAP_H

#include <iostream>
#include <cstddef>
#include "HashEntry.h"
#include "HashCode.h"

constexpr unsigned int TABLE_SIZE = 128;

template<typename K, typename V, typename F = HashCode<K>>
class HashMap {

public:
    //Constructor for initializing table with hashEntry array .. contains entries -> aktien
    HashMap(unsigned int hashSize = TABLE_SIZE) : hashSize(hashSize){
        table = new HashEntry<K, V> *[hashSize]();
        for (int i = 0; i < hashSize; i++)
            table[i] = NULL;
    }

    //Destructor for destroying all entries
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }

    //insert key, value to map
    void put(const K &key, const V &value) {
        unsigned int hash = 13 % hashSize;

        quadraticProbing(key, hash);

        if (table[hash] != NULL)
            delete table[hash];

        table[hash] = new HashEntry<K, V>(key, value);

    }

    //get a related value for a specific key and modify memory address
    V get(const K &key) {
        unsigned int hash = 13 % hashSize;

        quadraticProbing(key, hash);

        if (table[hash] == NULL)
            return 0;
        else
            return table[hash]->getValue();
    }

    bool erase(const K &key) {
        unsigned int hash = 13 % hashSize;
        quadraticProbing(key, hash);

        // key not found
        if (table[hash] == NULL)
            return false;

        //TODO - Compression, free allocated memory ..

        table[hash] = NULL;

        return true;
    }
    
    unsigned int quadraticProbing(const K &key, unsigned int &hash) const {
        int i = 1;
        while (table[hash] != NULL && table[hash]->getKey() != key) {
            //Quadratic probing
            hash = (hash + i*i) % hashSize;
            i++;
        }
        return hash;
    }

private:
    HashEntry<K, V> **table;
    F hashFunc;
    const unsigned int hashSize;
};

#endif //UEBUNG01_HASHMAP_H
