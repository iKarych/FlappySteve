//
//  column.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/4/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef column_h
#define column_h

#include "ltexture.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_IMAGE/SDL_image.h>

class column
{
    int x,y1,y2,s;
    SDL_Rect mColumn1;
    SDL_Rect mColumn2;
public:
    int UP_CWidth=gUColumnTexture.getWidth();
    int UP_CHeight=gUColumnTexture.getHeight();
    int DN_CWidth=gDColumnTexture.getWidth();
    int DN_CHeight=gDColumnTexture.getHeight();
    static const int left=2;
    column(int _x=0,int _y1=0,int _y2=249,int _s=0);
    void render();
    void move();
    void setX(int _x);
    void setUY(int _y);
    void setDY(int _y);
    void setS(int _s);
    SDL_Rect col1();
    SDL_Rect col2();
    int getX();
    int getW();
    
};

column::column(int _x,int _y1,int _y2,int _s)
{
    x=_x;y1=_y1;y2=_y2;s=_s;
    
    mColumn1.w=UP_CWidth-5; mColumn1.h=UP_CHeight-5;
    mColumn2.w=DN_CWidth-5; mColumn2.h=DN_CHeight-5;
}

void column::move()
{
    x-=left+s;
    
    mColumn1.x=x+5;
    mColumn1.y=y1+5;
    
    mColumn2.x=x+5;
    mColumn2.y=y2+5;
    
}

void column::render()
{
    gUColumnTexture.render(x,y1);
    gDColumnTexture.render(x,y2);
}

void column::setX(int _x)
{
    x=_x;
}

void column::setUY(int _y)
{
    y1=_y;
}

void column::setDY(int _y)
{
    y2=_y;
}

SDL_Rect column::col1()
{
    return mColumn1;
}

SDL_Rect column::col2()
{
    return mColumn2;
}

int column::getX()
{
    return x;
}

void column::setS(int _s)
{
    s=_s;
}

#endif /* column_h */
