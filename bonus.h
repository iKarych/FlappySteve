//
//  bonus.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/9/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef bonus_h
#define bonus_h


#include "ltexture.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_IMAGE/SDL_image.h>

class bonus
{
    int x,y,s;
    SDL_Rect cBonus;
public:
    int CWidth=gBonus.getWidth();
    int CHeight=gBonus.getHeight();
    static const int left=2;
    bonus(int _x=0,int _y=0,int _s=0);
    void render();
    void move();
    void setX(int _x);
    void setY(int _y);
    void setS(int _s);
    SDL_Rect col1();
    int getX();
    int getW();
    
};

bonus::bonus(int _x,int _y,int _s)
{
    x=_x;y=_y;s=_s;
}

void bonus::move()
{
    x-=left+s;
    
    cBonus.w=gBonus.getWidth();
    cBonus.h=gBonus.getHeight();
    cBonus.x=x;
    cBonus.y=y;
    
}

void bonus::render()
{
    gBonus.render(x,y);
}

void bonus::setX(int _x)
{
    x=_x;
}

void bonus::setY(int _y)
{
    y=_y;
}

SDL_Rect bonus::col1()
{
    return cBonus;
}

int bonus::getX()
{
    return x;
}

void bonus::setS(int _s)
{
    s=_s;
}


#endif /* bonus_h */
