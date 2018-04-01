#include <fstream>
#include <vector>
#include "algo/HashMap.h"
#include "domain/StockEntry.h"

using namespace std;

vector<StockEntry> readAktieFromCsv(const char *path);

std::string getFileName(std::string filePath, bool withExtension = true, char seperator = '/');

constexpr unsigned int HISTORY_SIZE = 30;

int main() {
    HashMap<string, vector<StockEntry>> hashMap;
    HashEntry<string, vector<StockEntry>> ** table;
    HashEntry<string, vector<StockEntry>> *entries;

    string key;
    vector<StockEntry> value;

    string path;
    int choice;

    while (true) {
        cout << "\n----------------------" << endl;
        cout << "Operations on Hash Table" << endl;
        cout << "\n----------------------" << endl;
        cout << "1. ADD: Eine Stock mit Namen, WKN und Kürzel wird hinzugefügt." << endl;
        cout << "2. DEL:Stock wird gelöscht." << endl;
        cout << "3. IMPORT: Kurswerte für eine Stock werden aus einer csv Datei importiert" << endl;
        cout << "4. SEARCH: Eine Stock wird in der Hashtabelle gesucht (Eingabe von Namen\n"
                "oder Kürzel) und der aktuellste Kurseintrag\n"
                "(Date,Open,High,Low,Close,Volume,Adj Close) wird ausgegeben." << endl;
        cout << "5. PLOT: Die Schlusskurse der letzten 30 Tage einer Stock werden als ASCII\n"
                "Grafik ausgegeben, Format ist frei wählbar." << endl;
        cout << "6. SAVE <filename>: Programm speichert die Hashtabelle in eine Datei ab" << endl;
        cout << "7. LOAD <filename>: Programm lädt die Hashtabelle aus einer Datei" << endl;
        cout << "8. PRINT Hashtable" << endl;
        cout << "9. QUIT : Programm wird beendet" << endl;
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
                cout << "Path from csv file: ";
                cin >> path;
                try {
                    key = getFileName(path, false);
                    value = readAktieFromCsv(path.c_str());

                    hashMap.put(key, value);
                } catch (const char *msg) {
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
                    //cout << value << endl;
                }
                break;
            case 5:
                //TODO - PLOT
            case 6:
                //TODO - SAVE
            case 7:
                //TODO - LOAD
            case 8:
                table = hashMap.getTable();
                for (size_t i = 0; i < hashMap.getHashSize(); ++i) {
                    entries = table[i];
                    if (entries != nullptr) {
                        cout << "Key-> " << entries->getKey() << endl;
                        for (StockEntry entry:entries->getValue())
                            cout << "Value-> " << entry << endl;
                    }
                }

                break;
            case 9:
                exit(1);
            default:
                cout << "\nEnter correct option\n";
        }
    }

    return 0;
}

std::vector<StockEntry> readAktieFromCsv(const char *path) {
    std::ifstream file(path);

    if (!file) {
        throw "Import-error";
    }

    vector<StockEntry> stockEntries;
    string line;
    getline(file, line);

    for (int i = 0; i < 30; i++) {
        getline(file, line);
        if (!file)
            break;
        stockEntries.emplace_back(StockEntry(line));
    }

    return stockEntries;
}

/*
 * Get File Name from a Path with or without extension
 * call-by-value
 */
std::string getFileName(std::string filePath,
                        bool withExtension,
                        char seperator) {
    // Get last dot position
    std::size_t dotPos = filePath.rfind('.');
    std::size_t sepPos = filePath.rfind(seperator);

    if (sepPos != std::string::npos) {
        return filePath.substr(sepPos + 1,
                               filePath.size() - (withExtension || dotPos == std::string::npos ? 1 : dotPos));
    }
    return "";
}
