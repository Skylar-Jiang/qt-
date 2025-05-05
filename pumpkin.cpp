
#include "pumpkin.h"

Pumpkin::Pumpkin()
{
    hp = 2200;
    allHp = hp;
    setMovie(":/images/Pumpkin.gif");
    name = "Pumpkin";
}

void Pumpkin::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (hp <= int(allHp/3) && state != 2)
    {
        state = 2;
        setMovie(":/images/Pumpkin2.gif");
    }
    else if (int(allHp/3) < hp && hp <= int(2*allHp/3) && state != 1)
    {
        state = 1;
        setMovie(":/images/Pumpkin1.gif");
    }
}

