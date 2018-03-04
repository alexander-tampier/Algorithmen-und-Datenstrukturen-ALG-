//
// Created by Alexander Tampier on 03.03.18.
//

#ifndef UEBUNG01_HASHMAP_H
#define UEBUNG01_HASHMAP_H

#include <cstddef>
#include "HashEntry.h"

const int TABLE_SIZE = 128;

template<typename K, typename V>
class HashMap {
private:
    HashEntry<K, V> **table;

public:
    HashMap() {
        table = new HashEntry<K,V> *[TABLE_SIZE]();
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;

    }

    bool get(const K &key, V &value) {
        int hash = (key % TABLE_SIZE);

        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;

        if (table[hash] == NULL)
            return false;
        else
            value = table[hash]->getValue();

        return true;
    }


    void put(const K &key, const V &value) {
        int hash = (key % TABLE_SIZE);

        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;

        if (table[hash] != NULL)
            delete table[hash];

        table[hash] = new HashEntry<K, V>(key, value);

    }
};


#endif //UEBUNG01_HASHMAP_H
