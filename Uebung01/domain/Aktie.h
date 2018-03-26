//
// Created by Alexander Tampier on 26.03.18.
//

#ifndef UEBUNG01_AKTIE_H
#define UEBUNG01_AKTIE_H


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
    Aktie(){}

    Aktie(int volume) : volume(volume) {}

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

    friend std::ostream &operator<<(std::ostream &os, const Aktie &aktie) {
        os << "volume: " << aktie.volume;
        return os;
    }
};


#endif //UEBUNG01_AKTIE_H
