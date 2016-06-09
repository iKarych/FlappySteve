//
//  google.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/7/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef google_h
#define google_h

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_IMAGE/SDL_image.h>
#include <cmath>

#include "ltexture.h"

class google
{
    double x,y;
    double a;
    SDL_Rect mCollider;
    
public:
    constexpr static const double ACC = 2.5;
    google(int _x=600,int _y=240);
    void render(int _i);
    void setX(int _x);
    void shoot();
    void setA(double a);
    void setWH(int _i);
    SDL_Rect getRect();
    
};

google::google(int _x,int _y)
{
    x=_x;y=_y;
}

void google::render(int _i)
{
    gGoogleTexture[_i].render(x,y);
}

void google::setX(int _x)
{
    x=_x;
}

void google::shoot()
{
    
    double velx=cos(a)*(double)ACC;
    double vely=sin(a)*(double)ACC;
    
    x-=velx;
    y-=vely;
    
    mCollider.x=x-5;
    mCollider.y=y-5;
   
}

void google::setA(double _a)
{
    a=_a;
}

void google::setWH(int _i)
{
    mCollider.h=gGoogleTexture[_i].getHeight()+5;
    mCollider.w=gGoogleTexture[_i].getWidth()+5;
}

SDL_Rect google::getRect()
{
    return mCollider;
}

#endif /* google_h */
