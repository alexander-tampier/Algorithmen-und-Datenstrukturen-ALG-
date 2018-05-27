//
// Created by Alexander Tampier on 25.05.18.
//
#include <math.h>

#ifndef UEBUNG04_TSP_H
#define UEBUNG04_TSP_H

#endif //UEBUNG04_TSP_H

class TSP{
public:
    TSP(vector<Point *> values){
        this->values = values;
        this->size = values.size();
        this->adjazenzMatrix = new double*[size];
        for(int i=0; i<size; i++){
            this->adjazenzMatrix[i] = new double[size];
        }
    }

    TSP() {
    }

    virtual ~TSP() {
        for(int i=0; i<size; i++){
            delete adjazenzMatrix[i];
        }

        delete[] adjazenzMatrix;
    }

    void setPoint(int row, int col, Point *p1, Point *p2){
        this->adjazenzMatrix[row][col] = pow(p1->getX()-p2->getX(), 2) + pow(p1->getY()-p2->getY(), 2);
    }

    void printMatrix(){
        for(int row=0; row<size; row++){
            for(int col=0; col<size; col++){
                cout<<adjazenzMatrix[row][col]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    double **getAdjazenzMatrix() const {
        return adjazenzMatrix;
    }

    const int getSize() const {
        return size;
    }

    const vector<Point *> &getValues() const {
        return values;
    }

private:
    double **adjazenzMatrix;
    int size;
    vector<Point *> values;
};