#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath> 
#include <string>
#include <vector>
#include <fstream>
using namespace std;


int countAdd(string given_paragrraph, string word) {
    int i = 0;
    int j = 0;
    int count_sum = 0;
    do {
        i = given_paragrraph.find(word, j); 
        if (i != string::npos) {
            j = i + 1;
            count_sum++;
        }   
    } while (i != string::npos);
    return count_sum;
}


int main() {
    string list[30] = {"urgent", "verification required", "customer", "invoice", "need", "help", "sharing", "label", "post", "unusual", "aid", "suspicious", "important", "action required", "vulnerability", "click", "link", "hyperlink", "authority", "don't miss out", "emotion", "copy", "label", "document", "usps", "postal", "calculations", "Amazon", "Apple", "Samsung"};


    int points_assigned[30] = {2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int tally[30];


    ifstream ifs("hw2_q2.txt");
    string content( (istreambuf_iterator<char>(ifs) ),
                       (istreambuf_iterator<char>()    ) );


    int total = 0;

    for (int i = 0; i < 30; i++) {
        tally[i] = countAdd(content, list[i]);
        cout << "word - " << list[i] << " , points - " << tally[i] * points_assigned[i] << "\n";
        total += (tally[i] * points_assigned[i]);
    }
    cout << "\ntotal points: " << total << endl;

     return 0;

}