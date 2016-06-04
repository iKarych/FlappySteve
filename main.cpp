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

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_IMAGE/SDL_image.h>
//#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;


//Scene textures
LTexture gBGTexture;

bool init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                
                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    
    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;
    
    //Load dot texture
    if( !gDotTexture.loadFromFile( "steve.png" ) )
    {
        printf( "Failed to load dot texture!\n" );
        success = false;
    }
    
    //Load background texture
    if( !gBGTexture.loadFromFile( "bg.png" ) )
    {
        printf( "Failed to load background texture!\n" );
        success = false;
    }
    
    if(!gDColumnTexture.loadFromFile("co2.png"))
    {
        printf( "Failed to load down column texture!\n" );
        success = false;
    }
    
    if(!gUColumnTexture.loadFromFile("cou2.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    return success;
}

void close()
{
    //Free loaded images
    gDotTexture.free();
    gBGTexture.free();
    gDColumnTexture.free();
    gUColumnTexture.free();
    
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;
    
    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }
    
    if( topA >= bottomB )
    {
        return false;
    }
    
    if( rightA <= leftB )
    {
        return false;
    }
    
    if( leftA >= rightB )
    {
        return false;
    }
    
    //If none of the sides from A are outside B
    return true;
}


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
            
            //The dot that will be moving around on the screen
            steve dot;
            
            std::vector<column> cl;
            
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
            
            //The background scrolling offset
            int scrollingOffset = 0;
            
            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
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
                    
                    if(checkCollision(ball, wall1)==true)
                    {
                        quit=true;
                    }
                    else if(checkCollision(ball, wall2)==true)
                    {
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
                
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}