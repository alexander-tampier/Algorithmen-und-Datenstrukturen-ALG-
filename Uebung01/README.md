# Übung 1 - Hastabelle

Arbeiten Sie in 2er Gruppen an folgendem Programmierbeispiel. Die Wahl der Programmiersprache (C, C++, C#, Java) bleibt Ihnen überlassen, jedoch muss die Datenstruktur selbst implementiert werden (keine fertige Hashtable Klasse verwenden!). Weitere Programmiersprachen nur nach Absprache!

## Aufgabenstellung

Implementieren Sie ein Programm zur Verwaltung von Aktienkursen.
Um schnell nach einer bestimmten Aktie suchen zu können, sollen die Aktien in einer Hashtabelle verwaltet werden. Pro Aktie sollen Name, Wertpapierkennnummer (WKN als String) und Kürzel (auch ein beliebiger String) gespeichert werden. Weiters sind pro Aktie die Kursdaten der vergangenen 30 Tage zu verwalten mit folgenden Informationen:
(Date,Open,High,Low,Close,Volume,Adj Close)

Aktienkursdaten dieser Form können z.B. von http://de.finance.yahoo.com/q/hp?s=<KÜRZEL> z.B. für die Microsoft Aktie (Kürzel MSFT) http://de.finance.yahoo.com/q/hp?s=MSFT auch als csv Datei heruntergeladen werden.

Das Programm wird über folgende Menüpunkte gesteuert:

* ADD: Eine Aktie mit Namen, WKN und Kürzel wird hinzugefügt.
* DEL:Aktiewirdgelöscht.
* IMPORT: Kurswerte für eine Aktie werden aus einer csv Datei importiert
* SEARCH: Eine Aktie wird in der Hashtabelle gesucht (Eingabe von Namen
oder Kürzel) und der aktuellste Kurseintrag
(Date,Open,High,Low,Close,Volume,Adj Close) wird ausgegeben.
* PLOT: Die Schlusskurse der letzten 30 Tage einer Aktie werden als ASCII
Grafik ausgegeben, Format ist frei wählbar.
* SAVE <filename>: Programm speichert die Hashtabelle in eine Datei ab
* LOAD <filename>: Programm lädt die Hashtabelle aus einer Datei
* QUIT : Programm wird beendet

# Sample Map

Klassendiagramm der Schnittstelle Map

![map](https://user-images.githubusercontent.com/16546792/36937985-912a32f2-1f1b-11e8-99c1-966d7968d280.png)

# Basicddea of HashMap

Grundidee für die Implementierung der Hashtabelle

 ```c++
class HashEntry {
  private:
    int key;
  int value;

  public:
    HashEntry(int key, int value) {
      this - > key = key;
      this - > value = value;
    }

  int getKey() {
    return key;
  }

  int getValue() {
    return value;
  }
};
 ```
 
Jeder Behälter beinhaltet Einträge einzelner Entries

```c++
const int HASH_SIZE = 128;

class HashMap {

private:
    HashEntry** bucket;

public:
    HashMap()
    {
        bucket = new HashEntry*[HASH_SIZE];
        for (int i = 0; i < HASH_SIZE; i++)
            bucket[i] = NULL;
    }

    int get(int key)
    {
        int hash = (key % HASH_SIZE);
        
        while (bucket[hash] != NULL && bucket[hash]->getKey() != key)
            hash = (hash + 1) % HASH_SIZE;

        if (bucket[hash] == NULL)
            return -1;
        else
            return bucket[hash]->getValue();
    }

    void put(int key, int value)
    {
        int hash = (key % HASH_SIZE);

        while (bucket[hash] != NULL && bucket[hash]->getKey() != key)
            hash = (hash + 1) % HASH_SIZE;

        if (bucket[hash] != NULL)
            delete bucket[hash];

        bucket[hash] = new HashEntry(key, value);
    }

    ~HashMap()
    {
        for (int i = 0; i < HASH_SIZE; i++)
            if (bucket[i] != NULL)
                delete bucket[i];
        delete[] bucket;
    }
};

```

# Contributors
* Alexander Tampier
* Benjamin Czihak

