#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"
#include <iostream>

class Monster : public Entity
{
    public:
        Monster(std::string filename, GameEnvironment* gameEnvironment);
        virtual ~Monster();

    protected:

    private:

    void draw(sf::RenderTarget& t, sf::RenderStates s) const;
};

#endif // MONSTER_H
