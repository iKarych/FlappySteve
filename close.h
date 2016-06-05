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
    //Free loaded images
    gDotTexture.free();
    gBGTexture.free();
    gDColumnTexture.free();
    gUColumnTexture.free();
    
    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;
    
    //Free the music
    Mix_FreeMusic( gMusic );
    gMusic = NULL;
    
    Mix_FreeChunk( gOutch );
    gOutch=NULL;
    
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
