#include "MonsterParty.h"

MonsterParty::MonsterParty(GameEnvironment* gameEnvironment) : m_gameEnvironment(gameEnvironment)
{
    m_count = 0;
}

MonsterParty::~MonsterParty()
{
    while(!m_monsters.empty())
    {
        Monster* m = m_monsters.back();
        m_monsters.pop_back();
        delete m;
    }
}

void MonsterParty::deleteMonster(int index)
{
    m_monsters.at(index)->setAlive(false);
}

void MonsterParty::addMonster(std::string filename)
{
    m_monsters.push_back(new Monster(filename, m_gameEnvironment));
}

void MonsterParty::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
    sf::Vector2f pos;

    pos.x = 20;
    pos.y = 200;

    for(unsigned int i = 0; i < m_monsters.size(); i++)
    {
        Monster* m = m_monsters.at(i);
        m->setPosition(pos);
        pos.x += m->getBounds().width;
        t.draw(*m);
    }

    (void)s;
}

