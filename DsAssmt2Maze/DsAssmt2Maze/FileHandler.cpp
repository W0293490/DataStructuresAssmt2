//
//  FileHandler.cpp
//  DsAssmt2Maze
//
//  Created by danielle ryall on 2017-02-13.
//  Copyright © 2017 w0293490. All rights reserved.
//

#include "FileHandler.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <time.h>

using namespace std;


void FileHandler::readWriteFile(ifstream & infile, ofstream & outfile)
{
    string data;
    while (getline(infile, data))
        {
            //erase all '\r's from file
            data.erase(remove(data.begin(), data.end(), '\r'), data.end());
            outfile << data << endl;
        }
}

int FileHandler::findNumberOfChars(const char * filename)
{
    int totalNumberOfChars;
        
    //http://stackoverflow.com/questions/9132151/how-to-find-number-of-characters-in-a-file-without-traversing-the-contents
    FILE*  file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    size_t  size = ftell(file);      // This is the size of the file.
    //    cout << "size is " << size << endl;
    // But note it is in bytes.
    // Also note if you are reading it into memory this is
    // is the value you want unless you plan to dynamically
    // convert the character encoding as you read.
    fseek(file, 0, SEEK_SET);        // Move the position back to the start.
        
    //http://stackoverflow.com/questions/11387370/how-can-i-safely-convert-unsigned-long-int-to-int
    stringstream ss;
    ss << size;
    string str = ss.str();
    totalNumberOfChars = atoi(str.c_str());
    return totalNumberOfChars;
        
}
    
int FileHandler::findNumberOfLines(const char * filename)
{
    //http://stackoverflow.com/questions/3482064/counting-the-number-of-lines-in-a-text-file
    int numberOfLines = 0;
    string line;
    ifstream myfile(filename);
    
    while (getline(myfile, line))
    {
        ++numberOfLines;
    }
        
    myfile.close();
    return numberOfLines;
}
    
void FileHandler::createSolvedMazeFile(string oFile, char** maze, int row, int col)
{
    ofstream finalFile;
        
    finalFile.open(oFile);
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            finalFile << maze[i][j];
        }
    }
        
    finalFile.close();
    
}
    
