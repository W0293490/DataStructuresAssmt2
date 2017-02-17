//
//  Stack.cpp
//  DsAssmt2Maze
//
//  Created by danielle ryall on 2017-02-13.
//  Copyright © 2017 w0293490. All rights reserved.
//

#include "Stack.hpp"

using namespace std;


    stack<pair<int, int> > mazeStack;
    
void Stack::addStackNodesToMaze(char** maze, stack<pair<int, int> > mazeStack)
{
    while(mazeStack.empty())
    {
        pair<int, int> w = mazeStack.top();
        //        cout << w.first << "," << w.second << endl;
        maze[w.first][w.second] = '#';
        mazeStack.pop();
    }
    
}
    


