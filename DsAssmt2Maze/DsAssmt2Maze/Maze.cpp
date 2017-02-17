//
//  Maze.cpp
//  DsAssmt2Maze
//
//  Created by danielle ryall on 2017-02-16.
//  Copyright © 2017 w0293490. All rights reserved.
//

#include "Maze.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

    
char** Maze::buildMaze(int col, int row, const char * filename)
{
    char **maze;
    // dynamically allocate an array
    // row = number of maze rows
    // col = line length
    maze = new char *[row];
    
    for (int count = 0; count < row; count++)
    {
        maze[count] = new char[col];
    }
    
    // load the elements in to the maze from the temp text file.
    fstream fin(filename);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //No skipping white-space (noskipws)...
            fin >> noskipws >> maze[i][j];
            //            cout << maze[i][j];
        }
        
    }
    fin.close();
    return maze;
}
    
void Maze::printMaze(int row, int col, char** maze)
{
    // Write them back out
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << maze[i][j];
        }
    }
    cout << endl << endl;
    
}
    
void Maze::deleteMaze(int row, int col, char** maze)
{
    // To free the dynamically allocated memory
    // Delete each row pointer before deleting the array of pointers
    
    
    //    for (int i = 0; i < row; i++)
    //    {
    //        delete[] maze[i];
    //    }
    //    delete[] maze;
    //    maze = NULL;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            maze[i][j] = NULL; // delete stored pointer
        }
        delete[] maze[i]; // delete sub array
    }
    delete [] maze; //delete outer array
    maze = NULL;
    
}
