//
//  startover.h
//  Flappy_Steve
//
//  Created by Krzysztof on 6/6/16.
//  Copyright © 2016 Krzysztof. All rights reserved.
//

#ifndef startover_h
#define startover_h

#include "steve.h"
#include "google.h"
#include "android.h"
#include "bonus.h"
#include "load.h"
#include "text.h"

#include <vector>


extern steve dot;
extern droid robot;
extern bonus mark1, mark2;
extern choose wisely;
extern std::vector<column> cl;
extern std::vector<google> googles;
extern int number;
extern int anumber;
extern int cho;


void startover()
{
    dot.setY(240);
    dot.setVY();
    mark1.setX(500);
    mark2.setX(500);
    mark1.setY(SCREEN_HEIGHT/2-3*gBonus.getHeight());
    mark2.setY(SCREEN_HEIGHT/2+2*gBonus.getHeight());
    mark1.setS(0);mark2.setS(0);
    wisely.setX(200);wisely.setY(150);wisely.setS(0);wisely.loadT();
    cl.clear();
    googles.clear();
    number=0;
    anumber=0;
    cho=rand()%4;
    
    int n=640;
    int ng=640;
    int num=100;
    
    for(int i=0;i<num;i++)
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
    
    double a;
    robot.setX(ng);
    for(int i=0;i<6;i++)
    {
        google gogle;
        a=(rand()%100-50)/100.0;
        //a-=0.13;
        gogle.setA(a);
        gogle.setX(ng);
        googles.push_back(gogle);
    }



}

#endif /* startover_h */
