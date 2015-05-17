#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <vector>
#include "Random.h"
#include "Party.h"
#include "Monster.h"
#include "Member.h"
#include "GameEnvironment.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "MonsterParty.h"
#include "Cursor.h"
#include "Skill.h"
#include "MenuSkill.h"
#include "Direction.h"
#include "TurnQueue.h"

/*Formule : ( ( (Niv x 0.4 + 2) x Att x Pui ) / (Def x 50) ) + 2*/

enum GameState
{
    ChoseAction,
    ChoseTargetEnemy,
    ChoseTargetAlly,
    ChoseSkill,
    ActionDone
};

enum TextureType
{
    TextureBG,
    TextureTopMenu,
    TextureBottMenu,
    TextureMax
};

int main()
{
    sf::Event event;
    int index = 0;
    GameState state = ChoseAction;
    GameEnvironment gameEnvironment;
    SoundManager soundManager;
    TextureManager textureManager;
    SkillList skillList;
    //TurnQueue turnQueue;
    sf::Font font;
    sf::Sprite s[TextureMax];
    sf::Text texts[4];
    sf::RenderWindow window(sf::VideoMode(910, 512), "Combat!");

    gameEnvironment.soundManager = &soundManager;
    gameEnvironment.textureManager = &textureManager;
    gameEnvironment.window = &window;

    MonsterParty monsterParty(&gameEnvironment);
    Party party(&gameEnvironment);
    Cursor cursorTarget(&gameEnvironment, "rc/images/cursor.png", 2);

    loadSkillList(skillList);

    MenuSkill menuSkill(skillList, &gameEnvironment);

    window.setFramerateLimit(60);

    s[TextureBG].setTexture(*textureManager.getTexture("rc/images/background.png"));
    s[TextureBottMenu].setTexture(*textureManager.getTexture("rc/images/menu-bot.png"));
    s[TextureTopMenu].setTexture(*textureManager.getTexture("rc/images/menu-top.png"));
    font.loadFromFile("rc/font/arial.ttf");


    texts[0].setString(L"Attaque");
    texts[1].setString(L"Garde");
    texts[2].setString(L"Spécial");
    texts[3].setString(L"Talent");

    texts[0].setPosition(50, 406);
    texts[1].setPosition(480, 406);
    texts[2].setPosition(50, 460);
    texts[3].setPosition(480, 460);

    for(int i = 0; i < 4; i++)
    {
        texts[i].setFont(font);
        texts[i].setColor(sf::Color::Blue);
        texts[i].setCharacterSize(14);
    }

    s[TextureBottMenu].setPosition(0, s[TextureTopMenu].getGlobalBounds().height + s[TextureBG].getGlobalBounds().height);
    s[TextureBG].setPosition(0, s[TextureTopMenu].getGlobalBounds().height);
    texts[index].setStyle(sf::Text::Bold | sf::Text::Underlined);

    monsterParty.addMonster("rc/images/zombie.png");
    monsterParty.addMonster("rc/images/zombie-2.png");
    monsterParty.addMonster("rc/images/zombie.png");

    cursorTarget.setIndexMax(monsterParty.size());

    party.addMember("Elliot", "rc/images/face-1.png");
    party.addMember("James", "rc/images/face-2.png");
    party.addMember("Jean", "rc/images/face-1.png");
    party.addMember("Phil", "rc/images/face-2.png");

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                break;

                case sf::Event::KeyReleased:
                    if(event.key.code == sf::Keyboard::Return)
                    {
                        if(state == ChoseAction)
                        {
                            if(index == 0)
                            {
                                state = ChoseTargetEnemy;
                                cursorTarget.setPadding(20);
                                cursorTarget.setOffset(34);
                                cursorTarget.setDefaultPosition(20, 168);
                            }
                            if(index == 2)
                            {
                                state = ChoseSkill;
                            }

                            if(index == 1)
                            {
                                //state = ChoseTargetEnemy;
                            }

                        }
                        else if(state == ChoseSkill)
                        {
                            if(menuSkill.getSkill().getTargetType() == Monster)
                            {
                                state = ChoseTargetEnemy;
                                cursorTarget.setPadding(20);
                                cursorTarget.setOffset(34);
                                cursorTarget.setDefaultPosition(20, 168);
                            }
                            if(menuSkill.getSkill().getTargetType() == Ally)
                            {
                                state = ChoseTargetAlly;
                                cursorTarget.setPadding(20);
                                cursorTarget.setOffset(150);
                                cursorTarget.setDefaultPosition(20, 0);
                                cursorTarget.setIndexMax(party.size());
                                cursorTarget.setIndex(0);
                            }
                        }
                        else if(state == ChoseTargetEnemy)
                        {
                            if(monsterParty.getMonster(cursorTarget.getIndex())->isAlive())
                            {
                                //Monster* monster = monsterParty.getMonster(cursorTarget.getIndex());
                                //party.getCurrentMember();
                                //party.nextMember();
                                //state = ChoseAction;
                                monsterParty.deleteMonster(cursorTarget.getIndex());
                                cursorTarget.setIndex(0);
                                state = ChoseAction;
                            }
                        }
                    }

                    if(event.key.code == sf::Keyboard::Down)
                    {
                        if(state == ChoseAction)
                        {
                            if((index + 2) <= 3)
                            {
                                texts[index].setStyle(sf::Text::Regular);
                                index+=2;
                            }
                        }

                        if(state == ChoseSkill)
                        {
                            menuSkill.nextEntry(Down);
                        }
                    }

                    if(event.key.code == sf::Keyboard::Left)
                    {
                        if(state == ChoseAction)
                        {
                            if((index == 1) || (index == 3))
                            {
                                texts[index].setStyle(sf::Text::Regular);
                                index--;
                            }
                        }
                        if(state == ChoseTargetEnemy || state == ChoseTargetAlly)
                        {
                            cursorTarget.nextIndex(Left);
                        }

                        if(state == ChoseSkill)
                        {
                            menuSkill.nextEntry(Left);
                        }
                    }

                    if(event.key.code == sf::Keyboard::Right)
                    {
                        if(state == ChoseAction)
                        {
                            if((index == 0) || (index == 2))
                            {
                                texts[index].setStyle(sf::Text::Regular);
                                index++;
                            }
                        }
                        if(state == ChoseTargetEnemy || state == ChoseTargetAlly)
                        {
                            cursorTarget.nextIndex(Right);
                        }

                        if(state == ChoseSkill)
                        {
                            menuSkill.nextEntry(Right);
                        }
                    }

                    if(event.key.code == sf::Keyboard::Up)
                    {
                        if(state == ChoseAction)
                        {
                            if((index - 2) >= 0)
                            {
                                texts[index].setStyle(sf::Text::Regular);
                                index-=2;
                            }
                        }

                        if(state == ChoseSkill)
                        {
                            menuSkill.nextEntry(Up);
                        }
                    }

                    if(event.key.code == sf::Keyboard::Escape)
                    {
                        if(state == ChoseTargetAlly || state == ChoseTargetEnemy)
                        {
                            state = ChoseAction;
                        }
                    }

                    if(state == ChoseAction)
                    {
                        texts[index].setStyle(sf::Text::Bold | sf::Text::Underlined);
                    }
                break;

                default:
                break;
            }
        }

        window.clear();

        if(state == ChoseAction)
        {
            for(int i = 0; i < TextureMax; i++)
            {
                window.draw(s[i]);
            }

            for(int i = 0; i < 4; i++)
            {
                window.draw(texts[i]);
            }

            window.draw(party);
            window.draw(monsterParty);
        }
        else if(state == ChoseTargetEnemy)
        {
            for(int i = 0; i < TextureMax; i++)
            {
                window.draw(s[i]);
            }

            window.draw(party);
            window.draw(monsterParty);
            window.draw(cursorTarget);
        }
        else if(state == ChoseSkill)
        {
            window.draw(menuSkill);
        }
        else if(state == ChoseTargetAlly)
        {
            for(int i = 0; i < TextureMax; i++)
            {
                window.draw(s[i]);
            }

            window.draw(party);
            window.draw(monsterParty);
            window.draw(cursorTarget);
        }
        window.display();
    }

    return 0;
}

