#ifndef SKILL_H
#define SKILL_H

#include "Entity.h"
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

enum TargetType
{
    Self = -1,
    Monster = 1,
    Ally = 2,
    AllMonster = 3,
    AllAlly = 4
};

class Skill
{
    public:
        Skill();
        virtual ~Skill();

        void setTarget(Entity* target){m_target = target;};
        Entity* getTarget(){return m_target;};

        void setUser(Entity* user){m_user = user;};
        Entity* getUser(){return m_user;};

        void setBasePower(int basePower){m_basePower = basePower;};
        int getBasePower() const {return m_basePower;};

        sf::String getName() const;
        void setName(std::string name);

        bool needTarget() const {return m_needTarget;};
        void setTargetNeeded(bool b){m_needTarget = b;};

        void setCooldown(int cooldown){m_cooldown = cooldown;};
        int getCooldown() const {return m_cooldown;};

        void setCurrentCooldown(int cooldown){m_currentCooldown = cooldown;};
        int getCurrentCooldown() const {return m_currentCooldown;};

        TargetType getTargetType() const {return m_targetType;};
        void setTargetType(TargetType t){m_targetType = t;};

        void setDescription(std::string description);
        sf::String getDescription() const;

        void calculate();

    protected:

    private:
        Entity* m_target;
        Entity* m_user;
        sf::String m_name;
        bool m_needTarget;
        int m_basePower;
        int m_currentCooldown;
        int m_cooldown;
        sf::String m_description;
        TargetType m_targetType;
};

typedef std::vector<Skill> SkillList;

void loadSkillList(SkillList& l);
void printSkillList(SkillList l);
std::basic_string<sf::Uint32> toUtf32(std::string s);

#endif // SKILL_H
