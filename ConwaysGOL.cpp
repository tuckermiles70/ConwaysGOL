#include <iostream>
#include <fstream>
// #include <cstring>
#include <string>
#include <algorithm>
#include <vector>

// TODO
// fix conventions.

using namespace std;

bool isspace(char c) {
    if (c == ' ') return true;
    return false;
}

void printBoard(vector<vector<int>> board) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Functionized finding neighbors and call it in loop. Creates a new board after each procedure call, or "tick"
void tick(vector<vector<int>> board) {
    // Loop through each cell, determining how many alive neighbor's it has
    // initialize to -1 so cell itself doesn't get counted as a living neighbor
    // when finding num of living neighbors


    // For when changing to M by N -> https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
    // Also don't forget delete
    int **newest= new int*[6];
    for (int i = 0; i < 6; i++) {
        newest[i] = new int[6];
    }

    int livingNeighbors = -1;
    for (int i = 1; i < 6 - 1; i++) {
        for (int j = 1; j < 6 - 1; j++) {

            // livingNeighbors = -1;
            livingNeighbors = 0;


            // Search for living neighbors
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    livingNeighbors += board[i + k][j + l];
                }
            }

            livingNeighbors -= board[i][j];

            // Cell is lonely and dies 
            if ((board[i][j] == 1) && (livingNeighbors < 2)) 
                newest[i][j] = 0; 

            // Cell dies due to over population 
            else if ((board[i][j] == 1) && (livingNeighbors > 3)) 
                newest[i][j] = 0; 

            // A new cell is born 
            else if ((board[i][j] == 0) && (livingNeighbors == 3)) 
                newest[i][j] = 1; 

            // Remains the same 
            else
                newest[i][j] = board[i][j]; 

            // cout << "cell " << i << " " << j << " has " << livingNeighbors << " living neighbors\n";
        }
    }


    cout << "post tick:\n";
    printBoard(newest);
}

int main(int argc, char **argv) {

    // read in table
    if (argc != 2) {
        return -1;
    }

    // Add a load of error checking

    ifstream infile;
    infile.open(argv[1]);

    // Eventually initialize this depending on size of input board
    vector<vector<int>> board {  {0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0} };

    string line;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    while (getline(infile, line)) {

        // Nifty :)
        line.erase(remove(line.begin(), line.end(),' '), line.end());

        for (j = 0; j < line.size(); j++) {
            // cout << "pushing back " << line[j] << " onto " << "vector " << i << endl;
            
            // some ASCII fun
            board[i][j] = line[j] - '0';
        }
        i++;
    }

    // Testing input parsing
    printBoard(board);

    // Rules
    // 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    // 2. Any live cell with two or three live neighbours lives on to the next generation.
    // 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
    // 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction

    tick(board);
    return 0;
}