//
//  Maze.hpp
//  DsAssmt2Maze
//
//  Created by danielle ryall on 2017-02-16.
//  Copyright © 2017 w0293490. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp


class Maze
{
public:
    
    char** buildMaze(int col, int row, const char * filename);
    
    void printMaze(int row, int col, char** maze);
    
    void deleteMaze(int row, int col, char** maze);
    
    
};

#endif /* Maze_hpp */
