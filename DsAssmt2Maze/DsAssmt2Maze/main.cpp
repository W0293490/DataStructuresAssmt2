//
//  main.cpp
//  Test Feb 9 17
//
//  Created by danielle ryall on 2017-02-09.
//  Copyright © 2017 w0293490. All rights reserved.
//

#include "FileHandler.hpp"
#include "Maze.hpp"
#include "Stack.hpp"
#include "Helper.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"


using namespace std;


int main(int argc, char** argv) {
    
    //member variables:
    char **maze;
    int row = 0;
    int col = 0;
    FileHandler fh;
    Maze m;
    Stack st;
    Helper h;
    
    if(argc < 2)
    {
        cout << RED << "Sorry, you need to open a valid file..." << RESET << endl;
        return 0;
    }
    
    string arg1(argv[1]);
    
    //Open original file according to argv, delete /r's, then save it to new temp file:
    // open a file in read mode:
    ifstream infile;
    infile.open(arg1);
    if(!infile)
    {
        cout << RED << "Sorry, you need to open a valid file..." << RESET << endl;
        return 0;
    }
    
    // open a file in write mode:
    ofstream outfile;
    outfile.open("temp.txt");
    
    // write data into the file:
    fh.readWriteFile(infile, outfile);
    
    infile.close();
    outfile.close();
    
    
    
    //find number of rows and cols:
    string mazeText = "temp.txt";
    
    int totalNumberOfChars = fh.findNumberOfChars("temp.txt");

    int numberOfLines = fh.findNumberOfLines("temp.txt");
    
    col = ((totalNumberOfChars - (numberOfLines - 1))  / (numberOfLines)) + 1;
    row = numberOfLines;

    
    
    //build the maze:
    maze = m.buildMaze(col, row, "temp.txt");
    
    
    
    //print the maze:
    cout << BLUE << "Here is your maze" << RESET << endl;
    m.printMaze(row, col, maze);
    
    
    
    //Figure out solution...
    //Mark endpoint:
    maze[row-2][col-2] = 'F';
    
    //Set starting point:
    st.mazeStack.push(make_pair(1, 0));
    
    for (int i = 0; i < totalNumberOfChars; i++){
        pair<int, int> top = st.mazeStack.top();
        
        //Set variables to link maze coords with elements of stack node:
        int x = top.first;
        int y = top.second;
        
        //If solved:...
        if (maze[x][y+1] == 'F') {
            st.mazeStack.push(make_pair(x, y+1));
            maze[x][y+1] = 'D';
            cout << GREEN << "YOU MADE IT!!!!!" << RESET << endl;
            
            //// ** comment/uncomment this code to show/hide breadcrumbs in output file... **
            ////replace 'o's with ' 's.
            //            for (int a = 0; a < row; a++) {
            //                for (int b = 0; b < col; b++) {
            //                    if (maze[a][b] == 'o') {
            //                        maze[a][b] = ' ';
            //                    }
            //                }
            //            }
            
            break;
        }
        else if (maze[x][y+1] == ' ') {
            st.mazeStack.push(make_pair(x, y+1));
            maze[x][y+1] = 'o';
        }
        else if (maze[x+1][y] == ' ') {
            st.mazeStack.push(make_pair(x+1, y));
            maze[x+1][y] = 'o';
        }
        else if (maze[x][y-1] == ' ') {
            st.mazeStack.push(make_pair(x, y-1));
            maze[x][y-1] = 'o';
        }
        else if (maze[x-1][y] == ' ') {
            st.mazeStack.push(make_pair(x-1, y));
            maze[x-1][y] = 'o';
        }
        else{
            st.mazeStack.pop();
        }
        
        
        // ** Uncomment/comment this code to show or not show animated maze solving... **
        
        cout << BLUE << "Here is your maze" << RESET << endl;
        m.printMaze(row, col, maze);
        
        //        msleep(2);
        clock_t strt = clock();
        clock_t end = 20000 + strt;
        while (clock() < end)
        {
            continue;
        };
        h.ClearScreen();
        
        
        
    }
    
    //Get the contents of the stack...add stack solution coords to maze...
//    st.addStackNodesToMaze(maze, st.mazeStack);
    while(!st.mazeStack.empty())
    {
        pair<int, int> w = st.mazeStack.top();
        //        cout << w.first << "," << w.second << endl;
        maze[w.first][w.second] = '#';
        st.mazeStack.pop();
    }
    
    
    
    //Print solved maze:
    cout << CYAN << "Here is the solved maze:" << RESET << endl;
    m.printMaze(row, col, maze);
    
    
    
    //create text file of solved maze.
    string oFile = "Solved_" + arg1;
    
    fh.createSolvedMazeFile(oFile, maze, row, col);
    
    
    
    //Delete maze:
    m.deleteMaze(row, col, maze);
    
    
    
    return 0;
}
