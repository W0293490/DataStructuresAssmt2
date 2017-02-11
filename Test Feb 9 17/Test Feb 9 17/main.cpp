//
//  main.cpp
//  Test Feb 9 17
//
//  Created by danielle ryall on 2017-02-09.
//  Copyright © 2017 w0293490. All rights reserved.
//

#include <iostream>

#include <fstream>

#include <vector>

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>

#include <sstream>
#include <stdlib.h>

//#include "stdafx.h"

using namespace std;


int main(int argc, char** argv) {
    
    string mazeText = "m.txt";
    fstream fin(mazeText);
    char **maze;
    // row and col mimic count of lines from file
    // for demo set to 5x4
    int row = 0;
    int col = 0;
    
    
    //http://stackoverflow.com/questions/9132151/how-to-find-number-of-characters-in-a-file-without-traversing-the-contents
    FILE*  file = fopen("m.txt", "rb");
    fseek(file, 0, SEEK_END);
    size_t  size = ftell(file);      // This is the size of the file.
    cout << "size is " << size << endl;
    // But note it is in bytes.
    // Also note if you are reading it into memory this is
    // is the value you want unless you plan to dynamically
    // convert the character encoding as you read.
    
    fseek(file, 0, SEEK_SET);        // Move the position back to the start.
    

   //http://stackoverflow.com/questions/11387370/how-can-i-safely-convert-unsigned-long-int-to-int
    stringstream ss;
    ss << size;
    string str = ss.str();
    int totalNumberOfChars = atoi(str.c_str());
    
    //http://stackoverflow.com/questions/3482064/counting-the-number-of-lines-in-a-text-file
    int numberOfLines = 0;
    string line;
    ifstream myfile(mazeText);
    
    while (getline(myfile, line))
    {
        ++numberOfLines;
    }
    cout << "Number of lines in text file: " << numberOfLines << endl;
    
    col = ((totalNumberOfChars - (numberOfLines - 1))  / (numberOfLines)) + 1;
//    col = ((totalNumberOfChars - ((numberOfLines * 2) - 1))  / (numberOfLines)) + 3;
    
    row = numberOfLines;
    
    cout << "col = " << col << endl;
    cout << "row = " << row << endl;
    
    myfile.close();
    
    

//    col = 7;
//    row = 4;
    
    // dynamically allocate an array
    // row = number of maze rows
    // col = line length
    
    maze = new char *[row];

    for (int count = 0; count < row; count++)
        {
            maze[count] = new char[col];
        }
        
        // load the elements in to the maze
//        cout << endl << "Now enter the element for the maze...";
    
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //No skipping white-space (noskipws)...
            fin >> noskipws >> maze[i][j];
            cout << maze[i][j];
        }
//           cout << endl;
            
    }
    
    
    cout << endl << endl;
    cout << "The chosen coord is: " << maze[3][2] << endl;
        
    // Write them back out
    
    cout << "Here is your matrix or maze" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << maze[i][j];
            
            
        }
    }
    cout << endl << endl << endl;
    
    
    fin.close();
    
    cout << "Deleting maze and terminating" << endl;

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
//    maze = NULL;
    
    // Write them back out after deletion...
    cout << "Here is your matrix or maze after deletion" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << maze[i][j];
            
        }
    }
    cout << endl << endl << endl;
    
    
    
        return 0;
    }

