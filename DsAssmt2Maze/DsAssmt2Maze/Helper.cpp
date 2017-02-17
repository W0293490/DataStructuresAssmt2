//
//  Helper.cpp
//  DsAssmt2Maze
//
//  Created by danielle ryall on 2017-02-16.
//  Copyright © 2017 w0293490. All rights reserved.
//

#include "Helper.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <time.h>
#include <thread>

using namespace std;


    //https://ubuntuforums.org/showthread.php?t=1357606
int Helper::msleep(unsigned long milisec)
{
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;
    while(nanosleep(&req,&req)==-1)
        continue;
    return 1;
}
    
    
void Helper::ClearScreen()
{
    cout << string( 100, '\n' );
}

