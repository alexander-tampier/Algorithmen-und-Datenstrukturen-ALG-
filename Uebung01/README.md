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

![map](https://user-images.githubusercontent.com/16546792/36937667-27c455b2-1f17-11e8-9e4b-1b4098364d0f.png)


# Contributors
* Alexander Tampier
* Benjamin Czihak

