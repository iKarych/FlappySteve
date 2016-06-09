//
//  text.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/9/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef text_h
#define text_h


#include "ltexture.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_IMAGE/SDL_image.h>

class choose
{
    int x,y,s;
public:
    static const int left=2;
    choose(int _x=0,int _y=0,int _s=0);
    void render();
    void move();
    void setX(int _x);
    void setY(int _y);
    void setS(int _s);
    void loadT();

    
};

choose::choose(int _x,int _y,int _s)
{
    x=_x;y=_y;s=_s;
}

void choose::move()
{
    x-=left+s;
    
}

void choose::render()
{
    gChoose.render(x,y);
}

void choose::setX(int _x)
{
    x=_x;
}

void choose::setY(int _y)
{
    y=_y;
}

void choose::setS(int _s)
{
    s=_s;
}

void choose::loadT()
{
    gChoose.loadFromRenderedText("Choose wisely", SDL_Color {0,0,0}, gSub);
}


#endif /* text_h */
