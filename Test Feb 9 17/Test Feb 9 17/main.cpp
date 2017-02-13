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
#include "stacknode.hpp"
#include "stdafx.hpp"
#include <iostream>
#include <stack>

//#include "stdafx.h"

using namespace std;

//ostream & operator<<(ostream & os, stack<pair<int, int> > mazeStack) //function header
//{
//    while(!mazeStack.empty()) //body
//    {
//        os << &mazeStack.top() << " ";
//        mazeStack.pop();
//    }
//    return os; // end of function
//}


int main(int argc, char** argv) {
    
    
    char **maze;
    // row and col mimic count of lines from file
    // for demo set to 5x4
    int row = 0;
    int col = 0;
//    char data[100];
    
    // open a file in read mode.
    ifstream infile;
    infile.open("maze.txt");
//    infile >> data;
    
    // open a file in write mode.
    ofstream outfile;
    outfile.open("temp.txt");
    // write data into the file.
//    outfile << data << endl;
    
    string data;
    while (getline(infile, data))
    {
        //erase all '\r's from file
        data.erase(remove(data.begin(), data.end(), '\r'), data.end());
//        data.erase(data.length()-2);
        outfile << data << endl;
    }
    
    
    infile.close();
    outfile.close();
    
    
    
    string mazeText = "temp.txt";
    
    //http://stackoverflow.com/questions/9132151/how-to-find-number-of-characters-in-a-file-without-traversing-the-contents
    FILE*  file = fopen("temp.txt", "rb");
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
    ifstream myfile("temp.txt");
    
    while (getline(myfile, line))
    {
        ++numberOfLines;
    }
    
    myfile.close();
    
    ifstream myfile3(mazeText);
//    while (getline(myfile3, line))
//    {
//        for (char& c : line)
//        {
//            if (c == '\r')
//            {
//                col = ((totalNumberOfChars - ((numberOfLines * 2) - 1))  / (numberOfLines)) + 3;
//            }
//            else
//            {
//                col = ((totalNumberOfChars - (numberOfLines - 1))  / (numberOfLines)) + 1;
//            }
//        }
//    }
    
//    while (getline(file, line))
//    {
//        //trim the line:
//        line.erase(line.find_last_not_of(" \n\r\t") + 1);
//        
//        for (char& c : line)
//        {
//            cout << c;
//        }
//        cout << "[ENDLINE]\n";
//    }
    
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
    
    
    fstream fin(mazeText);
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
    fin.close();
    
    
    cout << endl << endl;
    cout << "The chosen coord is: " << maze[2][2] << endl;
        
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
    
    maze[row-2][col-2] = 'F';
//    maze[2][2] = 'T';
//    maze[0][2] = 'B';
    
//    maze[1][0] = '#';
//    maze[1][1] = '#';
//    maze[1][2] = '#';
//    maze[1][3] = '#';
//    maze[1][4] = '#';
    
    cout << "Now here is your matrix or maze" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << maze[i][j];
            
            
        }
    }
    cout << endl << endl << endl;
    
    
    
    
    
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            cout << maze[i][j];
////            
//        }
//    }
    cout << endl << endl << endl;
    
    
    
    
//    int co1 = 1;
//    int co2 = 2;
    
    stack<pair<int, int> > mazeStack;
//    mazeStack.push(make_pair(co1, co2));
//    mazeStack.push(make_pair(1,0));
//    mazeStack.push(make_pair(1,1));
//    mazeStack.push(make_pair(1,2));
//    mazeStack.push(make_pair(1,3));
//    mazeStack.push(make_pair(1,4));
//    mazeStack.push(make_pair(1,5));
    
    long stackSize = mazeStack.size();
    
    cout << "Size of stack is " << stackSize << endl;
    
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (maze[i][j] == ' ')
//            {
//                mazeStack.push(make_pair(i, j));
//                maze[i][j] = '#';
//            }
//            else if (maze[i][j] == '|')
//            {
//                if (maze[i + 1][j] == ' ')
//                {
//                    maze[i + 1][j] = '#';
//                }
//                else if (maze[i - 1][j] == ' ')
//                {
//                    maze[i - 1][j] = '#';
//                }
//            }
//            
//        }
//    }
    
    
    cout << "Now here is your matrix or maze" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << maze[i][j];
            
            
        }
    }
    cout << endl << endl << endl;
    
    
    
    
    //    pair <int, int> p = mazeStack.top();
//    for (int i = 0; i < stackSize; i++)
//    {
//        cout << p.first << "," << p.second << endl;
//        mazeStack.pop();
//    }
    
    
    //test fill up stack with coords...
    
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            if (maze[i][j] == ' ') {
//                mazeStack.push(make_pair(i,j));
//                if (maze[i][j] == 'F') {
//                    break;
//                }
//            }
//        }
//    }
    
    
    
    
//    int i = 0;
//    int j = 0;
//    while (maze[i][j] != 'T') {
//        for (i = 0; i < row; i++) {
//            for (j = 0; j < col; j++) {
//                if (maze[i][j] == 'T') {
//                    break;
//                }
//                if (maze[i][j] == ' ') {
////                      mazeStack.push(make_pair(1,5));
//                    mazeStack.push(make_pair(i,j));
//                }
//            }
//        }
//        break;
//    }
    
//    maze[row-2][col-2] = 'F';
//    maze[1][0] = 'S';
//    maze [3][5] = 'T';
    mazeStack.push(make_pair(1, 0));
    for (int i = 0; i < 10000; i++){
        pair<int, int> z = mazeStack.top();
        
        int x = z.first;
        int y = z.second;
    
        
        if (maze[x][y+1] == 'F') {
            mazeStack.push(make_pair(x, y+1));
            maze[x][y+1] = 'D';
            cout << "YOU MADE IT!!!!!" << endl;
            for (int a = 0; a < row; a++) {
                for (int b = 0; b < col; b++) {
                    if (maze[a][b] == '.') {
                        maze[a][b] = ' ';
                    }
                }
            }
            break;
        }
        else if (maze[x][y+1] == ' ') {
            mazeStack.push(make_pair(x, y+1));
            maze[x][y+1] = '.';
        }
        else if (maze[x+1][y] == ' ') {
            mazeStack.push(make_pair(x+1, y));
            maze[x+1][y] = '.';
        }
        else if (maze[x][y-1] == ' ') {
            mazeStack.push(make_pair(x, y-1));
            maze[x][y-1] = '.';
        }
        else if (maze[x-1][y] == ' ') {
            mazeStack.push(make_pair(x-1, y));
            maze[x-1][y] = '.';
        }
        else{
            mazeStack.pop();
        }
    }
    
    
    cout << "Here is the contents of the stack..." << endl;
    while(!mazeStack.empty())
    {
        pair<int, int> w = mazeStack.top();
        cout << w.first << "," << w.second << endl;
        maze[w.first][w.second] = '#';
        
        mazeStack.pop();
    }
    
    cout << "Lastly, here is your matrix or maze" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << maze[i][j];
            
            
        }
    }
    cout << endl << endl << endl;
    
    
    
    
    
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
        maze = NULL;
    
    
    // Write them back out after deletion...
    cout << "Here is your matrix or maze after deletionnnnnnnnnnnnn" << endl;
    cout << "\033[1;31mbold red text\033[0m\n";
    
    
        return 0;
    }


