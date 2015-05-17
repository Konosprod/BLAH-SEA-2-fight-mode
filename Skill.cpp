#include "Skill.h"

Skill::Skill()
{
    //ctor
}

Skill::~Skill()
{
    //dtor
}

void Skill::calculate()
{
    //(((Niv x 0.4 + 2) x m_user*m_basePower)/(m_target->getDefense()*50)) + 2
}

std::basic_string<sf::Uint32> toUtf32(std::string s)
{
    std::basic_string<sf::Uint32> utf32;
    sf::Utf8::toUtf32(s.begin(), s.end(), std::back_inserter(utf32));

    return utf32;
}

void Skill::setDescription(std::string description)
{
    m_description = toUtf32(description);
}

void Skill::setName(std::string name)
{
    m_name = toUtf32(name);
}

void loadSkillList(SkillList& l)
{
    std::ifstream file("rc/data/skilllist.csv");
    std::string line;
    std::string value;
    std::string* listValue;
    int index = 0;

    while(std::getline(file, line))
    {
        Skill skill;
        listValue = new std::string[6];
        std::stringstream lineStream(line);

        while(std::getline(lineStream, value, ','))
        {
            listValue[index] = value;
            index++;
        }

        skill.setName(listValue[0]);
        skill.setBasePower(atoi(listValue[1].c_str()));
        skill.setTargetNeeded((atoi(listValue[2].c_str()) == 1) ? true : false);
        skill.setTargetType(static_cast<TargetType>(atoi(listValue[3].c_str())));
        skill.setCooldown(atoi(listValue[4].c_str()));
        skill.setDescription(listValue[5]);

        l.push_back(skill);

        index = 0;
        delete [] listValue;
    }
}

sf::String Skill::getName() const
{
    return m_name;
}

sf::String Skill::getDescription() const
{
    return m_description;
}

void printSkillList(SkillList l)
{
    SkillList::iterator itr(l.begin());

    for(;itr != l.end(); itr++)
    {
        std::cout << itr->getName().toAnsiString() << std::endl;
        std::cout << "Puissance : " << itr->getBasePower()
                  << " Target : " << itr->needTarget()
                  << " Target type : " << itr->getTargetType()
                  << " CD : " << itr->getCooldown()
                  << std::endl;
    }
}
