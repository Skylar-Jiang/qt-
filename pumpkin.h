#ifndef PUMPKIN_H
#define PUMPKIN_H

#include "plant.h"
#include "zombie.h"

class Pumpkin : public Plant
{
protected:
    int allHp;
public:
    Pumpkin();
    void advance(int phase) override;
};

#endif // PUMPKIN_H
