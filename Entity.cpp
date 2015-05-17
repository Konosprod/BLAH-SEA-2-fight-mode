#include "Entity.h"

Entity::Entity()
{

}

Entity::Entity(std::string filename, GameEnvironment* gameEnvironment) : m_gameEnvironment(gameEnvironment)
{
    m_sprite.setTexture(*m_gameEnvironment->textureManager->getTexture(filename));
}

Entity::Entity(std::string name, std::string filename, GameEnvironment* gameEnvironment) : m_name(name), m_gameEnvironment(gameEnvironment)
{
    m_sprite.setTexture(*m_gameEnvironment->textureManager->getTexture(filename));
}

Entity::~Entity()
{
    //dtor
}

void Entity::setAlive(bool b)
{
    m_alive = b;

    if(!b)
    {
        m_sprite.setTexture(*m_gameEnvironment->textureManager->getTexture("rc/images/dead.png"));
    }
}


void Entity::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
    t.draw(m_sprite);
    (void)s;
}

