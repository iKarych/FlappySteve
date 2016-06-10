//
//  main.cpp
//  Flappy_Steve
//
//  Created by Krzysztof on 6/4/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_IMAGE/SDL_image.h>
#include <SDL2_MIXER/SDL_mixer.h>
#include <SDL2_TTF/SDL_ttf.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "load.h"
#include "steve.h"
#include "ltexture.h"
#include "column.h"
#include "lostmenu.h"
#include "showmenu.h"
#include "initial.h"
#include "close.h"
#include "collision.h"
#include "pausemenu.h"
#include "google.h"
#include "winmenu.h"
#include "bonus.h"
#include "text.h"

//Numbers
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int TOTAL_DATA = 1;
const int WALKING_ANIMATION_FRAMES = 3;
int number=0;
int anumber=0;
int cho;

//Vectors
std::vector<column> cl;         //Vector of columns
std::vector<google> googles;    //Vector of Google letters

//Window
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Fonts
TTF_Font *gFont = NULL;
TTF_Font *gScore=NULL;
TTF_Font *gNm=NULL;
TTF_Font *gSub=NULL;

//Scene textures
LTexture gDColumnTexture;
LTexture gUColumnTexture;
LTexture gDotTexture;
LTexture gBGTexture;
LTexture gBMTexture;
LTexture gDataTextures[ TOTAL_DATA ];
LTexture gGoogleTexture[6];
LTexture gDroidTexture;
LTexture gName;
LTexture gSubtitle;
LTexture gChoose;
LTexture gMan;
LTexture gToilet;
LTexture gPause;
LTexture gCongrats;
LTexture gSound;
LTexture gMSound;
LTexture gBonus;
LTexture gOut;
LTexture count;
LTexture gSpriteSheetTexture;

//Music
Mix_Music *gMusic = NULL;
Mix_Chunk *gOutch = NULL;
Mix_Chunk *gSiri=NULL;

//Data
Sint32 gData[ TOTAL_DATA ];

//Animation
SDL_Rect gSpriteClips[ WALKING_ANIMATION_FRAMES ];

//Text rendering color
SDL_Color textColor = { 0, 0, 0, 0xFF };

//Classes
steve dot;              //Hero
droid robot;            //Villain
bonus mark1, mark2;     //Question marks
choose wisely;          //Text

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;
            
            //Event handler
            SDL_Event e;
            
            srand(time(NULL));
            
            SDL_Rect pa;
            pa.x=600; pa.y=0;
            
            int i = showmenu(gWindow);
            if(i==1)
                quit=true;
            
            //The background scrolling offset
            int scrollingOffset = 0;
            
            //While application is running
            while( !quit )
            {
                
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    switch(e.type)
                    {
                        case SDL_QUIT:
                            quit=true;
                            break;
                        case SDL_KEYDOWN:
                            switch(e.key.keysym.sym)
                            {
                                case SDLK_ESCAPE:
                                    int i=pausemenu(gWindow);
                                    if(i==1)
                                    {
                                        quit=true;
                                    }
                                    break;
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            int x=e.button.x;
                            int y=e.button.y;
                            if(x>=pa.x && x<=pa.x+gPause.getWidth() && y>=pa.y && y<=pa.y+gPause.getHeight())
                            {
                                int i=pausemenu(gWindow);
                                if(i==1)
                                {
                                    quit=true;
                                }
                            }break;
                            
                    }
                    
                    //Handle input for steve
                    dot.handleEvent( e );
                }
                
                dot.move();
                mark1.move();
                mark2.move();
                wisely.move();
                SDL_Rect ball=dot.st();
                SDL_Rect bmark1=mark1.col1();
                SDL_Rect bmark2=mark2.col1();

                for(auto it=cl.begin();it!=cl.end();++it)
                {
                    it->move();
                    SDL_Rect wall1=it->col1();
                    SDL_Rect wall2=it->col2();
                    
                    if(it->getX()==270)
                    {
                        Mix_PlayChannel( -1, gSiri, 0 );
                        number++;
                        anumber++;
                    }

                    
                    if(checkCollision(ball, wall1)==true)
                    {
                        Mix_PlayChannel( -1, gOutch, 0 );
                        if(gData[0]<number)
                        {
                            gData[0]=number;
                        }
                        int i=closemenu(gWindow);
                        if(i==1)
                        {
                            quit=true;
                        }
                    }
                    else if(checkCollision(ball, wall2)==true)
                    {
                        
                        Mix_PlayChannel( -1, gOutch, 0 );
                        if(gData[0]<number)
                        {
                            gData[0]=number;
                        }
                        int i=closemenu(gWindow);
                        if(i==1)
                            quit=true;
                    }
                    
                }
                if(checkCollision(ball, bmark1))
                {
                    
                    if(cho==0)
                    {
                        for(auto it=cl.begin();it!=cl.end();++it)
                        {
                            it->setS(-1);
                            mark1.setS(-1);
                            mark2.setS(-1);
                            wisely.setS(-1);
                            mark1.setX(-100);
                        }
                    }
                    else if(cho==1)
                    {
                        Mix_PlayChannel( -1, gOutch, 0 );
                        int i=closemenu(gWindow);
                        if(i==1)
                            quit=true;
                    }
                    else if(cho==2)
                    {
                        number+=5;
                        mark1.setX(-100);
                    }
                    else if(cho==3)
                    {
                        number-=25;
                        mark1.setX(-100);
                    }

                    
                }
                if(checkCollision(ball, bmark2))
                {
                    
                    if(cho==0)
                    {
                        for(auto it=cl.begin();it!=cl.end();++it)
                        {
                            it->setS(-1);
                            mark1.setS(-1);
                            mark2.setS(-1);
                            wisely.setS(-1);
                            mark2.setX(-100);
                        }
                    }
                    else if(cho==1)
                    {
                        Mix_PlayChannel( -1, gOutch, 0 );
                        int i=closemenu(gWindow);
                        if(i==1)
                            quit=true;
                    }
                    else if(cho==2)
                    {
                        number+=5;
                        mark2.setX(-100);
                    }
                    else if(cho==3)
                    {
                        number-=25;
                        mark2.setX(-100);
                    }
                }
                
                if(anumber==cl.size())
                {
                    robot.move();
                    if(robot.getX()==200)
                    {
                        number+=5;
                        int i=winmenu(gWindow);
                        if(i==1)
                        {
                            quit=true;
                        }
                        
                    }
                    for(auto itr=googles.begin();itr!=googles.end();++itr)
                    {
                        itr->shoot();
                        SDL_Rect letter=itr->getRect();
                        
                        if(checkCollision(ball, letter))
                        {
                            Mix_PlayChannel( -1, gOutch, 0 );
                            if(gData[0]<number)
                            {
                                gData[0]=number;
                            }
                            int i=closemenu(gWindow);
                            if(i==1)
                            {
                                quit=true;
                            }
                        }
                    }
                }
            
                //Scroll background
                --scrollingOffset;
                if( scrollingOffset < -gBGTexture.getWidth() )
                {
                    scrollingOffset = 0;
                }
                
                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );
                
                //Render background
                gBGTexture.render( scrollingOffset, 0 );
                gBGTexture.render( scrollingOffset + gBGTexture.getWidth(), 0 );
                
                //Render objects
                wisely.render();
                dot.render();
                robot.render();
                mark1.render();
                mark2.render();
                for(auto it=cl.begin();it!=cl.end();++it)
                {
                    it->render();
                }
                
                int ggle=0;
                for(auto it=googles.begin();it!=googles.end();it++)
                {
                    it->render(ggle);
                    it->setWH(ggle);
                    ggle++;
                }
                
                std::string s = std::to_string(number);
                
                count.loadFromRenderedText(s, SDL_Color {0,0,0},gFont);
                count.render(0, 0);
                gPause.render(pa.x, pa.y);
                
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}