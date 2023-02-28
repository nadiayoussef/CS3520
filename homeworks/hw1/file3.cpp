/*  This program should determine if a number is a prime or composite number 
    The program should ask user for a number 'num'
    If 'num' is 0 or 1, print "num is not prime or composite"
    For any value > 1, print "num is a prime number" or "num is a composite number" depending on the number */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)
  
// Fix: mispelling of iostream
// Fix: add the std namespace
#include <iostream>
using namespace std;

int main(void){
    int num, i;
    // Fix: false intialization should be lowercase
    bool factor_found = false;
    // Fix: replace new line with a space
    cout<<"Enter Number: ";
    cin>>num;
    // Fix: replace colon at the end of line with brackets
    // Fix: replace and (&&) with or (||)
    if(num == 0 || num == 1) {
        // Fix: add semicolon at the end of line
        // Fix: add endl since it is the end of the program
        cout<<num<<" is not prime or composite" << endl;
    }
    // Fix: add an else statement for the rest of the program
    else
    {
        // Fix: Remove the semicolon before the bracket
        // Fix: Replace commas with semicolons in between the for loop fields
        for (i = 2; i < num; i++) {
            // Fix: add parentheses after if
            // Fix: replace colon after if statement with brackets
            if (num%i == 0) {
                // Fix: true intialization should be lowercase
                // Fix: variable name factor_found is lowercase
                // Fix: semicolon after true
                factor_found = true;
                break;
            }
        }
        // Fix: delete "not"
        // Fix: add parentheses after if
        // Fix: replace colon after if statement with brackets
        // Fix: replace \n with endl since it is the end of the program
        // Fix: add num to the output statement
        if (factor_found) {
            cout << num << " is a composite number" << endl;
        }
        // Fix: add brackets after else statement
        else {
            // Fix: semicolon after statement
            // Fix: remove floating bracket
            // Fix: replace \n with endl since it is the end of the program
            // Fix: add num to the output statement
            cout << num << " is a prime number" << endl;
        }
    }
}
