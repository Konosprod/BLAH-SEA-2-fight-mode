#ifndef GROUP_H
#define GROUP_H


#include <SFML/Graphics.hpp>
#include "Entity.h"


class Group : public sf::Drawable, public sf::Transformable
{
    public:
        Group();
        virtual ~Group();

        void printGroup();

        void addMember(Entity entity);
        void deleteMember(std::string name);

    protected:
        std::map<std::string, Entity*> m_entities;
        int m_currentMember;

    private:

        virtual void draw(sf::RenderTarget& t, sf::RenderStates s) const;
};

#endif // GROUP_H
