#include "HashMap.h"
#include "Aktie.h"

using namespace std;

int main() {
    HashMap<string, Aktie> hashMap;
    hashMap.put("microsoft", Aktie(23));
    std::cout << hashMap.get("microsoft");

    return 0;
}