#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics.hpp>
#include "GameEnvironment.h"
#include "Direction.h"

class Cursor : public sf::Drawable, public sf::Transformable
{
    public:
        Cursor(GameEnvironment* gameEnvironment, std::string filename, int indexMax = 0);
        virtual ~Cursor();

        int getIndex(){return m_currentIndex;};
        void setIndex(int index){m_currentIndex = index;};

        int getIndexMax(){return m_indexMax;};
        void setIndexMax(int index){m_indexMax = index;};

        void nextIndex(Dir d);

        void setPadding(int padding) {m_padding = padding;};
        int getPadding(){return m_padding;};

        void setOffset(int offset){m_offset = offset;};
        int getOffset(){return m_offset;};

        void setDefaultPosition(int x, int y){m_sprite.setPosition(x, y);};

    protected:

    private:
        GameEnvironment* m_gameEnvironment;
        sf::Sprite m_sprite;
        int m_indexMax;
        int m_currentIndex;
        int m_padding;
        int m_offset;

        void draw(sf::RenderTarget& t, sf::RenderStates s) const;
};

#endif // CURSOR_H
