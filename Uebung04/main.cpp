#include <iostream>
#include "commons/FileReader.h"
#include "algo/NearestNeighbour.h"

int main(int argc, char *argv[]) {
    try {
        vector<Point *> values = FileReader::readFromFile(argv[2]);

        switch (argv[1][1]) {
            case 'n':
            {
                NearestNeighbour *nearestNeighbour = new NearestNeighbour(values);
                nearestNeighbour->initalizeMatrix();
                nearestNeighbour->printMatrix();
                nearestNeighbour->getMinimumDistance();
                nearestNeighbour->printMinimumDistance();
                nearestNeighbour->printWay();
                break;
            }
            case 'e': {
                // code here ..
                break;
            }
            default:
                break;
        }

    } catch (exception &e) {
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
