#include "Monster.h"

Monster::Monster(std::string filename, GameEnvironment* gameEnvironment) : Entity(filename, gameEnvironment)
{
    m_sprite.setTexture(*m_gameEnvironment->textureManager->getTexture(filename));
    m_alive = true;
}

Monster::~Monster()
{
    //dtor
}

void Monster::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
    t.draw(m_sprite);
    (void)s;
}

