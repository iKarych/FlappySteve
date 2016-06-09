//
//  pausemenu.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/5/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef pausemenu_h
#define pausemenu_h

#include "startover.h"

int pausemenu(SDL_Window* screen)
{
    Uint32 time;
    int x,y;
    const int NUMMENU=3;
    const char* labels[NUMMENU]={"New Game(\"N\")","Continue(\"C\")","Exit(\"Esc\")"};
    LTexture menus[NUMMENU];
    bool selected[NUMMENU]={0,0,0};
    SDL_Color color[2]={{0,0,0},{255,0,0}};
    
    menus[0].loadFromRenderedText(labels[0],color[0],gScore);
    menus[1].loadFromRenderedText(labels[1], color[0],gScore);
    menus[2].loadFromRenderedText(labels[2], color[0],gScore);
    SDL_Rect pos[NUMMENU];
    SDL_Rect so;
    for(int i=0;i<NUMMENU;i++)
    {
        pos[i].x=SCREEN_WIDTH/2-menus[i].getWidth()/2;
    }
    pos[0].y=SCREEN_HEIGHT/2-menus[0].getHeight();
    pos[1].y=SCREEN_HEIGHT/2;
    pos[2].y=SCREEN_HEIGHT/2+menus[0].getHeight();
    so.x=600; so.y=440;
    
    //SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));
    
    SDL_Event event;
    
    while(1)
    {
        time=SDL_GetTicks();
        
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    for(int i=0;i<NUMMENU;i++)
                    {
                        menus[i].free();
                    }
                    return 1;
                    break;
                case SDL_MOUSEMOTION:
                    x=event.motion.x;
                    y=event.motion.y;
                    for(int i=0;i<NUMMENU;i++)
                    {
                        if(x>=pos[i].x && x<=pos[i].x+menus[i].getWidth() && y>=pos[i].y && y<=pos[i].y+menus[i].getHeight())
                        {
                            if(!selected[i])
                            {
                                selected[i]=true;
                                menus[i].free();
                                menus[i].loadFromRenderedText(labels[i], color[1],gScore);
                            }
                        }
                        else
                        {
                            if(selected[i])
                            {
                                selected[i]=false;
                                menus[i].free();
                                menus[i].loadFromRenderedText(labels[i], color[0],gScore);
                            }
                        }
                    }break;
                case SDL_MOUSEBUTTONDOWN:
                    x=event.button.x;
                    y=event.button.y;
                    for(int i=0;i<NUMMENU;i++)
                    {
                        if(x>=pos[i].x && x<=pos[i].x+menus[i].getWidth() && y>=pos[i].y && y<=pos[i].y+menus[i].getHeight())
                        {
                            for(int j=0;j<NUMMENU;j++)
                            {
                                menus[j].free();
                            }
                            if(i==0)
                            {
                                startover();
                                return 0;
                            }
                            else if(i==1)
                                return 0;
                            else
                                return 1;
                        }
                    }
                    if(x>=so.x && x<=so.x+gSound.getWidth() && y>=so.y && y<=so.y+gSound.getHeight())
                    {
                        if( Mix_PausedMusic() == 1 )
                        {
                            //Resume the music
                            Mix_ResumeMusic();
                            
                        }
                        //If the music is playing
                        else if(Mix_PausedMusic()==0)
                        {
                            //Pause the music
                            Mix_PauseMusic();
                        }
                    }break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym==SDLK_ESCAPE)
                    {
                        for(int i=0;i<NUMMENU;i++)
                        {
                            menus[i].free();
                        }
                        return 1;
                    }
                    else if(event.key.keysym.sym==SDLK_c)
                    {
                        for(int i=0;i<NUMMENU;i++)
                        {
                            menus[i].free();
                        }
                        return 0;
                    }
                    else if(event.key.keysym.sym==SDLK_n)
                    {
                        for(int i=0;i<NUMMENU;i++)
                        {
                            menus[i].free();
                        }
                        startover();
                        return 0;
                    }
                    else if(event.key.keysym.sym==SDLK_p)
                    {
                        if( Mix_PausedMusic() == 1 )
                        {
                            //Resume the music
                            Mix_ResumeMusic();
                        }
                        //If the music is playing
                        else
                        {
                            //Pause the music
                            Mix_PauseMusic();
                        }
                    }
                    break;
                    
            }
        }
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );
        gMan.render((SCREEN_WIDTH-gMan.getWidth())/2,(SCREEN_HEIGHT-gMan.getHeight())/2);
        if(Mix_PausedMusic())
            gMSound.render(so.x, so.y);
        else if(Mix_PausedMusic()==0)
            gSound.render(so.x,so.y);
        for(int i=0;i<NUMMENU;i++)
        {
            menus[i].render( pos[i].x, pos[i].y );
            
            
        }
        std::string s = std::to_string(number);
        
        count.loadFromRenderedText(s, SDL_Color {0,0,0},gFont);
        count.render(0, 0);
        gDataTextures[0].loadFromRenderedText( "Highscore:"+std::to_string( (long)gData[0] ), textColor ,gFont);
        gToilet.loadFromRenderedText("Toilet Time", SDL_Color {0,153,76}, gNm);
        gDataTextures[0].render(0, 410);
        gToilet.render((SCREEN_WIDTH-gToilet.getWidth())/2, 60);
        
        
        SDL_RenderPresent(gRenderer);
        if(1000/30>(SDL_GetTicks()-time))
        {
            SDL_Delay(1000/30>(SDL_GetTicks()-time));
        }
    }
    
    
}


#endif /* pausemenu_h */
