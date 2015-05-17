#ifndef PARTY_H
#define PARTY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <sstream>
#include "GameEnvironment.h"
#include "Member.h"

class Party : public sf::Drawable, public sf::Transformable
{
    public:
        Party(GameEnvironment* gameEnvironment);
        virtual ~Party();

        bool isDone() {return m_done;};
        void setDone(bool b){m_done = b;};
        void deleteMember(std::string name);
        void addMember(std::string name, std::string filename);
        int getCurrentMember();

        int size() {return m_members.size();};

        void nextMember();

        Member* getMember(std::string name){return m_members[name];};

    protected:

    private:
        std::map<std::string, Member*> m_members;
        GameEnvironment* m_gameEnvironment;
        int m_currentMember;
        bool m_done;

        virtual void draw(sf::RenderTarget& t, sf::RenderStates s) const;

};

#endif // PARTY_H
