#include "sunflower.h"
#include <QDebug>

SunFlower::SunFlower()
{
    hp = 300;
    time = atk_speed(10.0);
    setMovie(":/images/SunFlower.gif");
    name = "SunFlower";
}

void SunFlower::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new Sun(pos()));
    }
}


