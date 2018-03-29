//
// Created by Alexander Tampier on 26.03.18.
//

#ifndef UEBUNG01_AKTIE_H
#define UEBUNG01_AKTIE_H


#include <ostream>

class Aktie {
private:
    time_t date;
    double open;
    double high;
    double low;
    double close;
    int volume;
    double adjClose;

public:
    Aktie(time_t date, double open, double high, double low, double close, int volume, double adjClose) : date(date),
                                                                                                          open(open),
                                                                                                          high(high),
                                                                                                          low(low),
                                                                                                          close(close),
                                                                                                          volume(volume),
                                                                                                          adjClose(
                                                                                                                  adjClose) {}

    Aktie() {

    }

    char *getDate() const {
        return ctime(&date);
    }

    void setDate(time_t date) {
        Aktie::date = date;
    }

    double getOpen() const {
        return open;
    }

    void setOpen(double open) {
        Aktie::open = open;
    }

    double getHigh() const {
        return high;
    }

    void setHigh(double high) {
        Aktie::high = high;
    }

    double getLow() const {
        return low;
    }

    void setLow(double low) {
        Aktie::low = low;
    }

    double getClose() const {
        return close;
    }

    void setClose(double close) {
        Aktie::close = close;
    }

    int getVolume() const {
        return volume;
    }

    void setVolume(int volume) {
        Aktie::volume = volume;
    }

    double getAdjClose() const {
        return adjClose;
    }

    void setAdjClose(double adjClose) {
        Aktie::adjClose = adjClose;
    }

    friend ostream &operator<<(ostream &os, const Aktie &aktie) {
        os << "date: " << aktie.date << " open: " << aktie.open << " high: " << aktie.high << " low: " << aktie.low
           << " close: " << aktie.close << " volume: " << aktie.volume << " adjClose: " << aktie.adjClose;
        return os;
    }
};


#endif //UEBUNG01_AKTIE_H
