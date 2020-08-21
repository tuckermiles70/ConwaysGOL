#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {

    // read in table
    if (argc != 2) {
        return -1;
    }

    ifstream infile;
    infile.open(argv[1]);

    vector<string> board;

    string line;
    int i = 0;
    int j = 0;
    while (getline(infile, line)) {

        board.push_back(line);

        // i++;
    }

    for (i = 0; i < board.size(); i++) {
        cout << board[i] << endl;
    }

    return 0;
}