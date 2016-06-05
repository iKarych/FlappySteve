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

LTexture gDColumnTexture;
LTexture gUColumnTexture;

class column
{
    int x,y1,y2;
    SDL_Rect mColumn1;
    SDL_Rect mColumn2;
public:
    int UP_CWidth=gUColumnTexture.getWidth();
    int UP_CHeight=gUColumnTexture.getHeight();
    int DN_CWidth=gDColumnTexture.getWidth();
    int DN_CHeight=gDColumnTexture.getHeight();
    static const int left=2;
    column(int _x=0,int _y1=0,int _y2=249);
    void render();
    void move();
    void setX(int _x);
    void setUY(int _y);
    void setDY(int _y);
    SDL_Rect col1();
    SDL_Rect col2();
    int getX();
    int getW();
    
};

column::column(int _x,int _y1,int _y2)
{
    x=_x;y1=_y1;y2=_y2;
    
    mColumn1.w=UP_CWidth; mColumn1.h=UP_CHeight;
    mColumn2.w=DN_CWidth; mColumn2.h=DN_CHeight;
}

void column::move()
{
    x-=left;
    
    mColumn1.x=x;
    mColumn1.y=y1;
    
    mColumn2.x=x;
    mColumn2.y=y2;
    
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

#endif /* column_h */
