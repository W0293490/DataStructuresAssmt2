//
//  FileHandler.hpp
//  DsAssmt2Maze
//
//  Created by danielle ryall on 2017-02-13.
//  Copyright © 2017 w0293490. All rights reserved.
//

#ifndef FileHandler_hpp
#define FileHandler_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class FileHandler
{
public:
    
    void readWriteFile(ifstream & infile, ofstream & outfile);
    
    int findNumberOfChars(const char * filename);
    
    int findNumberOfLines(const char * filename);
    
    void createSolvedMazeFile(string oFile, char** maze, int row, int col);
    
    
    
};

#endif /* FileHandler_hpp */
