//
// Created by Alexander Tampier on 03.03.18.
//

#ifndef UEBUNG01_HASHENTRY_H
#define UEBUNG01_HASHENTRY_H

template<typename K, typename V>
class HashEntry {
private:
    // key-value pair
    K key;
    V value;
public:
    HashEntry(const K &key, const V &value) {
        this->key = key;
        this->value = value;
    }

    K getKey() const {
        return key;
    }

    V getValue() const {
        return value;
    }
};


#endif //UEBUNG01_HASHENTRY_H
