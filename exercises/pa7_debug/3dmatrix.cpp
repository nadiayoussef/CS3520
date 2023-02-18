// Program to read 3-dimensional matrix and display the elements as 1xN^3 matrix
// TODO
// initize matrix using update_3d method (see comments below)
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops
// 

#include <iostream>
#include <math.h>
#include <stdio.h>
#define SIZE 7
using namespace std;

void update_3d(double Matrix_3d[][SIZE][SIZE],int size); 
void display_1d(double Matrix_3d[][SIZE][SIZE],int size); 

int main(void) {
	int size;
	//prompt the user to initialize the matrix accordingly
	cout << "Enter matrix size: ";
	cin >> size;
	double Matrix_3d[SIZE][SIZE][SIZE] = {};
	//initialize the array to non-zero values (use scanf or random numbers generator)
	update_3d(Matrix_3d, SIZE);
	//display the values
	display_1d(Matrix_3d, SIZE);
	return 0;
}

void update_3d(double matrix[][SIZE][SIZE], int size) {
	cout<<"Entering 3N elements of the matrix:"<<endl;
	for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
	  {
	      for (int k = 0; k < size; k++)
		  {
	        //cin for Matrix_3d[i][j][k] or random number generator
			cout << "Enter 3 numbers: ";
	      }
      }
    }
}

//update as needed. 1 'for' loop only with 1 iterator to print all values with addresses
//must not be able to update the array.
//Share any observations.
void display_1d(int matrix[][SIZE][SIZE], int size) {
	for (int i = 0; i < pow(size, 3); i++) {
        cout << &matrix[i]<< " ";
    }
	cout << endl << endl;
}
