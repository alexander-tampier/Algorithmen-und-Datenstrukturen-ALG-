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

const int HASH_SIZE = 1499;

template<typename K, typename V, typename F = HashCode<K>>
class HashMap {

public:
    //Constructor for initializing bucket with hashEntry array .. contains entries -> aktien
    HashMap(unsigned int hashSize = HASH_SIZE) : hashSize(hashSize) {
        deletedPointer = new HashEntry<K,V>();
        bucket = new HashEntry<K, V> *[hashSize]();
        for (int i = 0; i < hashSize; i++){
            bucket[i] = NULL;
        }
    }

    /*   Function: Adds new item to the back of the list at a given key in the hash map
     * */
    void put(const K &key, const V &value) {
        unsigned int hash = hashFunc(key) % hashSize;

        if(bucket[hash]!=NULL){
            int i = 1;
            while ( bucket[hash] != NULL && bucket[hash]->getKey() != key && bucket[hash] != deletedPointer) {
                //Quadratic probing
                hash = (hash + i * i) % hashSize;
                i++;
            }
        }

        //Update record
        if (bucket[hash] != NULL || bucket[hash] == deletedPointer)
            bucket[hash] = NULL;

        bucket[hash] = new HashEntry<K, V>(key, value);

    }

    //find a related value for a specific key and modify memory address
    bool get(const K &key, V &value) {
        unsigned int hash = hashFunc(key) % hashSize;

        int counter = 0;

        if(bucket[hash]!=NULL){
            int i = 1;
            while ( bucket[hash] != NULL && bucket[hash]->getKey() != key) {
                //Quadratic probing
                hash = (hash + i * i) % hashSize;
                i++;

                //Collision detection - Every time: O(n)
                if(counter==hashSize-1)
                    return false;
                counter++;
            }
        }

        if (bucket[hash]->getKey() == key)
        {
            value = bucket[hash]->getValue();
            return true;
        }

        //No Collision, field is null
        return false;
    }

    /**
     * Removes the instance from the map
     * @param key
     */
    void erase(const K &key) {
        int i = 1;
        unsigned int hash = hashFunc(key) % hashSize;
        while (bucket[hash] != NULL) {
            if (bucket[hash]->getKey() == key)
                break;
            quadraticProbing(key, hash);
        }

        if (bucket[hash] == NULL) {
            return;
        } else {
            delete bucket[hash];
            bucket[hash] = deletedPointer;
        }
    }

    unsigned int quadraticProbing(const K &key, unsigned int &hash) const {
        int i = 1;
        while ( bucket[hash] != NULL && bucket[hash]->getKey() != key) {
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
            HashEntry<K, V> *entry = bucket[i];

            while (entry != NULL) {
                delete entry;
            }

            bucket[i] = NULL;
        }

        delete deletedPointer;
    }

    HashEntry<K, V> **getTable() const {
        return bucket;
    }

    const unsigned int getHashSize() const {
        return hashSize;
    }

    HashEntry<K, V> *getDeletedPointer() const {
        return deletedPointer;
    }

private:
    HashEntry<K, V> *deletedPointer;
    HashEntry<K, V> **bucket;
    F hashFunc;
    const unsigned int hashSize;
};

#endif //UEBUNG01_HASHMAP_H
