// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 617, exchange = 424
Output : 
"I am calling to tell you to buy a subscription to Dogs Monthly Magazine!"
617-424-0001
617-424-0002
617-424-0003
...
617-424-9998
617-424-9999
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include<iostream>
//add the std namespace (and removed std:: prefix from the rest of the program)
using namespace std;
  
int main() {
    // Fix: change varibale type to int
   int digit1, digit2, digit3, digit4;
   int areaCode, exchange;
   cout << "Hello, I am a telemarketing calling making program.\n";
   // Fix: add missing open quote
   cout << "Enter a three-digit area code ";
   // Fixes:
   // Replace exchange variable for areaCode variable
   // Add std:: prefix
   // Switch direction of arrows to >>
   cin >> areaCode;
   // Fix: add missing semicolon at the end of line
   cout << "Enter a three-digit exchange to call ";
   // Fix: replace areaCode variable for exchange variable
   cin >> exchange;
   
   // Fixes:
   // Remove floating end parenthesis
   // Moved to earlier in the program to print before the phone numbers
    cout<< "I am calling to tell you to buy a subscription to Dogs Monthly!\n";

    // Fixes:
   // Replace colons with semicolons
   // Change condition to be less than, but not equal to, 10
   // Change all of the loops incremet to be a post-increment rather than pre
   // Increment self rather than next digit
   for(digit1 = 0; digit1 < 10; digit1++)
   {
        // Fixes:
        // Replace commas with semicolons
        // Change initialization to start from 0
        // Change condition to be <10
        // Change to positive increment
        // Increment self rather than next digit
        for(digit2 = 0; digit2 < 10; digit2++)
        {
            // Fixes:
            // Add missing open bracket
            // Replace periods with semicolons
            // Replace while statement with for statement
            // Replace incremented variable to digit4
            // Increment self rather than next digit
            for(digit3 = 0; digit3 < 10; digit3++)
            {
                // Fix: add a while loop for digit4
                while(digit4 < 10) {
                    cout<< "Dialing ("<< areaCode <<") " << exchange <<" - ";
                    // Fix: seperate digit1 and digit2 by arrows rather than a comma
                    cout << digit1 << digit2 << digit3 << digit4 <<endl;
                    digit4++;
                }
                 // Fix: initialize digit4 to 0
                digit4 = 0;
            }
            digit3 = 0;
        }
        digit2 = 0;
    }
    
    cout<< "\nCalls completed"<<endl;
   
   // Fix: add missing return value
   return 0;
}