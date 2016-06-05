//
//  main.cpp
//  Flappy_Steve
//
//  Created by Krzysztof on 6/4/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#include "steve.h"
#include "ltexture.h"
#include "column.h"
#include "lostmenu.h"
#include "showmenu.h"
#include "initial.h"
#include "load.h"
#include "close.h"
#include "collision.h"
#include "pausemenu.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_IMAGE/SDL_image.h>
#include <SDL2_MIXER/SDL_mixer.h>
#include <SDL2_TTF/SDL_ttf.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

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
            

            int n=640;
            
            for(int i=0;i<100;i++)
            {       
                column c;
                
                int u=rand()%150-300;
                int d=u+370+120;
                int r=200;
                
                c.setX(n);
                c.setUY(u);
                c.setDY(d);
                
                cl.push_back(c);
                
                n+=r;
            }
            
            int i = showmenu(gWindow);
            if(i==1)
                quit=true;
            
            //The background scrolling offset
            int scrollingOffset = 0;
            
            //While application is running
            while( !quit )
            {
                //If there is no music playing
                if( Mix_PlayingMusic() == 0 )
                {
                    //Play the music
                    Mix_PlayMusic( gMusic, -1 );
                }
                
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
                    }
                    
                    //Handle input for the dot
                    dot.handleEvent( e );
                }
                
                //Move the dot
                dot.move();
                SDL_Rect ball=dot.st();
                for(auto it=cl.begin();it!=cl.end();++it)
                {
                    it->move();
                    SDL_Rect wall1=it->col1();
                    SDL_Rect wall2=it->col2();
                    
                    if(it->getX()==270)
                    {
                        Mix_PlayChannel( -1, gSiri, 0 );
                        number++;
                    }
                    
                    if(checkCollision(ball, wall1)==true)
                    {
                        Mix_PlayChannel( -1, gOutch, 0 );
                        int i=closemenu(gWindow);
                        if(i==1)
                        {
                            quit=true;
                        }
                    }
                    else if(checkCollision(ball, wall2)==true)
                    {
                        Mix_PlayChannel( -1, gOutch, 0 );
                        int i=closemenu(gWindow);
                        if(i==1)
                            quit=true;
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
                dot.render();
                for(auto it=cl.begin();it!=cl.end();++it)
                {
                    it->render();
                }
                
                std::string s = std::to_string(number);
                
                count.loadFromRenderedText(s, SDL_Color {0,0,0});
                count.render(0, 0);
                
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}