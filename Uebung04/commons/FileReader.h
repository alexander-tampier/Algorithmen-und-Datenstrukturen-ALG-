//
// Created by Alexander Tampier on 25.05.18.
//

#ifndef UEBUNG04_FILEREADER_H
#define UEBUNG04_FILEREADER_H

#include <vector>
#include <fstream>
#include <sstream>
#include "../domain/Point.h"

using namespace std;

class FileReader {
public:
    /**
     * Reads a given file with specified numbers and returns the numbers stored in a vector
     * @param path - reads the given path to the file
     * @return vector<int> that contains the given key values for the BST
     */
    static vector<Point *> readFromFile(const char *path) {
        vector<Point *> points;
        string line = "";
        string compare[] = {"DISPLAY_DATA_SECTION", "NODE_COORD_SECTION"};

        bool found = false;

        double index = 0.0;
        double x = 0.0;
        double y = 0.0;

        ifstream file;
        file.open(path);

        if (!file) {
            throw "Import-error";
        }

        while (true) {
            getline(file, line);

            if (found) {
                stringstream stream(line);

                stream >> index >> x >> y;

                if (index != 0) {
                    Point *point = new Point(x, y);
                    //push into collection
                    points.push_back(point);
                }

                stream.clear();
                index = 0;
            }

            for (int i = 0; i<sizeof(compare)/sizeof(compare[0]);i++) {
                if (line.compare(compare[i]) == 0) found = true;
            }

            // line is equal with

            if (file.eof()) break;
        }

        file.close();
        return points;
    }
};


#endif //UEBUNG04_FILEREADER_H
