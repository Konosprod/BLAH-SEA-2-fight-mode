#include "Cursor.h"

Cursor::Cursor(GameEnvironment* gameEnvironment, std::string filename, int indexMax) : m_gameEnvironment(gameEnvironment),
                                                                                       m_indexMax(indexMax)
{
    m_sprite.setTexture(*m_gameEnvironment->textureManager->getTexture(filename));
    m_currentIndex = 0;
    m_padding = 0;
    m_offset = 0;
}

Cursor::~Cursor()
{
    //dtor
}

void Cursor::nextIndex(Dir d)
{
    sf::Vector2f pos;

    if(d == Right)
    {
        ((m_currentIndex + 1) >= m_indexMax) ? m_currentIndex = 0 : m_currentIndex++;
    }
    else if(d == Left)
    {
        ((m_currentIndex - 1) <= 0) ? m_currentIndex = 0 : m_currentIndex--;
    }

    pos = m_sprite.getPosition();

    pos.x = m_padding + m_currentIndex * m_offset;

    m_sprite.setPosition(pos);
}

void Cursor::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
    t.draw(m_sprite);
    (void)s;
}
