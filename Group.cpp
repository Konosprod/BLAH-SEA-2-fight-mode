#include "Group.h"

Group::Group()
{
    m_currentMember = 0;
}

Group::~Group()
{

}

void Group::addMember(Entity& entity)
{
    m_entities[entity.getName()] = entity;
}

void Group::deleteMember(std::string name)
{
    m_entities.erase(name);
}

void Group::printGroup()
{
    std::map<std::string, Entity>::const_iterator itBegin(m_entities.begin()),
                                                  itEnd(m_entities.end());

    for(;itBegin != itEnd; itBegin++)
    {
        std::cout << itBegin->first << std::endl;
    }
}

void Group::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
    (void)t;
    (void)s;
}

