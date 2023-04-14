#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Plansza.h"
#include "poztrud.h"
#include "wyniki.h"

using namespace std;
using namespace sf;

void display(RenderWindow * wnd, Plansza p)
{
    wnd->clear();
    RectangleShape pb, pc;
    pc.setSize({ 64,64 });
    pc.setFillColor(Color(225, 193, 110));
    pb.setSize({ 64,64 });
    pb.setFillColor(Color(255, 255, 255));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                pc.setPosition(64 * j, 64 * i);
                wnd->draw(pc);
            }
            else if (i % 2 != 0 && j % 2 != 0)
            {
                pc.setPosition(64 * j, 64 * i);
                wnd->draw(pc);
            }
            else
            {
                pb.setPosition(64 * j, 64 * i);
                wnd->draw(pb);
            }

        }
    Texture cp, bp, db, dc;
    cp.loadFromFile("../pion_c.jpg");
    bp.loadFromFile("../pion_b.jpg");
    db.loadFromFile("../dama_b.jpg");
    dc.loadFromFile("../dama_c.jpg");
    Sprite czp, czd, bip, bid;
    czp.setTexture(cp);
    czd.setTexture(dc);
    bip.setTexture(bp);
    bid.setTexture(db);
    Figura x;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            x = p.naPolu(j, i);
            if (x == Figura::bd)
            {
                bid.setPosition(64 * j, 64 * i);
                wnd->draw(bid);
            }
            else if (x == Figura::cd)
            {
                czd.setPosition(64 * j, 64 * i);
                wnd->draw(czd);
            }
            else if (x == Figura::bp)
            {
                bip.setPosition(64 * j, 64 * i);
                wnd->draw(bip);
            }
            else if (x == Figura::cp)
            {
                czp.setPosition(64 * j, 64 * i);
                wnd->draw(czp);
            }
        }
    wnd->display();
}

int main()
{
    Rezultat kon;
    int ax = -1, ay = -1;
    int level = poztrud();
    Plansza pl(level);
    RenderWindow okno(VideoMode(800, 600, 32), "Gra w Warcaby");
    while (okno.isOpen())
    {
        sf::Event zd;
        while (okno.pollEvent(zd))
        {
            if (zd.type == Event::Closed)
                okno.close();

            if (zd.type == Event::MouseButtonPressed && zd.mouseButton.button == Mouse::Left)
            {
                if (ax == -1 && ay == -1)
                {
                    ax = Mouse::getPosition(okno).x / 64;
                    ay = Mouse::getPosition(okno).y / 64;
                    if (pl.naPolu(ax, ay) == Figura::brak)
                    {
                        ax = -1;
                        ay = -1;
                    }
                }
                else
                {
                    if (Mouse::getPosition(okno).x / 64 < 8 && Mouse::getPosition(okno).y / 64 < 8)
                        pl.ruch(ax, ay, Mouse::getPosition(okno).x / 64, Mouse::getPosition(okno).y / 64);
                    ax = -1;
                    ay = -1;
                }
            }
        }
        display(&okno, pl);
        kon = pl.result();
        if (kon != Rezultat::brak)
        {
            okno.close();
            wyniki(kon);
        }
    }
    return 0;
}
