//
//  showmenu.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/5/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef showmenu_h
#define showmenu_h

#include "lostmenu.h"
#include "load.h"

int showmenu(SDL_Window* screen)
{
    Uint32 time;
    int x,y;
    const int NUMMENU=2;
    const char* labels[NUMMENU]={"New Game(\"N\")","Exit(\"Esc\")"};
    LTexture menus[NUMMENU];
    bool selected[NUMMENU]={0,0};
    SDL_Color color[2]={{0,0,0},{255,0,0}};
    
    menus[0].loadFromRenderedText(labels[0],color[0]);
    menus[1].loadFromRenderedText(labels[1], color[0]);
    SDL_Rect pos[NUMMENU];
    for(int i=0;i<NUMMENU;i++)
    {
        pos[i].x=SCREEN_WIDTH/2-menus[i].getWidth()/2;
    }
    pos[0].y=SCREEN_HEIGHT/2;
    pos[1].y=SCREEN_HEIGHT/2+menus[0].getHeight();
    
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
                                menus[i].loadFromRenderedText(labels[i], color[1]);
                            }
                        }
                        else
                        {
                            if(selected[i])
                            {
                                selected[i]=false;
                                menus[i].free();
                                menus[i].loadFromRenderedText(labels[i], color[0]);
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
                                dot.setY(200);
                            dot.setVY();
                            cl.clear();
                            number=0;
                            
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
                                return 0;
                            }
                            else
                                return 1;
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
                    else if(event.key.keysym.sym==SDLK_n)
                    {
                        for(int i=0;i<NUMMENU;i++)
                        {
                            menus[i].free();
                        }
                        dot.setY(200);
                        dot.setVY();
                        cl.clear();
                        number=0;
                        
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
        gBMTexture.render(0, 0);
        for(int i=0;i<NUMMENU;i++)
        {
            menus[i].render( pos[i].x, pos[i].y );
            
            
        }
        SDL_RenderPresent(gRenderer);
        if(1000/30>(SDL_GetTicks()-time))
        {
            SDL_Delay(1000/30>(SDL_GetTicks()-time));
        }
    }
    
    
}

#endif /* showmenu_h */
