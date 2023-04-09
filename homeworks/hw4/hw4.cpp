#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

class WordInfo {
   public:
      void increase_count() {
        count++;
      }
      string get_info() {
        return word_info;
      }
      int get_count() {
        return count;
      }
      // Constructor
      WordInfo(string word_info, int count) {
        this->word_info = word_info;
        this->count = count;
    }
   private:
      string word_info;
      int count;
};


bool starts_with_vowel(string word) {
    char start = word[0];
    return (start == 'a' || start == 'e' || start == 'i' || start == 'o' || start == 'u' ||
            start == 'A' || start == 'E' || start == 'I' || start == 'O' || start == 'U');
}

int vowel_counter(map<string, pair<int, bool> > words) {
    int count = 0;

    for(auto i : words) {
        if( (i.second).second ) {
            count++;
        }
    }

    return count;
}


int freq(string word, string filename) {
    int count = 0;
    ifstream file;
 
    file.open(filename.c_str());

    if (!file) {
        cerr << "Error opening file " << filename << endl;
        return 0;
    }

    string curr_word;
    while (file >> curr_word) {
        transform(curr_word.begin(), curr_word.end(), curr_word.begin(), ::tolower);
        if(curr_word.compare(word) == 0) {
            count++;
        }
    }
    return count;

}

bool is_length(string word, int len) {
    return word.length() <= len;
}

int main() {
    string filename;
    cout << "Enter the name of the text file: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file " << filename << endl;
        return 0;
    }

    map<string, pair<int, bool> > words;

    string word;
    int word_count = 0;
    while (file >> word) {
        pair<int, bool> stat;
        // transform(word.begin(), word.end(), word.begin(), ::tolower);
        stat.first = freq(word, filename);

        if(starts_with_vowel(word)){
            stat.second = true;
        }
        else {
            stat.second = false;
        }

        words[word] = stat;
        word_count++;
    }

    // Create and open a text file for the statistics
    ofstream stats("statistics.txt");

    // Write to the file:
    // Total word count
    stats << filename << " has " << word_count << " number of words" << endl << endl;

    // Words that start with a vowel count
    stats << filename << " has " << vowel_counter(words) << " words that start with a vowel" << endl;

    // Words that start with a vowel with their length and frequency
    for (auto i : words) {
        string word_lc = i.first;
        transform(word_lc.begin(), word_lc.end(), word_lc.begin(), ::tolower);
        for(int len = 0; len <= words.size(); len++) {
            if(freq(word_lc, filename) == len && i.second.second) {
                    stats << word_lc << " {Word Length: " << (word_lc).size() << "}: " << freq(word_lc, filename) << endl;
            }
        }
    }

    stats << endl;

    // Take user input of a word length
    int given_len;
    cout << "Input a word length: ";
    cin >> given_len;
    cout << endl;

    // Number of words of the given length
    int num_len = 0;
    for (auto i = words.begin(); i != words.end(); i++) {
        if( is_length(i->first, given_len) ) {
            num_len++;
        }
    }


    stats << filename << " has " << num_len << " distinct words with length " << given_len << " or less" << endl;

    map<string, WordInfo*> wc_info;

    // Close the file
    stats.close();
}