#include <iostream>
#define ROWS 10 // Number of rows in the cinema
#define COLS 10 // Number of columns in the cinema

using namespace std;

// Sequential search function
bool sequentialSearch(bool cinema[ROWS][COLS], int& row, int& col) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (!cinema[i][j]) { // If the seat is empty (false)
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

// Binary search function
bool recursiveLinearSearch(bool cinema[ROWS][COLS], int row, int col, int i, int j) {
    // Base case: if we have checked all the seats
    if (i >= ROWS) {
        return false; // No empty seat found
    }

    // Check the current seat
    if (!cinema[i][j]) { // If the seat is empty (false)
        row = i;
        col = j;
        return true;
    }

    // Move to the next column
    if (j < COLS - 1) {
        return recursiveLinearSearch(cinema, row, col, i, j + 1); // Search in the next column
    }

    // Move to the next row if we reach the end of a row
    return recursiveLinearSearch(cinema, row, col, i + 1, 0); // Search in the next row
}

int main() {
    // Initialize the cinema seating arrangement (0 = empty, 1 = occupied)
    bool cinema[ROWS][COLS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };


    int row = -1, col = -1;

    // Sequential Search
    bool foundSeq = sequentialSearch(cinema, row, col);

    if (foundSeq) {
        cout << "Sequential Search: Found empty seat at (" << row << ", " << col << ")\n";
    } else {
        cout << "Sequential Search: No empty seat found.\n";
    }

    // Reset row and col for Binary Search
    row = -1;
    col = -1;

    // Binary Search
    bool foundSeq = recursiveLinearSearch(cinema, row, col, 0, 0);

    if (foundSeq) {
        cout << "Recursive Linear Search: Found empty seat at (" << row << ", " << col << ")\n";
    } else {
        cout << "Recursive Linear Search: No empty seat found.\n";
    }
    return 0;
}
