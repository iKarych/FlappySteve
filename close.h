//
//  close.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/5/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef close_h
#define close_h

void close()
{
    //Open data for writing
    SDL_RWops* file = SDL_RWFromFile( "nums.bin", "w+b" );
    if( file != NULL )
    {
        //Save data
        for( int i = 0; i < TOTAL_DATA; ++i )
        {
            SDL_RWwrite( file, &gData[ i ], sizeof(Sint32), 1 );
        }
        
        //Close file handler
        SDL_RWclose( file );
    }
    else
    {
        printf( "Error: Unable to save file! %s\n", SDL_GetError() );
    }
    
    //Free loaded images
    gDotTexture.free();
    gBGTexture.free();
    gDColumnTexture.free();
    gUColumnTexture.free();
    gDroidTexture.free();
    gMan.free();
    gSound.free();
    gMSound.free();
    gPause.free();
    gBonus.free();
    gChoose.free();
    gBMTexture.free();
    gDataTextures[1].free();
    gName.free();
    gSubtitle.free();
    gToilet.free();
    gPause.free();
    gCongrats.free();
    gMSound.free();
    gOut.free();
    count.free();
    gSpriteSheetTexture.free();
    for(int i=0;i<6;i++)
    {
        gGoogleTexture[i].free();
    }
    
    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;
    TTF_CloseFont( gScore );
    gScore = NULL;
    TTF_CloseFont( gNm );
    gNm = NULL;
    TTF_CloseFont( gSub );
    gSub = NULL;
    
    //Free the music
    Mix_FreeMusic( gMusic );
    gMusic = NULL;
    Mix_FreeChunk( gOutch );
    gOutch=NULL;
    Mix_FreeChunk( gSiri );
    gSiri=NULL;
    
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    
    //Quit SDL subsystems
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
}

#endif /* close_h */
