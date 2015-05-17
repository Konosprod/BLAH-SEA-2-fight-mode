#include "Member.h"

Member::Member()
{

}

Member::Member(std::string name, std::string filename, GameEnvironment* gameEnvironment) : Entity(name, filename, gameEnvironment)
{
    //m_sprite.setTexture(*m_gameEnvironment->textureManager->getTexture(filename));
}

Member::~Member()
{
    //dtor
}

