#ifndef WALLNUT_H
#define WALLNUT_H

#include "plant.h"

class WallNut : public Plant
{
private:
    int allHp;
public:
    WallNut();
    void advance(int phase) override;
};

#endif // WALLNUT_H
