#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool isVowel(char c) {
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}
bool isPunc(char c) {
    switch(c) {
        case '!':
        case '.':
        case ',':
        case ';':
        case '\"':
        case '\'':
        case '\?':
        case '$':
            return true;
        default:
            return false;
    }
}

// num is the length to compare the words' lengths
// paragraph is the string with the words being compared to num
// op is true when comparing for words greater than num, and false when comparing words less than
int compareGreaterLengths(int num, string paragraph, bool op) {
    int curr_word_length = 0;
    int compared_length = 0;
 for(int i = 0; i < paragraph.length(); i++) {
        char curr_char = paragraph[i];
        if(curr_char != ' '){
            curr_word_length = curr_word_length + 1;
        }
        else {
            if(op){
                if(curr_word_length > num) {
                compared_length = compared_length + 1;
                }
            }
            else {
               if(curr_word_length < num) {
                compared_length = compared_length + 1;
                }
            }
            curr_word_length = 0;
        }
    }
    return compared_length;
}


int main(void){ 
    string paragraph;
    cout << "Enter paragraph:\n";
    getline (cin, paragraph);
    cout << endl << endl << "Your paragraph:" << endl;
    cout << paragraph << endl << endl;

    int total_words = 1;
    int total_VC = 0; // total vowels and consonants
    int total_punc = 0; // total punctuation marks (! . , ; “ ‘ ? $)
    int vowel_start = 0;

    for(int i = 0; i < paragraph.length(); i++) {
        char curr_char = paragraph[i];
        if(curr_char == ' '){
            total_words = total_words + 1;
            if(isVowel(paragraph[i+1])) {
                vowel_start = vowel_start + 1;
            }
        }
        if(isalpha(int(curr_char)) > 0) {
            total_VC = total_VC + 1;
        }

        if(isPunc(curr_char)) {
            total_punc = total_punc + 1;
        }
    }

    cout << "Numbers of total words: " << total_words << endl;
    cout << "Number of vowels and consonants: " << total_VC << endl;
    cout << "Number of words that use the following punctuation marks (! . , ; “ ‘ ? $): " << total_punc << endl;
    cout << "Number of words that start with a vowel: " << vowel_start << endl << endl;

    int input_num;
    cout << "Enter a number: ";
    cin >> input_num;
    cout << endl;

    int greater_length = 0; // words greater in length than the inputted number
    int curr_word_length = 0;
    paragraph.append(" ");
    for(int i = 0; i < paragraph.length(); i++) {
        char curr_char = paragraph[i];
        if(curr_char != ' '){
            curr_word_length = curr_word_length + 1;
        }
        else {
            if(curr_word_length > input_num) {
            greater_length = greater_length + 1;
            }
            curr_word_length = 0;
        }
    }

    int greater_than_input = compareGreaterLengths(input_num, paragraph, true);
    cout << "Number of words with length greater than " << input_num << ": " << greater_than_input << endl;

    srand(time(NULL));
    int random = rand() % 5 + 6;
    int less_than_rand = compareGreaterLengths(random, paragraph, false);
    cout << "Number of words with length less than " << random << ": " << less_than_rand << endl << endl;

}