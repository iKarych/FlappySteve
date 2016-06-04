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

LTexture gDotTexture;


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class steve
{
    int x,y;
    int vy;
    SDL_Rect mCollider;
    
public:
    int DOT_WIDTH = gDotTexture.getWidth();
    int DOT_HEIGHT = gDotTexture.getHeight();
    static const int DOT_VEL = 10;
    constexpr static const double ACC = 2;
    steve(int _x=300,int _y=200,int _vy=0);
    void handleEvent(SDL_Event& e);
    void move();
    void render();
    SDL_Rect st();
    void setY(int _y);
    int getV();
    void setM(int _m);
    
};

steve::steve(int _x,int _y,int _vy)
{
    x=_x;y=_y;
    vy=_vy;
    mCollider.w=DOT_WIDTH; mCollider.h=DOT_HEIGHT;
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
    y += vy+ACC;
    
    mCollider.x=x;
    mCollider.y=y;
    
//    if( ( y < 0 ) || ( y + DOT_HEIGHT > SCREEN_HEIGHT ) || checkCollision( mCollider, wall ) )
//    {
//        //Move back
//        y -= vy;
//        mCollider.y = y;
//    }
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


#endif /* steve_h */
