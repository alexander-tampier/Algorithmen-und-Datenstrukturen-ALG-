//
// Created by Alexander Tampier on 29.03.18.
//

#ifndef UEBUNG01_StockEntryENTRY_H
#define UEBUNG01_StockEntryENTRY_H


#include <ctime>
#include <ostream>
#include <string>
#include <sstream>

using namespace std;

class StockEntry {
    string date;
    double open;
    double high;
    double low;
    double close;
    int volume;
    double adjClose;

public:

    StockEntry(){}

    StockEntry(string csvLine) {
        date = "";
        open = 0;
        high = 0;
        low = 0;
        close = 0;
        volume = 0;
        adjClose = 0;

        replace(csvLine.begin(), csvLine.end(), ',', ' ');
        istringstream csvStream(csvLine);

        csvStream >> date;
        csvStream >> open;
        csvStream >> high;
        csvStream >> low;
        csvStream >> close;
        csvStream >> volume;
        csvStream >> adjClose;
    }

    friend std::ostream &operator<<(std::ostream &os, const StockEntry &entry) {
        os << "date: " << entry.date << " open: " << entry.open << " high: " << entry.high << " low: " << entry.low
           << " close: " << entry.close << " volume: " << entry.volume << " adjClose: " << entry.adjClose;
        return os;
    }
};


#endif //UEBUNG01_StockEntryENTRY_H
