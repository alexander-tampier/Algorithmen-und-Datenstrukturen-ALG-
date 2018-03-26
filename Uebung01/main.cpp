#include "algo/HashMap.h"
#include "domain/Aktie.h"

using namespace std;

int main() {
    HashMap<string, Aktie> hashMap;
    hashMap.put("hello", Aktie(25));
    std::cout << hashMap.get("hello")<<endl;

    hashMap.erase("hello");

    std::cout << hashMap.get("hello")<<endl;

    return 0;
}