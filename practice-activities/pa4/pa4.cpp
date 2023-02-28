// Nadia Youssef and John Berry

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Psuedocode:
/*
fileArr[][];
readfile(in.txt);
for()



*/

int main() {

    vector<double> fileVect;

    ifstream infile;
    infile.open("in.txt");
    if(!infile){
        cout<<"can't open the in file"<<endl;
        return EXIT_FAILURE;
    }

    stringstream buffer;
    buffer << infile.rdbuf();

    string line;
    line = buffer.str();
    infile.close();
 
// for(int i = 0; i < line.length(); i++) {
//     while((line.charAt(i)) != " ") {
//         if((line.charAt(i+1)).equals(" ")) {
//             fileVector.push_back((double)line.charAt(i));
//         }
//         else {
//             while((line.charAt(i+1)) != " ") {
                
//             }
//         }
//     }
// }

string currNum;

for(int i = 0; i < line.length(); i++) {
    if(&(line.at(i)) != " ") {
        currNum += (line.at(i));
    }
    else {
        currNum = "";
    }

    if(&(line.at(i+1)) == " ") {
        fileVect.push_back(stod(currNum));
    }
}



    cout << "\nThe vector elements are: " << endl;
    // for (int i = 0; i < fileVect.size(); i++)
    //     cout << fileVect[i] << " ";





cout << "Sum of all Values is: ";

}