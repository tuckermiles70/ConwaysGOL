#include <iostream>
#include <fstream>
// #include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isspace(char c) {
    if (c == ' ') return true;
    return false;
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
            cout << "pushing back " << line[j] << " onto " << "vector " << i << endl;
            
            // some ASCII fun
            board[i][j] = line[j] - '0';
        }
        i++;
    }

    // Testing input parsing
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }


    // Rules
    // 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    // 2. Any live cell with two or three live neighbours lives on to the next generation.
    // 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
    // 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction

    // Loop through each cell, determining how many alive neighbor's it has


    // initialize to -1 so cell itself doesn't get counted as a living neighbor
    // when finding num of living neighbors
    int livingNeighbors = -1;
    
    // loop through each cell
    for (i = 1; i < 6 - 1; i++) {
        for (j = 1; j < 6 - 1; j++) {

            livingNeighbors = -1;

            // Search for living neighbors
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    livingNeighbors += board[i + k][j + l];
                }
            }

            cout << "cell " << i << " " << j << " has " << livingNeighbors << " living neighbors\n";

        }
    }



    return 0;
}