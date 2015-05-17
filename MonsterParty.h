#ifndef MONSTERPARTY_H
#define MONSTERPARTY_H

#include <vector>
#include <list>
#include <SFML/Graphics.hpp>
#include "Monster.h"
#include "GameEnvironment.h"

class MonsterParty : public sf::Drawable, public sf::Transformable
{
    public:
        MonsterParty(GameEnvironment* gameEnvironment);
        virtual ~MonsterParty();

        void addMonster(std::string filename);
        void deleteMonster(int index);

        Monster* getMonster(int index){return m_monsters[index];};

        int size(){return m_monsters.size();};

    protected:

    private:
        std::vector<Monster*> m_monsters;
        GameEnvironment* m_gameEnvironment;
        int m_count;

        void draw(sf::RenderTarget& t, sf::RenderStates s) const;

};

#endif // MONSTERPARTY_H
