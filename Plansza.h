//
// Created by Mateusz on 06.06.2022.
//

#ifndef NOWY_FOLDER__5__PLANSZA_H
#define NOWY_FOLDER__5__PLANSZA_H

enum class Figura {brak, cp, bp, cd, bd}; // cp - czarny pion, bp - biay pion, cd - czarna dama, bd - biaa dama
enum class Rezultat {brak, re, wb, wcz}; // brak - gra dalej si toczy, re - remis, wb - wygrana biaych, wc - wygrana czarnych
enum class Kolej {biale, czarne};

class Plansza
{
private:
    Figura pola[64]; // Wszystkie pola na planszy
    int rc; // Licznik posuni bez bicia i bez ruchu pionem.

public:
    Kolej k;
    Plansza(int);
    Rezultat result();
    Figura naPolu(int x, int y);
    bool ruch(int fx, int fy, int tx, int ty);
};

#endif //NOWY_FOLDER__5__PLANSZA_H
