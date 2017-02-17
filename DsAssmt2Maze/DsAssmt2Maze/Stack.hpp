//
//  Stack.hpp
//  DsAssmt2Maze
//
//  Created by danielle ryall on 2017-02-13.
//  Copyright © 2017 w0293490. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <stack>

using namespace std;

class Stack
{
    
public:
    stack<pair<int, int> > mazeStack;
    
    void addStackNodesToMaze(char** maze, stack<pair<int, int> > mazeStack);
    
};

#endif /* Stack_hpp */
