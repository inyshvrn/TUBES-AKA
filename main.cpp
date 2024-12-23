#include <iostream>
using namespace std;

#define ROWS 10
#define COLS 10

bool cinema[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void findAllAvailableSeatsIterative() {
    cout << "Iterative Approach:" << endl;
    bool found = false;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (cinema[row][col] == 0) {
                cout << "Available seat found at row " << row << ", column " << col << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No available seats found." << endl;
    }
}

void findAllAvailableSeatsRecursive(int row, int col) {
    if (row >= ROWS) return;
    if (col >= COLS) {
        findAllAvailableSeatsRecursive(row + 1, 0);
        return;
    }
    if (cinema[row][col] == 0) {
        cout << "Available seat found at row " << row << ", column " << col << endl;
    }
    findAllAvailableSeatsRecursive(row, col + 1);
}


int main() {
    // Memanggil metode iteratif
    findAllAvailableSeatsIterative();

    cout << endl;

    // Memanggil metode rekursif
    cout << "Recursive Approach:" << endl;
    findAllAvailableSeatsRecursive(0, 0);

    return 0;
}
