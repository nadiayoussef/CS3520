#include <iostream>
using namespace std;

// main function stores count in an array
int main() {

   int count_of_sum_array[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   //int arr_count[11] = new int[11];

    srand(time(NULL));
   int roll1 = 0;
   int roll2 = 0;
   int roll1and2 = 0;

   // rolls two random sets of dice and adds them up 

   for (int n = 0; n != 36000; ++n) {
      roll1 = 10;
      roll2 = 10;
      while(roll1 > 6 || roll2 > 6) {
         roll1 = 1 + rand()/((RAND_MAX + 1u)/6); 
         roll2 = 1 + rand()/((RAND_MAX + 1u)/6); 
      }
      roll1and2 = roll1 + roll2; 
      count_of_sum_array[roll1and2 - 2] += 1;
   }

   // prints frequency and percentage of sum of both rolls  
   printf("count\tsum\tpercentage\n\n");
   for (int i = 0; i < 12; i++) {
      double percentage_sum = count_of_sum_array[i] / 36000.0;
      cout << i + 1 << "\t" << count_of_sum_array[i] <<"\t" << percentage_sum << endl;
   }
    return 0;
}