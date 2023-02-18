
// Program to check if the user-provided number is a palindrome
// Number of errors/bugs = 25


//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<iostream>
// Missing namespace std
using namespace std;
// Change void to bool
// Change char to int
bool func(int x);

// Change void to int
int main() {
        // Change char to int
        int input = 1001;
        // Add a variable to store user input
        int user;
	cout<<"enter an integer please: ";
        // Add a statement to accept user input
        cin >> user;
        // Define returned_val
        bool returned_val;
        // Edit func2 to just func
        // Passing the user input into the function
        returned_val = func(user);
        // Switch conditional statements' output
        if (returned_val){ 
                // Statement should be in quotes
                // Line should end with a semicolon
                cout<< "It is a palindrome" << endl;
        }
        else{
                cout<< "It is not a palindrome"<<endl;
        }
		// Unnecessary return
		//return 0;
}

//the return value of your func should be true / false only
// The function should be boolean to return true/false and not void
// Function definition does not need to take in result
bool func(int n)
{
        // Missing semicolon
            float given_number;
            int temp = 0;
            // Replace = with >
            while (n > 0) {
                // remainder variable was not defined
                int remainder;
                // Modify / to %
		remainder = n % 10;
                // Value of n was not modified
		n = n/10;
                // Value of temp was not modified
                temp = temp * 10 + remainder;        
            }

        // Switch conditional outputs
            if (n == temp)
            {
                    return true;
            }
            else
            {
                    return false;
                }
}

