//
// Created by Alexander Tampier on 26.03.18.
//

#ifndef UEBUNG01_HASHENTRY_H
#define UEBUNG01_HASHENTRY_H


template<typename K, typename V>
class HashEntry {

public:
    HashEntry() {}

    HashEntry(const K &key, const V &value) {
        this->key = key;
        this->value = value;
    }

    const K getKey() const {
        return key;
    }

    const V getValue() const {
        return value;
    }

private:
    // key-value pair
    K key;
    V value;
};


#endif //UEBUNG01_HASHENTRY_H
