#include "MenuSkill.h"

MenuSkill::MenuSkill(SkillList skillList, GameEnvironment* gameEnvironment) : m_gameEnvironment(gameEnvironment),
                                                                              m_skills(skillList)
{
    m_topBackground.setTexture(*m_gameEnvironment->textureManager->getTexture("rc/images/topbackground.png"));
    m_botBackground.setTexture(*m_gameEnvironment->textureManager->getTexture("rc/images/botbackground.png"));

    m_botBackground.setPosition(0, 399);

    m_font.loadFromFile("rc/font/arial.ttf");

    m_index = 0;

}

MenuSkill::~MenuSkill()
{
    //dtor
}

void MenuSkill::nextEntry(Dir d)
{
    switch(d)
    {
        case Up:
            if((m_index - 5) >= 0)
            {
                m_index -=5;
            }
        break;

        case Down:
            if((unsigned(m_index + 5)) < m_skills.size())
            {
                m_index+=5;
            }
        break;

        case Right:
            if((unsigned(m_index + 1)) < m_skills.size())
            {
                m_index++;
            }
        break;

        case Left:
            if((m_index - 1) >= 0)
            {
                m_index--;
            }
        break;

        default:
        break;
    }
}

void MenuSkill::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
    std::ostringstream ss;
    t.draw(m_topBackground);
    t.draw(m_botBackground);

    sf::Vector2f pos;
    sf::Text text("", m_font, 14);
    text.setPosition(20, 20);
    pos = text.getPosition();
    int padding = 0;

    for(unsigned int i = 0; i < m_skills.size(); i++)
    {
        if(i == ((unsigned)m_index))
        {
            text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        }
        else
        {
            text.setStyle(sf::Text::Regular);
        }

        text.setString(m_skills[i].getName());
        t.draw(text);
        padding++;
        pos.x = 20 + padding * 123;

        if(padding > 4)
        {
            padding = 0;
            pos.x = 20;
            pos.y += 30;
        }

        text.setPosition(pos);
    }

    text.setStyle(sf::Text::Regular);
    pos.x = 20;
    pos.y = 409;
    text.setColor(sf::Color::Red);
    text.setPosition(pos);

    ss << m_skills[m_index].getBasePower();
    std::string powa = ss.str();
    ss.str("");
    ss << m_skills[m_index].getCooldown();
    std::string cd = ss.str();
    ss.str("");

    text.setString(L"Nom : " + m_skills[m_index].getName() +
                   L"\nDescription : " + m_skills[m_index].getDescription() +
                   L"\nPuissance : " + powa +
                   L"\nCooldown : " + cd + " tours");

    t.draw(text);
    (void)s;
}
