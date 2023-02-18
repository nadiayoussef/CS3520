//This program should read any string (including spaces) from the user and print it using a character pointer
//The program is setup to use pointer offset notation to get each character of the string

//Number of bugs/errors : 8
// 1

// Missing iostream
#include <iostream> 
#include <string>
// Missing cstring
#include <cstring> 

using namespace std;

void main(void) {
    char s[20];
    // User input needed
    cout << "Please enter a string: "; 
    cin.getline(s,20);
    // Correctly write pointer
    char* cPtr = s;
    // No while loop
    //while (s[] != '\0') { 
        cout << cPtr;
      // cPtr++; Do not need or } below
   //} 
    cout << "\n";
    // Do not need return 0
}
