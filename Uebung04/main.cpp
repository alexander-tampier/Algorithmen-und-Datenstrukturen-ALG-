#include <iostream>
#include "commons/FileReader.h"

int main() {
    std::string path;
    std::cout << "filename: ";
    std::cin >> path;

    try{
        vector<Point*> values = FileReader::readFromFile(path.c_str());

        for (Point *point : values) // access by reference to avoid copying
        {
            std::cout << *point <<"\n";
        }
        
    }catch(exception& e){
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}