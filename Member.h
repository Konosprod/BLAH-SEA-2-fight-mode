#ifndef MEMBER_H
#define MEMBER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"

class Member : public Entity
{
    public:
        Member();
        Member(std::string name, std::string filename, GameEnvironment* gameEnvironment);
        virtual ~Member();

    protected:

    private:
};

#endif // MEMBER_H
