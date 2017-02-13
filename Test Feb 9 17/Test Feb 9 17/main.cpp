//
//  main.cpp
//  Test Feb 9 17
//
//  Created by danielle ryall on 2017-02-09.
//  Copyright © 2017 w0293490. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <time.h>

using namespace std;


//https://ubuntuforums.org/showthread.php?t=1357606
int msleep(unsigned long milisec)
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


int main(int argc, char** argv) {
    
    
    char **maze;
    // row and col mimic count of lines from file
    // for demo set to 5x4
    int row = 0;
    int col = 0;
    
    
    //Open original file according to argv, delete /r's, the save it to new temp file.
    // open a file in read mode.
    ifstream infile;
    if (!strcmp(argv[1], "maze.txt"))
    {
        infile.open("maze.txt");
    }
    else if (!strcmp(argv[1], "maze2.txt"))
    {
        infile.open("maze2.txt");
    }
    else if (!strcmp(argv[1], "maze3.txt"))
    {
        infile.open("maze3.txt");
    }
    else if (!strcmp(argv[1], "maze4.txt"))
    {
        infile.open("maze4.txt");
    }
    else if (!strcmp(argv[1], "mazex.txt"))
    {
        infile.open("mazex.txt");
    }
    
    
    // open a file in write mode.
    ofstream outfile;
    outfile.open("temp.txt");
    
    // write data into the file.
    string data;
    while (getline(infile, data))
    {
        //erase all '\r's from file
        data.erase(remove(data.begin(), data.end(), '\r'), data.end());
        outfile << data << endl;
    }
    
    infile.close();
    outfile.close();
    
    
    string mazeText = "temp.txt";
    
    //find number of rows and cols.
    //http://stackoverflow.com/questions/9132151/how-to-find-number-of-characters-in-a-file-without-traversing-the-contents
    FILE*  file = fopen("temp.txt", "rb");
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
    int totalNumberOfChars = atoi(str.c_str());
    
    //http://stackoverflow.com/questions/3482064/counting-the-number-of-lines-in-a-text-file
    int numberOfLines = 0;
    string line;
    ifstream myfile("temp.txt");
    
    while (getline(myfile, line))
    {
        ++numberOfLines;
    }
    
    myfile.close();
    
    ifstream myfile3(mazeText);

//    cout << "Number of lines in text file: " << numberOfLines << endl;
    
    col = ((totalNumberOfChars - (numberOfLines - 1))  / (numberOfLines)) + 1;
    row = numberOfLines;
    
//    cout << "col = " << col << endl;
//    cout << "row = " << row << endl;
    
    myfile.close();
    
    
    // dynamically allocate an array
    // row = number of maze rows
    // col = line length
    maze = new char *[row];

    for (int count = 0; count < row; count++)
        {
            maze[count] = new char[col];
        }
        
    // load the elements in to the maze from the temp text file.
    fstream fin(mazeText);
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
    
//    cout << "The chosen coord is: " << maze[2][2] << endl;
    
    // Write them back out
    cout << "Here is your maze" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << maze[i][j];
        }
    }
    cout << endl << endl;
    
    //Set endpoint.
    maze[row-2][col-2] = 'F';
  
    //Create stack.
    stack<pair<int, int> > mazeStack;
    
//    long stackSize = mazeStack.size();
    
//    cout << "Size of stack is " << stackSize << endl;
    
    //Figure out solution...
    mazeStack.push(make_pair(1, 0));
    for (int i = 0; i < totalNumberOfChars; i++){
        pair<int, int> z = mazeStack.top();
        
        int x = z.first;
        int y = z.second;
    
        if (maze[x][y+1] == 'F') {
            mazeStack.push(make_pair(x, y+1));
            maze[x][y+1] = 'D';
            cout << "YOU MADE IT!!!!!" << endl;
            //replace '.'s with ' 's.
            for (int a = 0; a < row; a++) {
                for (int b = 0; b < col; b++) {
                    if (maze[a][b] == '*') {
                        maze[a][b] = ' ';
                    }
                }
            }
            break;
        }
        else if (maze[x][y+1] == ' ') {
            mazeStack.push(make_pair(x, y+1));
            maze[x][y+1] = 'o';
        }
        else if (maze[x+1][y] == ' ') {
            mazeStack.push(make_pair(x+1, y));
            maze[x+1][y] = 'o';
        }
        else if (maze[x][y-1] == ' ') {
            mazeStack.push(make_pair(x, y-1));
            maze[x][y-1] = 'o';
        }
        else if (maze[x-1][y] == ' ') {
            mazeStack.push(make_pair(x-1, y));
            maze[x-1][y] = 'o';
        }
        else{
            mazeStack.pop();
        }
        
//        cout << string(50, '\n');
        cout << "Here is your maze" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << maze[i][j];
            }
        }
        msleep(2);
        
    }
    
    //Get the contents of the stack...add stack solution coords to maze...
//    cout << "Here is the contents of the stack..." << endl;
    while(!mazeStack.empty())
    {
        pair<int, int> w = mazeStack.top();
//        cout << w.first << "," << w.second << endl;
        maze[w.first][w.second] = '#';
        mazeStack.pop();
    }
    
    cout << "Here is the solved maze:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << maze[i][j];
        }
    }
    cout << endl << endl;
    
    // open a file in write mode.
    ofstream finalFile;
    
    string oFile;
    if (!strcmp(argv[1], "maze.txt"))
    {
        oFile = "mazeSolved.txt";
    }
    else if (!strcmp(argv[1], "maze2.txt"))
    {
        oFile = "maze2Solved.txt";
    }
    else if (!strcmp(argv[1], "maze3.txt"))
    {
        oFile = "maze3Solved.txt";
    }
    else if (!strcmp(argv[1], "maze4.txt"))
    {
        oFile = "maze4Solved.txt";
    }
    else if (!strcmp(argv[1], "mazex.txt"))
    {
        oFile = "mazexSolved.txt";
    }
    
    finalFile.open(oFile);
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            finalFile << maze[i][j];
        }
    }
    
    
    
    
//    cout << "Deleting maze and terminating" << endl;
    
    
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
    
    
//    // Write them back out after deletion...
//    cout << "Here is your matrix or maze after deletionnnnnnnnnnnnn" << endl;
    
    
        return 0;
    }


