#include <iostream>
using namespace std;

int dirV[4] = {-1, 0, 1, 0}; // Up, right, down, left
int dirH[4] = {0, 1, 0, -1};
const int PATH = 48;  // length of all possible paths
int pathToTake [PATH];
// Rather than 7 add a border so I don't have to deal with out of bounds logic
const int SIZE_OF_GRID = 9;  
bool grid [SIZE_OF_GRID][SIZE_OF_GRID];

int tryPath(int pathIdx, int row, int col) {
	// Base Case #1: Reached bottom left square
    if (row == 7 && col == 1) {
        // If entire path has been gone throught add one
		if (pathIdx == PATH) {
            return 1;
        }
        // Reached bottom left too early
        return 0;
	}

    // Can only move left or right not up or down
    if ((grid[row][col - 1] && grid[row][col + 1]) && (!grid[row - 1][col] && !grid[row + 1][col])) {
            return 0;
    }

    // Can only move up and down but not right or left
	if ((grid[row - 1][col] && grid[row + 1][col]) && (!grid[row][col - 1] && !grid[row][col + 1])) {
        return 0;
    }

    // If we used all 48 directions but haven't reached bottom left yet
	if (pathIdx == PATH) {
        return 0;
    }

	int ret = 0;
	grid[row][col] = true;

	// Case #1: The input is either U, D, L, R and we move that direction
	if (pathToTake[pathIdx] < 4) {
		int nxtR = row + dirV[pathToTake[pathIdx]];
		int nxtC = col + dirH[pathToTake[pathIdx]];
		if (!grid[nxtR][nxtC]) {
            ret += tryPath(pathIdx + 1, nxtR, nxtC);
        }
    // Case #2: The input is '?' and we must try all four directions
	} else {
		for (int i = 0; i < 4; i++) {
			int nxtR = row + dirV[i];
			int nxtC = col + dirH[i];
			if (!grid[nxtR][nxtC]) {
			    ret += tryPath(pathIdx + 1, nxtR, nxtC);
            }
		}
	}
	// Since we're finding all solution must set this back to false
	grid[row][col] = false;
	return ret;
}

int main() {
    int currPath = 0;
	int startRow = 1;
	int startCol = 1;
	string input;
	getline(cin, input);

	// Assign each input to an int to make determining direction easier
	for (int i = 0; i < PATH; i++) {
        char c = input[i];
        switch (c) {
            case 'U':
                pathToTake[i] = 0;
                break;
            case 'R' :
                pathToTake[i] = 1;
                break;
            case 'D':
                pathToTake[i] = 2;
                break;
            case 'L':
                pathToTake[i] = 3;
                break;
            default:
                pathToTake[i] = 4;
                break;
        }
	}

	// Set up the border in the 2D array to be visited (true)
	for (int i = 0; i < SIZE_OF_GRID; i++) {
        // First and last rows to true
		grid[0][i] = true;
		grid[8][i] = true;
        // First and last columns to true
		grid[i][0] = true;
		grid[i][8] = true;
	}
	// Sets up the rest of the grid to unvisited (false)
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			grid[i][j] = false;
		}
	}

	int ans = tryPath(currPath, startRow, startCol);
	cout << ans << endl;
}
