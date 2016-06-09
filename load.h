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

#include <SDL2_MIXER/SDL_mixer.h>

//Constants
extern const int TOTAL_DATA;
extern const int WALKING_ANIMATION_FRAMES;

//Scene textures
extern LTexture gDColumnTexture;
extern LTexture gUColumnTexture;
extern LTexture gDotTexture;
extern LTexture gBGTexture;
extern LTexture gBMTexture;
extern LTexture gDataTextures[];
extern LTexture gGoogleTexture[];
extern LTexture gDroidTexture;
extern LTexture gName;
extern LTexture gSubtitle;
extern LTexture gChoose;
extern LTexture gMan;
extern LTexture gToilet;
extern LTexture gPause;
extern LTexture gCongrats;
extern LTexture gSound;
extern LTexture gMSound;
extern LTexture gBonus;
extern LTexture gOut;
extern LTexture count;
extern LTexture gSpriteSheetTexture;

//Music
extern Mix_Music *gMusic;
extern Mix_Chunk *gOutch;
extern Mix_Chunk *gSiri;

//Data
extern Sint32 gData[];

//Animation
extern SDL_Rect gSpriteClips[];

//Text rendering color
extern SDL_Color textColor;

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
    
    if(!gGoogleTexture[0].loadFromFile("g.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gGoogleTexture[1].loadFromFile("o1.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gGoogleTexture[2].loadFromFile("o2.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gGoogleTexture[3].loadFromFile("g2.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gGoogleTexture[4].loadFromFile("l.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gGoogleTexture[5].loadFromFile("e.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gDroidTexture.loadFromFile("droid.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gMan.loadFromFile("man.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gSound.loadFromFile("sound.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gMSound.loadFromFile("sound1.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gPause.loadFromFile("pause.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gCongrats.loadFromFile("congrats.png"))
    {
        printf( "Failed to load up column texture!\n" );
        success = false;
    }
    
    if(!gBonus.loadFromFile("question.png"))
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
    
    gFont = TTF_OpenFont( "sanfran.ttf", 40);
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    
    gScore = TTF_OpenFont("og.otf", 50);
    if( gScore == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    
    gNm = TTF_OpenFont("og.otf", 100);
    if( gNm == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    
    gSub = TTF_OpenFont("og1.otf", 150);
    if( gSub == NULL )
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
    
    SDL_RWops* file = SDL_RWFromFile( "nums.bin", "r+b" );
    if( file == NULL )
    {
        printf( "Warning: Unable to open file! SDL Error: %s\n", SDL_GetError() );
        
        //Create file for writing
        file = SDL_RWFromFile( "nums.bin", "w+b" );
        if( file != NULL )
        {
            printf( "New file created!\n" );
            
            //Initialize data
            for( int i = 0; i < TOTAL_DATA; ++i )
            {
                gData[ i ] = 0;
                SDL_RWwrite( file, &gData[ i ], sizeof(Sint32), 1 );
            }
            
            //Close file handler
            SDL_RWclose( file );
        }
        else
        {
            printf( "Error: Unable to create file! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
    }
    //File exists
    else
    {
        //Load data
        printf( "Reading file...!\n" );
        for( int i = 0; i < TOTAL_DATA; ++i )
        {
            SDL_RWread( file, &gData[ i ], sizeof(Sint32), 1 );
        }
        
        //Close file handler
        SDL_RWclose( file );
    }
    
    gDataTextures[ 0 ].loadFromRenderedText( std::to_string( (long)gData[ 0 ] ), textColor,gFont );
    for( int i = 1; i < TOTAL_DATA; ++i )
    {
        gDataTextures[ i ].loadFromRenderedText( std::to_string( (long)gData[ i ] ), textColor,gFont );
    }


    
    
    return success;
}




#endif /* load_h */
