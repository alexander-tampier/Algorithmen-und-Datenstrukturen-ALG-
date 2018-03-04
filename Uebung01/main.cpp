#include <iostream>
#include <string>
#include "HashEntry.cpp"
#include "HashMap.cpp"

using namespace std;

int main() {
    HashMap<int, string> hashMap;

    string value;

    hashMap.put(1, "helloWorld");
    hashMap.get(1, value);
    std::cout << value;

    return 0;
}