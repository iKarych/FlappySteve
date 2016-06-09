//
//  android.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/7/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef android_h
#define android_h

#include "ltexture.h"

class droid
{
    int x,y;
public:
    constexpr static const double left=2;
    droid(int _x=0,int _y=240);
    void render();
    void move();
    void setX(int _x);
    void setY(int _y);
    SDL_Rect dro();
    int getX();
    
};

droid::droid(int _x,int _y)
{
    x=_x;y=_y;
}

void droid::move()
{
    
    x-=left;
}

void droid::render()
{
    gDroidTexture.render(x,y);
}

void droid::setX(int _x)
{
    x=_x;
}

void droid::setY(int _y)
{
    y=_y;
}

int droid::getX()
{
    return x;
}

#endif /* android_h */
