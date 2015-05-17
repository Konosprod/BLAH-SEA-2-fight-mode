#ifndef MENUSKILL_H
#define MENUSKILL_H

#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Skill.h"
#include "GameEnvironment.h"

class MenuSkill : public sf::Drawable, public sf::Transformable
{
    public:
        MenuSkill(SkillList skillList, GameEnvironment* gameEnvironment);
        virtual ~MenuSkill();

        void nextEntry(Dir d);

        Skill getSkill(){return m_skills[m_index];};

    protected:

    private:
        GameEnvironment* m_gameEnvironment;
        SkillList m_skills;
        sf::Font m_font;
        sf::Sprite m_topBackground;
        sf::Sprite m_botBackground;
        int m_index;

        virtual void draw(sf::RenderTarget& t, sf::RenderStates s) const;
};

#endif // MENUSKILL_H
