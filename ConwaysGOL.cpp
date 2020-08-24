#include <iostream>
#include <fstream>
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

    ifstream infile;
    infile.open(argv[1]);

    // Eventually initialize this depending on size of input board
    vector<vector<char>> board {  {0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0} };

    string line;
    int i = 0;
    int j = 0;
    while (getline(infile, line)) {

        // Nifty :)
        line.erase(remove(line.begin(), line.end(),' '), line.end());

        cout << line << endl;

        for (j = 0; j < line.size(); j++) {
            cout << "pushing back " << line[j] << " onto " << "vector " << i << endl;
            board[i][j] = line[j];
        }

        // cout << endl;

        // board.push_back(line);

        i++;
    }

    // cout << board[0].size() << endl;

    // cout << board[0][0] << endl;

    // Testing input parsing
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}