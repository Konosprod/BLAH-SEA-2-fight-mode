#include "Party.h"

Party::Party(GameEnvironment* gameEnvironment) : m_gameEnvironment(gameEnvironment)
{
    m_currentMember = 0;
    m_done = false;
}

Party::~Party()
{
    std::map<std::string, Member*>::iterator itr(m_members.begin());

    for(; itr != m_members.end(); itr++)
    {
        delete m_members[itr->first];
    }
    m_members.clear();
}

void Party::addMember(std::string name, std::string filename)
{
    m_members[name] = new Member(name, filename, m_gameEnvironment);
}

void Party::deleteMember(std::string name)
{
    m_members[name]->setAlive(false);
}

void Party::nextMember()
{
    (((unsigned int)(m_currentMember + 1)) >= m_members.size()) ? m_currentMember = 0 : m_currentMember++;
}

int Party::getCurrentMember()
{
    return m_currentMember;
}

void Party::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
    std::ostringstream ss;
    sf::Vector2f pos;
    sf::Text te;
    sf::Font f;
    f.loadFromFile("rc/font/arial.ttf");
    te.setCharacterSize(14);
    te.setFont(f);
    te.setPosition(20, 40);

    pos.x = 10;
    pos.y = 10;

    std::map<std::string, Member*>::const_iterator itBegin(m_members.begin()),
                                                  itEnd(m_members.end());
    for(;itBegin != itEnd; itBegin++)
    {
        std::string details = itBegin->first;
        Member* m = itBegin->second;
        m->setHP(200);
        m->setHPMax(200);

        ss << m->getHP();
        std::string hp = ss.str();
        ss.str("");
        ss << m->getHPMax();
        std::string hpmax = ss.str();
        ss.str("");

        details += "\n" + hp + "/" + hpmax;
        te.setString(details);
        m->setPosition(pos);
        te.setPosition(m->getPosition().x + m->getBounds().width + 5, m->getPosition().y);
        t.draw(te);
        t.draw(*m);
        pos.x += 30 + m->getBounds().width + te.getGlobalBounds().width;
    }

    (void)s;
}

