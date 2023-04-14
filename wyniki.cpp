//
// Created by Mateusz on 06.06.2022.
//

#include "wyniki.h"
#include "Plansza.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
using namespace sf;
using namespace std;
wyniki::wyniki(){}

void wyniki(Rezultat r)
{
    ifstream inp("wyniki.info");
    RenderWindow okno(VideoMode(800, 600, 32), "Koniec gry");
    int wyn[3];
    for (int i = 0; i < 3; i++)
    {
        wyn[i] = 0;
        inp >> wyn[i];
    }
    if (r == Rezultat::re)
        wyn[1] += 1;
    else if (r == Rezultat::wb)
        wyn[0] += 1;
    else if (r == Rezultat::wcz)
        wyn[2] += 1;
    inp.close();
    ofstream out("wyniki.info", ofstream::trunc);
    for (int i = 0; i < 3; i++) out << wyn[i] << '\n';
    out.close();
    Font f;
    f.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
    Text txt;
    txt.setCharacterSize(20);
    txt.setFillColor(Color::White);
    txt.setFont(f);

    if (r == Rezultat::re)
        txt.setString("Remis! Oto laczne wyniki wszystkich gier:");
    else if (r == Rezultat::wb)
        txt.setString("Wygrana bialych! Oto laczne wyniki wszystkich gier:");
    else if (r == Rezultat::wcz)
        txt.setString("Wygrana czarnych! Oto laczne wyniki wszystkich gier:");
    txt.setPosition(4, 10);
    okno.draw(txt);

    txt.setString("Wygrane bialych:" + to_string(wyn[0]));
    txt.setPosition(4, 40);
    okno.draw(txt);

    txt.setString("Remisy:" + to_string(wyn[1]));
    txt.setPosition(4,70);
    okno.draw(txt);

    txt.setString("Wygrane czarnych:" + to_string(wyn[2]));
    txt.setPosition(4, 100);
    okno.draw(txt);
    while (okno.isOpen())
    {
        sf::Event zd;
        while (okno.pollEvent(zd))
        {
            if (zd.type == Event::Closed)
                okno.close();
        }

        okno.display();
    }
}
