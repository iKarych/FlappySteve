//
//  load.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/5/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef load_h
#define load_h

#include "ltexture.h"

//Scene textures
LTexture gBGTexture;
LTexture gBMTexture;

Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gOutch = NULL;

Mix_Chunk *gSiri=NULL;

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
    
    if(!gOut.loadFromFile("out.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    
    //Load music
    gMusic = Mix_LoadMUS( "music.mp3" );
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    
    //Load sound effects
    gOutch = Mix_LoadWAV( "ouch.mp3" );
    if( gOutch == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    
    gSiri=Mix_LoadWAV( "siri.mp3" );
    if( gSiri == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    
    gFont = TTF_OpenFont( "sanfran.ttf", 50);
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    
    //Load sprite sheet texture
    if( !gSpriteSheetTexture.loadFromFile( "android.png" ) )
    {
        printf( "Failed to load walking animation texture!\n" );
        success = false;
    }
    else
    {
        //Set sprite clips
        gSpriteClips[ 0 ].x =   0;
        gSpriteClips[ 0 ].y =   0;
        gSpriteClips[ 0 ].w = 221;
        gSpriteClips[ 0 ].h = 200;
        
        gSpriteClips[ 1 ].x = 221;
        gSpriteClips[ 1 ].y =   0;
        gSpriteClips[ 1 ].w = 221;
        gSpriteClips[ 1 ].h = 205;
        
        gSpriteClips[ 2 ].x = 442;
        gSpriteClips[ 2 ].y =   0;
        gSpriteClips[ 2 ].w = 221;
        gSpriteClips[ 2 ].h = 205;

    }
    
    if(!gBMTexture.loadFromFile("plane.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    
    return success;
}


#endif /* load_h */
