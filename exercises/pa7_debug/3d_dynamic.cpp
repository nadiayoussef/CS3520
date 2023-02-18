//This program allocated memory for an NxM integer array dynamicaly
//The program then prints the 2D array in a matrix form using a combination of * and [] operators
//Note: You can't use ** or [][] for printing the values (use a combination of * and [] only.

//Number of bugs/errors : 6

#include <iostream>
#include <cstdlib>
#include <stdio.h> // Include
using namespace std;

int main() {
    int N = 3, M = 5;
    int i, j;
	// Change to *
    int *d_array = (int*) malloc( N * sizeof(int) ); 

    for (i = 0; i < N; i++) { // ;
	// Create temporary variable
        int temporary = (M * sizeof(int*) );
        malloc(temporary); 
         d_array[i] = temporary;
         }

    //Initializing 2D array using [ ][ ] notation

    printf("Initializing array values!\n");

    for(i = 0; i < N; i++) {            
         for(j = 0; j < M ; j++) {
              *(d_array + i + j) = i + j; // ;
         }
    }

    //Accessing 2D array using a combination of * and [] notation

    printf("\n");

    for(i = 0; i < N; i++) {            
         for(j = 0; j < N; j++) {
			// Make not an int
              cout << *(d_array + j); 
         }
         cout<<"\n";
    }

    //Deallocating 2D array
    for(i = 0; i < N; i++) { // Need {} i     
        free(d_array + i);
    free(d_array);
}
}