//
//  steve.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/4/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef steve_h
#define steve_h

#include "ltexture.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_IMAGE/SDL_image.h>

class steve
{
    int x,y;
    int vy;
    SDL_Rect mCollider;
    
public:
    int DOT_WIDTH = gDotTexture.getWidth();
    int DOT_HEIGHT = gDotTexture.getHeight();
    static const int DOT_VEL = 10;
    //constexpr static const
    double ACC = 2;
    steve(int _x=300,int _y=240,int _vy=0);
    void handleEvent(SDL_Event& e);
    void move();
    void render();
    SDL_Rect st();
    void setY(int _y);
    int getV();
    void setM(int _m);
    void setVY();
    int getX();
    
};

steve::steve(int _x,int _y,int _vy)
{
    x=_x;y=_y;
    vy=_vy;
}

void steve::handleEvent(SDL_Event& e)
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_SPACE: vy -= DOT_VEL; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_SPACE: vy += DOT_VEL; break;

        }
    }

}

void steve::move()
{    
    y +=vy+ACC;
    
    mCollider.w=gDotTexture.getWidth()-5;
    mCollider.h=gDotTexture.getHeight()-5;
    mCollider.x=x+5;
    mCollider.y=y+5;
    
    if( ( y < 0 ) || ( y + gDotTexture.getHeight() > SCREEN_HEIGHT ) )
    {
        //Move back
        y -=vy+ACC;
        mCollider.y = y;
    }

}

void steve::render()
{
    gDotTexture.render(x,y);
}


SDL_Rect steve::st()
{
    return mCollider;
}

void steve::setY(int _y)
{
    y=_y;
}

int steve::getV()
{
    return vy+ACC;
}

void steve::setM(int _m)
{
    mCollider.y=_m;
}

void steve::setVY()
{
    vy=0;
}

int steve::getX()
{
    return x;
}


#endif /* steve_h */
