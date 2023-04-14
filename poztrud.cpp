//
// Created by Mateusz on 06.06.2022.
//

#include "poztrud.h"
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int poztrud() // Poziom trudnoci - 1: atwy, 2: redni, 3: trudny
{
    RenderWindow okno(VideoMode(800, 600, 32), "Wybr poziomu trudnoci");
    Font f;
    f.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
    Text t;
    t.setString("Wybierz poziom trudnosci:");
    t.setFillColor(Color::White);
    t.setFont(f);
    t.setPosition(4, 4);
    t.setCharacterSize(20);
    Text poz[3];
    poz[0].setString("Latwy");
    poz[0].setFillColor(Color::White);
    poz[0].setFont(f);
    poz[0].setPosition(4, 34);
    poz[0].setCharacterSize(20);

    poz[1].setString("Sredni");
    poz[1].setFillColor(Color::White);
    poz[1].setFont(f);
    poz[1].setPosition(4, 64);
    poz[1].setCharacterSize(20);

    poz[2].setString("Trudny");
    poz[2].setFillColor(Color::White);
    poz[2].setFont(f);
    poz[2].setPosition(4, 94);
    poz[2].setCharacterSize(20);
    while (okno.isOpen())
    {
        okno.clear();
        if (Mouse::getPosition(okno).y > 32 && Mouse::getPosition(okno).y < 62 && Mouse::getPosition(okno).x < 400 && Mouse::getPosition(okno).x > 0)
        {
            poz[0].setFillColor(Color::Red);
        }
        else
        {
            poz[0].setFillColor(Color::White);
        }
        if (Mouse::getPosition(okno).y > 62 && Mouse::getPosition(okno).y < 92 && Mouse::getPosition(okno).x < 400 && Mouse::getPosition(okno).x > 0)
        {
            poz[1].setFillColor(Color::Red);
        }
        else
        {
            poz[1].setFillColor(Color::White);
        }
        if (Mouse::getPosition(okno).y > 92 && Mouse::getPosition(okno).y < 122 && Mouse::getPosition(okno).x < 400 && Mouse::getPosition(okno).x > 0)
        {
            poz[2].setFillColor(Color::Red);
        }
        else
        {
            poz[2].setFillColor(Color::White);
        }
        okno.draw(t);
        okno.draw(poz[0]);
        okno.draw(poz[1]);
        okno.draw(poz[2]);
        sf::Event zd;
        while (okno.pollEvent(zd))
        {
            if (zd.type == Event::Closed)
            {
                okno.close();
                return 0;
            }

            if (zd.type == Event::MouseButtonPressed && zd.mouseButton.button == Mouse::Left)
            {
                if (Mouse::getPosition(okno).y > 32 && Mouse::getPosition(okno).y < 62 && Mouse::getPosition(okno).x < 400 && Mouse::getPosition(okno).x > 0)
                {
                    okno.close();
                    return 1;
                }
                if (Mouse::getPosition(okno).y > 62 && Mouse::getPosition(okno).y < 92 && Mouse::getPosition(okno).x < 400 && Mouse::getPosition(okno).x > 0)
                {
                    okno.close();
                    return 2;
                }
                if (Mouse::getPosition(okno).y > 92 && Mouse::getPosition(okno).y < 122 && Mouse::getPosition(okno).x < 400 && Mouse::getPosition(okno).x > 0)
                {
                    okno.close();
                    return 3;
                }
            }
        }

        okno.display();
    }
}
