/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
// Fix: add the std namespace
using namespace std;

int main(){
    // Fixes:
    // Adjust the limit variable to the actual limit of 10
    // Change inital values of even_product and odd_product to 1 (so the prouduct isn't always 0 when multiplied)
    int limit = 10, even_product = 1, odd_product = 1, sum;
    char c;
    cout << "The value of limit is " << limit << endl;
    
    // Fixes:
    // Declare the variable i instead of only initializing it
    // Replace colons with semicolons
    // Start the loop at i = 1, as instructions specify from 1 to 10
    for(int i = 1; i <= limit; ++i){ 
        // Fixes:
        // Use double equal signs 
        // Change / to %
       if(i % 2 == 0){
            // Fix: muliply the current number to the previous product
           even_product = even_product * i;
       }   
       // Fix: change to an else statement
        else {
            // Fix: muliply the current number to the previous product
           odd_product = odd_product * i;
       }
        sum = even_product + odd_product;
    }
    
    // Fixes:
    // Remove floating parenthesis and add proper synax for appending the sum (<<)
    // Remove \n so the sum is on the same line
    // Append endl to end
    // Remove %d since this is not a decimal or a part of a printf function
    cout << "The Sum = " << sum << endl;
    
    // Fixes:
    // Edit value of char variables to be uppercase letters
    // Start the loop with Z and end at A
    // Cast the iterative value back into a char
    for(c = 'Z'; c >= 'A'; c = c - 2){
        // Fix: change output variable from i to c
        cout << " " << c;
    }
    cout << endl;
    return 0;
}
