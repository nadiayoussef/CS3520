// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.

// Number of errors/bugs = 10

#include <iostream>
using namespace std;

void display(int Matrix[3][3], int size);

// Move display function

void display(int Matrix[3][3], int size) { 
  // Int i
    for (int i = 0; i < size; i++) { 
      // Int j and j++
        for (int j = 0; j < size; j++) 
        {
            cout << Matrix[i][j] << ", ";
        }
        cout << endl; // ;
    }
}

int main(void) {
  // Make constant 3
    const int height = 3; 
    const int width = 3;
    // Fix Matrix initialization
    int Matrix[height][width] = { {}, {}, {} }; 
    // cout << not cin >>
    cout << "Enter 9 elements of the matrix:" << endl; 
    // Int i
    for (int i = 0; i < height; i++) 
    {
      // Put this in loop
        for (int j = 0; j < width; j++) {
            cin >> Matrix[i][j];
        }
    }

// Not &Matrix
    display(Matrix, 3);
    return 0;
}
