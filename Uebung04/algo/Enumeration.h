//
// Created by Alexander Tampier on 25.05.18.
//
#include "TSP.h"
#include "../domain/Point.h"

#ifndef UEBUNG04_ENUMERATION_H
#define UEBUNG04_ENUMERATION_H

#endif //UEBUNG04_ENUMERATION_H

using namespace std;

class Enumeration : public TSP{
public:
    Enumeration(const vector<Point *> &values) : TSP(values) {}
};