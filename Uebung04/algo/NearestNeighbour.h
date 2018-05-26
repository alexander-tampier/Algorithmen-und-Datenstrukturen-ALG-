//
// Created by Alexander Tampier on 25.05.18.
//
#include <cfloat>
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
            for (int col = row; col < getSize(); col++) {
                this->setPoint(row, col, points.at(row), points.at(col));
            }
        }

        initialized = true;
    }

    void getMinimumDistance() {
        if (initialized) {
            int startPoint = 1;
            int nextRow = 0;
            double temp = DBL_MAX;
            double **matrix = getAdjazenzMatrix();

            //Give me the neighbour of the startpoint
            getValues().at(0)->setVisited(true);
            for (int row = 0; row < startPoint; row++) {
                for (int col = row; col < getSize(); col++) {
                    if (matrix[row][col] < temp && !getValues().at(col)->isVisited()) {
                        temp = matrix[row][col];
                        nextRow = col;

                    }
                }
            }
            getValues().at(nextRow)->setVisited(true);
            minimumDistance.push_back(temp);
            way.push_back(nextRow);

            temp = DBL_MAX;

            for(int k=0; k<getSize()-2; k++){
                for(int i=0; i<nextRow; i++){
                    if(matrix[i][nextRow] < temp && !getValues().at(i)->isVisited()){
                        temp = matrix[i][nextRow];
                        nextRow = i;

                    }
                }

                for(int z=nextRow;z<getSize();z++){
                    if(matrix[nextRow][z] < temp && !getValues().at(z)->isVisited()){
                        temp = matrix[nextRow][z];
                        nextRow = z;

                    }
                }
                getValues().at(nextRow)->setVisited(true);
                minimumDistance.push_back(temp);
                way.push_back(nextRow);
            }
        }
    }

    void printMinimumDistance(){
        cout << "Distances: ";
        for(double distance : minimumDistance){
            cout << distance << " ";
        }
        cout<<endl;
    }

    void printWay(){
        cout << "Ways: ";
        for(int w : way){
            cout << w << " ";
        }
        cout<<endl;
    }

private:
    vector<double> minimumDistance;
    vector<int> way;
    bool initialized = false;
};