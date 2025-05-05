#ifndef NEWSPAPERZOMBIE_H
#define NEWSPAPERZOMBIE_H

#include "zombie.h"
#include "plant.h"

class NewspaperZombie : public Zombie
{
private:
    bool newspaper;
public:
    NewspaperZombie();
    void advance(int phase) override;
};

#endif // NEWSPAPERZOMBIE_H