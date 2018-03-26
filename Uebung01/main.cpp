#include "algo/HashMap.h"
#include "domain/Aktie.h"

using namespace std;

int main() {
    HashMap<string, Aktie> hashMap;
    hashMap.put("microsoft", Aktie(23));
    std::cout << hashMap.get("microsoft")<<endl;
    hashMap.put("formicsot", Aktie(24));
    std::cout << hashMap.get("formicsot")<<endl;
    hashMap.put("hello", Aktie(25));
    std::cout << hashMap.get("hello")<<endl;

    hashMap.erase("hello");

    std::cout << hashMap.get("hello")<<endl;

    return 0;
}