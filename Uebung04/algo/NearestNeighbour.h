//
// Created by Alexander Tampier on 25.05.18.
//
#include <cfloat>
#include <stack>
#include "TSP.h"

#ifndef UEBUNG04_NEARESTNEIGHBOUR_H
#define UEBUNG04_NEARESTNEIGHBOUR_H

#endif //UEBUNG04_NEARESTNEIGHBOUR_H

class NearestNeighbour : public TSP {
public:
    NearestNeighbour(const vector<Point *> values) : TSP(values) {
    }

    void initalizeMatrix() {
        vector<Point *> points = this->getValues();

        for (int row = 0; row < getSize(); row++) {
            for (int col = 0; col < getSize(); col++) {
                this->setPoint(row, col, points.at(row), points.at(col));
            }
        }

        initialized = true;
    }

    void getMinimumDistance() {
        if (initialized) {
            double **adjacencyMatrix = getAdjazenzMatrix();
            int size = getSize();

            stack<int> stack;
            std::vector<int> visited(size);

            stack.push(0);

            int destination = 0;
            int element=0;
            int i=0;

            double min = DBL_MAX;
            bool minFlag = false;

            while (!stack.empty()) {
                element = stack.top();
                min = DBL_MAX;
                for(int i=0; i<size; i++){
                    if (adjacencyMatrix[element][i] != 0 && visited.at(i) == 0) {
                        if (adjacencyMatrix[element][i] < min) {
                            min = adjacencyMatrix[element][i];
                            destination = i;
                            minFlag = true;
                        }
                    }
                }
                if (minFlag) {
                    //set node to visited true
                    visited.at(0) = 1;
                    visited.at(destination) = 1;
                    stack.push(destination);

                    ways.push_back(element);
                    ways.push_back(destination);

                    minimumDistance.push_back(min);

                    minFlag = false;
                    continue;
                }
                stack.pop();
            }
            ways.push_back(destination);
            ways.push_back(element);

            minimumDistance.push_back(adjacencyMatrix[element][destination]);
        }
    }

    void printMinimumDistance() {
        cout << "Distances: ";
        for (double distance : minimumDistance) {
            cout << distance << " ";
        }
        cout << endl;
    }

    void printWay() {
        cout << "Ways: ";
        for (int i = 0; i < ways.size(); i += 2) {
            cout << ways.at(i) << "->" << ways.at(i + 1) << " ";
        }
        cout << endl;
    }

private:
    vector<double> minimumDistance;
    vector<int> ways;
    bool initialized = false;
};