#include <iostream>
using namespace std;

int main() {

    // Declaring strings
    string paragraph;
    string find;
    string replace;

    // Output for user when entering in terminal their input
    cout << "Enter paragraph: ";
    getline (cin, paragraph);

    cout << "Find: ";
    getline (cin, find);

    cout << "Replace with: ";
    getline (cin, replace);
    cout << endl;

    // Initializing variables and count and setting pos
    int index, j, count = 0;
    int pos[] = {};

    // While there is a word in the paragraph, it will be found
    while (index < paragraph.length()) {
        index = paragraph.find(find, j);
        pos[count] = index;
        j = index + 1;
        count++;
    }

    index = 0;
    j = 0;

    // While there is a word found, it will be replaced
    while (index < paragraph.length()) {
        index = paragraph.find(find, j);
        if (index != string::npos) {
            paragraph.replace(index, find.length(), replace);
            j = index + replace.length();
        }

    } 

    cout << "Replaced paragraph: " << paragraph << "\n" << endl;
    return 0;
}