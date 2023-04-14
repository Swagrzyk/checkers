#include "Plansza.h"
#include <cmath>

Plansza::Plansza(int lev)
{
    for (int i = 0; i < 64; i++) pola[i] = Figura::brak;
    pola[0] = Figura::cp;
    pola[2] = Figura::cp;
    pola[4] = Figura::cp;
    pola[6] = Figura::cp;
    pola[9] = Figura::cp;
    pola[11] = Figura::cp;
    pola[13] = Figura::cp;
    pola[15] = Figura::cp;
    lev > 1 ? pola[16] = Figura::cp : pola[16] = Figura::brak;
    lev > 2 ? pola[18] = Figura::cp : pola[18] = Figura::brak;
    lev > 2 ? pola[20] = Figura::cp : pola[20] = Figura::brak;
    lev > 1 ? pola[22] = Figura::cp : pola[22] = Figura::brak;
    lev > 1 ? pola[41] = Figura::bp : pola[41] = Figura::brak;
    lev > 2 ? pola[43] = Figura::bp : pola[43] = Figura::brak;
    lev > 2 ? pola[45] = Figura::bp : pola[45] = Figura::brak;
    lev > 1 ? pola[47] = Figura::bp : pola[47] = Figura::brak;
    pola[48] = Figura::bp;
    pola[50] = Figura::bp;
    pola[52] = Figura::bp;
    pola[54] = Figura::bp;
    pola[57] = Figura::bp;
    pola[59] = Figura::bp;
    pola[61] = Figura::bp;
    pola[63] = Figura::bp;
    rc = 0;
    k = Kolej::biale;
}

Figura Plansza::naPolu(int x, int y)
{
    return pola[y*8+x];
}


bool Plansza::ruch(int fx, int fy, int tx, int ty)
{
    if (fx > 7 || fy > 7 || tx > 7 || ty > 7 || fx < 0 || fy < 0 || tx < 0 || ty < 0)
        return false;
    Figura x = naPolu(fx, fy);
    if (k == Kolej::biale)
    {
        if (x == Figura::bd)
        {
            if (fabs(fx - tx) == fabs(fy - ty) && fabs(fx - tx) != 0)
            {
                bool bnd = false;
                int x, y;
                tx > fx ? x = fx + 1 : x = fx - 1;
                ty > fy ? y = fy + 1 : y = fy - 1;
                while (x != tx || y != ty)
                {
                    if (naPolu(x, y) == Figura::bd || naPolu(x, y) == Figura::bp)
                        bnd = true;
                    tx > fx ? x += 1 : x -= 1;
                    ty > fy ? y += 1 : y -= 1;
                }
                if (naPolu(tx, ty) != Figura::brak)
                    bnd = true;
                if (bnd) return false;
                bnd = false;
                tx > fx ? x = fx + 1 : x = fx - 1;
                ty > fy ? y = fy + 1 : y = fy - 1;
                while (x != tx || y != ty)
                {
                    if (naPolu(x, y) == Figura::cd || naPolu(x, y) == Figura::cp)
                        bnd = true;
                    pola[y * 8 + x] = Figura::brak;
                    tx > fx ? x += 1 : x -= 1;
                    ty > fy ? y += 1 : y -= 1;
                }
                if (bnd) rc = 0; else rc++;
                pola[fy * 8 + fx] = Figura::brak;
                pola[ty * 8 + tx] = Figura::bd;
                k = Kolej::czarne;
            }
            else return false;
        }
        else if (x == Figura::bp)
        {
            if (fabs(fx - tx) == 1 && ty == (fy - 1))
            {
                if (naPolu(tx, ty) == Figura::brak)
                {
                    if (ty == 0)
                        pola[ty * 8 + tx] = Figura::bd;
                    else
                        pola[ty * 8 + tx] = Figura::bp;
                    pola[fy * 8 + fx] = Figura::brak;
                    rc = 0;
                    k = Kolej::czarne;
                    return true;
                }
            }
            else if (fabs(fx - tx) == 2 && ty == (fy - 2))
            {
                if (naPolu(tx, ty) == Figura::brak)
                {
                    if (naPolu((fx - tx) > 0 ? fx - 1 : fx + 1, fy - 1) == Figura::cd || naPolu((fx - tx) > 0 ? fx - 1 : fx + 1, fy - 1) == Figura::cp)
                    {
                        pola[(fx - tx) > 0 ? (fy - 1) * 8 + fx - 1 : (fy - 1) * 8 + fx + 1] = Figura::brak;
                        if (ty == 0)
                            pola[ty * 8 + tx] = Figura::bd;
                        else
                            pola[ty * 8 + tx] = Figura::bp;
                        pola[fy * 8 + fx] = Figura::brak;
                        rc = 0;
                        k = Kolej::czarne;
                        return true;
                    }
                    else return false;
                }
            }
            else return false;
        }
        else return false;
    }
    else
    {
        if (x == Figura::cd)
        {
            if (fabs(fx - tx) == fabs(fy - ty) && fabs(fx - tx) != 0)
            {
                bool bnd = false;
                int x, y;
                tx > fx ? x = fx + 1 : x = fx - 1;
                ty > fy ? y = fy + 1 : y = fy - 1;
                while (x != tx || y != ty)
                {
                    if (naPolu(x, y) == Figura::cd || naPolu(x, y) == Figura::cp)
                        bnd = true;
                    tx > fx ? x += 1 : x -= 1;
                    ty > fy ? y += 1 : y -= 1;
                }
                if (naPolu(tx, ty) != Figura::brak)
                    bnd = true;
                if (bnd) return false;
                bnd = false;
                tx > fx ? x = fx + 1 : x = fx - 1;
                ty > fy ? y = fy + 1 : y = fy - 1;
                while (x != tx || y != ty)
                {
                    if (naPolu(x, y) == Figura::bd || naPolu(x, y) == Figura::bp)
                        bnd = true;
                    pola[y * 8 + x] = Figura::brak;
                    tx > fx ? x += 1 : x -= 1;
                    ty > fy ? y += 1 : y -= 1;
                }
                if (bnd) rc = 0; else rc++;
                pola[fy * 8 + fx] = Figura::brak;
                pola[ty * 8 + tx] = Figura::cd;
                k = Kolej::biale;
            }
            else return false;
        }
        else if (x == Figura::cp)
        {
            if (fabs(fx - tx) == 1 && ty == (fy + 1))
            {
                if (naPolu(tx, ty) == Figura::brak)
                {
                    if (ty == 7)
                        pola[ty * 8 + tx] = Figura::cd;
                    else
                        pola[ty * 8 + tx] = Figura::cp;
                    pola[fy * 8 + fx] = Figura::brak;
                    rc = 0;
                    k = Kolej::biale;
                    return true;
                }
            }
            else if (fabs(fx - tx) == 2 && ty == (fy + 2))
            {
                if (naPolu(tx, ty) == Figura::brak)
                {
                    if (naPolu((fx - tx) > 0 ? fx - 1 : fx + 1, fy + 1) == Figura::bd || naPolu((fx - tx) > 0 ? fx - 1 : fx + 1, fy + 1) == Figura::bp)
                    {
                        pola[(fx - tx) > 0 ? (fy + 1) * 8 + fx - 1 : (fy + 1) * 8 + fx + 1] = Figura::brak;
                        if (ty == 7)
                            pola[ty * 8 + tx] = Figura::cd;
                        else
                            pola[ty * 8 + tx] = Figura::cp;
                        pola[fy * 8 + fx] = Figura::brak;
                        rc = 0;
                        k = Kolej::biale;
                        return true;
                    }
                    else return false;
                }
            }
            else return false;
        }
        else return false;
    }
}

Rezultat Plansza::result()
{
    bool spc = false, spb = false, sdc = false, sdb = false;
    if (rc >= 20) return Rezultat::re;
    for (int i = 0; i < 64; i++)
    {
        if (pola[i] == Figura::bd) sdb = true;
        else if (pola[i] == Figura::bp) spb = true;
        else if (pola[i] == Figura::cd) sdc = true;
        else if (pola[i] == Figura::cp) spc = true;
    }
    if (!spc && !sdc) return Rezultat::wb;
    if (!spb && !sdb) return Rezultat::wcz;
    return Rezultat::brak;
}
