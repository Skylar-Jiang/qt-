#include "wallnut.h"
#include <QDebug>

WallNut::WallNut()
{
    hp = 4000;
    allHp = hp;
    setMovie(":/images/WallNut.gif");
    name = "WallNut";
}

void WallNut::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (hp <= int(allHp/3) && state != 2)
    {
        state = 2;
        setMovie(":/images/WallNut2.gif");
    }
    else if (int(allHp/3) < hp && hp <= int(2*allHp/3) && state != 1)
    {
        state = 1;
        setMovie(":/images/WallNut1.gif");
    }
}
