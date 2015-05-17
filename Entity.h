#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEnvironment.h"

class Entity : public sf::Drawable, public sf::Transformable
{
    public:
        Entity();
        Entity(std::string filename, GameEnvironment* gameEnvironment);
        Entity(std::string name, std::string filename, GameEnvironment* gameEnvironment);
        virtual ~Entity();

        std::string getName(){return m_name;};
        void setName(std::string name){m_name = name;};

        bool isAlive(){return m_alive;};
        void setAlive(bool alive);

        int getLevel(){return m_level;};
        void setLevel(int level){m_level = level;};

        int getDefense(){return m_defense;};
        void setDefense(int defense){m_defense = defense;};

        int getAttack(){return m_attack;};
        void setAttack(int attack){m_attack = attack;};

        int getSpeed(){return m_speed;};
        void setSpeed(int speed){m_speed = speed;};

        int getExperience(){return m_experience;};
        void setExperience(int experience){m_experience = experience;};

        int getHPMax(){return m_hpMax;};
        void setHPMax(int hpMax){m_hpMax = hpMax;};

        int getHP(){return m_currentHp;};
        void setHP(int hp){m_currentHp = hp;};

        sf::Vector2f getPosition() { return m_sprite.getPosition();};
        void setPosition(sf::Vector2f& pos){m_sprite.setPosition(pos);};

        sf::FloatRect getBounds() { return m_sprite.getGlobalBounds();};

    protected:

        std::string m_name;
        int m_level;
        int m_defense;
        int m_attack;
        int m_speed;
        int m_experience;
        int m_hpMax;
        int m_currentHp;
        GameEnvironment* m_gameEnvironment;
        sf::Sprite m_sprite;
        bool m_alive;

        virtual void draw(sf::RenderTarget& t, sf::RenderStates s) const;

    private:

};

#endif // ENTITY_H
