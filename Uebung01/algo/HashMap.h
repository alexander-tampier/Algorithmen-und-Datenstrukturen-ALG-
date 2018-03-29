//
// Created by Alexander Tampier on 26.03.18.
//

#ifndef UEBUNG01_HASHMAP_H
#define UEBUNG01_HASHMAP_H

#include <iostream>
#include <cstddef>
#include "HashEntry.h"
#include "HashCode.h"

using namespace std;

constexpr unsigned int TABLE_SIZE = 128;

template<typename K, typename V, typename F = HashCode<K>>
class HashMap {

public:
    //Constructor for initializing table with hashEntry array .. contains entries -> aktien
    HashMap(unsigned int hashSize = TABLE_SIZE) : hashSize(hashSize) {
        table = new HashEntry<K, V> *[hashSize]();
        for (int i = 0; i < hashSize; i++){
            table[i] = NULL;
        }
    }

    //insert key, value to map
    void put(const K &key, const V &value) {
        unsigned int hash = hashFunc(key) % hashSize;

        quadraticProbing(key, hash);

        if (table[hash] != NULL)
            table[hash] = NULL;

        table[hash] = new HashEntry<K, V>(key, value);

    }

    //find a related value for a specific key and modify memory address
    bool get(const K &key, V &value) {
        unsigned int hash = hashFunc(key) % hashSize;

        quadraticProbing(key, hash);

        if (table[hash]->getKey() == key)
        {
            value = table[hash]->getValue();
            return true;
        }

        return false;
    }

    /**
     * Remove element at a key
     * @param key
     */
    void erase(const K &key) {
        int i = 1;
        unsigned int hash = hashFunc(key) % hashSize;
        while (table[hash] != NULL) {
            if (table[hash]->getKey() == key)
                break;
            quadraticProbing(key, hash);
        }

        if (table[hash] == NULL) {
            return;
        } else {
            table[hash] = nullptr;
            //Free up the memory
            delete table[hash];
        }
    }

    unsigned int quadraticProbing(const K &key, unsigned int &hash) const {
        int i = 1;
        while (table[hash] != NULL && table[hash]->getKey() != key) {
            //Quadratic probing
            hash = (hash + i * i) % hashSize;
            i++;
        }
        return hash;
    }

    //Destructor for destroying all entries
    ~HashMap() {
        // destroy all buckets one by one
        for (size_t i = 0; i < hashSize; ++i) {
            HashEntry<K, V> *entry = table[i];

            while (entry != NULL) {
                delete entry;
            }

            table[i] = NULL;
        }
    }

private:
    HashEntry<K, V> **table;
    F hashFunc;
    const unsigned int hashSize;
};

#endif //UEBUNG01_HASHMAP_H
