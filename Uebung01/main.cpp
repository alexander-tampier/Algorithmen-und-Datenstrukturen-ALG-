#include <fstream>
#include "algo/HashMap.h"
#include "domain/Aktie.h"

using namespace std;

Aktie *readAktieFromCsv(const char *path);

constexpr unsigned int HISTORY_SIZE = 30;

int main() {
    /*
    hashMap.put("microsoft", Aktie(25));
    std::cout << hashMap.get("microsoft")<<endl;
    hashMap.erase("microsoft");
    std::cout << hashMap.get("microsoft")<<endl;
     */

    HashMap<string, Aktie> hashMap;
    string key, path;
    int choice;
    Aktie value;

    while (1) {
        cout << "\n----------------------" << endl;
        cout << "Operations on Hash Table" << endl;
        cout << "\n----------------------" << endl;
        cout << "1. ADD: Eine Aktie mit Namen, WKN und Kürzel wird hinzugefügt." << endl;
        cout << "2. DEL:Aktie wird gelöscht." << endl;
        cout << "3. IMPORT: Kurswerte für eine Aktie werden aus einer csv Datei importiert" << endl;
        cout << "4. SEARCH: Eine Aktie wird in der Hashtabelle gesucht (Eingabe von Namen\n"
                "oder Kürzel) und der aktuellste Kurseintrag\n"
                "(Date,Open,High,Low,Close,Volume,Adj Close) wird ausgegeben." << endl;
        cout << "5. PLOT: Die Schlusskurse der letzten 30 Tage einer Aktie werden als ASCII\n"
                "Grafik ausgegeben, Format ist frei wählbar." << endl;
        cout << "6. SAVE <filename>: Programm speichert die Hashtabelle in eine Datei ab" << endl;
        cout << "7. LOAD <filename>: Programm lädt die Hashtabelle aus einer Datei" << endl;
        cout << "8. QUIT : Programm wird beendet" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to be inserted: ";
                //cin >> value;
                cout << "Enter key at which element to be inserted: ";
                cin >> key;
                hashMap.put(key, value);
                break;
            case 2:
                cout << "Enter key of the element to be deleted: ";
                cin >> key;
                hashMap.erase(key);
                break;
            case 3:
                //TODO - IMPORT
                cout << "Path from csv file: ";
                cin >> path;
                try {
                    readAktieFromCsv(path.c_str());
                }catch(const char* msg){
                    cerr << msg << endl;
                }
                break;
            case 4:
                cout << "Enter key of the element to be searched: ";
                cin >> key;

                if (!hashMap.get(key, value)) {
                    cout << "No element found at key " << key << endl;
                    continue;
                } else {
                    cout << "Element at key " << key << " : ";
                    cout << value << endl;
                }
                break;
            case 5:
                //TODO - PLOT
            case 6:
                //TODO - SAVE
            case 7:
                //TODO - LOAD
            case 8:
                exit(1);
            default:
                cout << "\nEnter correct option\n";
        }
    }

    return 0;
}

Aktie *readAktieFromCsv(const char *path) {
    Aktie *aktie = new Aktie[HISTORY_SIZE];

    for (int i = 0; i < HISTORY_SIZE; i++) {
        aktie[i] = NULL;
    }

    ifstream csv(path);

    if (!csv) {
        throw "Import-error";
    }

    return aktie;
}