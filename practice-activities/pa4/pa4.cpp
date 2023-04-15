#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std; 


/* 

PSEUDOCODE:

- create hpp file for functions, main file to test and output file to show values

turn values of input file into double 

#include <file given>

for nums in file, for appropriate integer sz initialized for array

create 2D vector:

for int i = 0; int < size of array; i++

cout << int vect[i][2];

// we will always have n rows by 2 - this is because there will be at most 1 null value

create 3D matrix:

for nums in file, for appropriate integer sz initialized for array

// we will figure most appropriate 3D array size by -> [2][2][ceil(n/4)] this is because there will be the most amount of groups
of 2 x 2 groups such that there will be at most 3 nulls per group at all times 

for int i = 0; int < size of array; i++

for int j = 0; j < size of array; j++

cout << int arr[][i][j]; // such that appropriate size is used and null values return zero

*/




int main() {

ifstream file;
file.open("numbers.txt");
if (file.fail()) {
    cout << "File failed to open" << endl;
    return 1;
}

vector<double> total_nums_vect;
double sum = 0;
double num;
while(file >> num) {
    total_nums_vect.push_back(num);
    sum = sum + num;
};

file.close();



int total_vect_size = total_nums_vect.size();
int size_2D;
int size_3D;
if(total_vect_size % 2 == 0) {
    size_2D = total_vect_size / 2;
}
else {
    size_2D = (total_vect_size / 2) + 1;
}
if(total_vect_size % 4 == 0) {
    size_3D = total_vect_size / 4;
}
else {
    size_3D = (total_vect_size / 4) + 1;
}

// 2D vector
vector<vector<double> > twoD_vector;
// 3D array
double threeD_array[2][2][size_3D];

int temp = 0;
vector<double> v1;
vector<double> v2;
twoD_vector.push_back(v1);
twoD_vector.push_back(v2);
for(int i = 0; i < total_vect_size; i++) {
    if(temp < size_2D) {
        twoD_vector[0].push_back(total_nums_vect[i]);
    }
    else {
        twoD_vector[1].push_back(total_nums_vect[i]);
    }
    threeD_array[0][0][i] = total_nums_vect[i];
    temp = temp + 1;
}

ofstream output("pa4output.txt");
if (output.fail()) {
    cout << "File failed to open" << endl;
    return 1;
}

output << "Sum of all values is: " << sum;

output << endl;


output << "2D vector:" << endl;
for(int outer = 0; outer < 2; outer++) {
    for(int inner = 0; inner < size_2D; inner++) {
        output << twoD_vector[outer][inner];
    }
    output << endl;
}


output << endl << endl;


output << "3D array:" << endl;
for(int outer = 0; outer < 2; outer++) {
    for(int mid = 0; mid < 2; mid++) {
        for(int inner = 0; inner < size_3D; inner++) {
            output << threeD_array[outer][mid][inner];
        }
        output << endl;
    }
    output << endl;
}


return 0;

}


