#include <iostream>
#include <vector>
#include "Repository.hpp"
#include "Course.cpp"
#include "Book.cpp"

using namespace std;

int main() {
    // creating int items 
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;
    int six = 6;

    // creating a vector of integers
    vector<int> num_vec;
    // filling that vector with the int items
    num_vec.push_back(one);
    num_vec.push_back(two);
    num_vec.push_back(three);

    // creating a repository of integers
    Repository<int> num_repo(num_vec);
    // outputting the int items
    cout << num_repo << endl;


    // adding a new item to the repository
    num_repo.add_item(four);
    // testing that the repository updated by printing the int items again
    cout << num_repo << endl;

    // adding two new items at a time to the repository
    vector<int> new_int_items;
    new_int_items.push_back(five);
    new_int_items.push_back(six);
    num_repo.add_items(new_int_items);
    cout << num_repo << endl;


    cout << "Position of item four: " << num_repo.get_pos(four) << endl;
    
    num_repo.remove_item(four);
    cout << num_repo << endl;

    vector<int> rm_items;
    rm_items.push_back(two);
    rm_items.push_back(three);
    num_repo.remove_items(rm_items);
    cout << num_repo << endl;
 
    cout << "Number of items in integer repository: " << num_repo.count_items() << endl;





    vector<string> string_vec;
    string_vec.push_back("Hello");
    string_vec.push_back("my");    
    Repository<string> string_repo(string_vec);

    cout << endl << endl;
    cout << string_repo << endl;
    string_repo.add_item("name");
    cout << string_repo << endl;
    vector<string> new_strings;
    new_strings.push_back("is");
    new_strings.push_back("Nadia");
    string_repo.add_items(new_strings);
    cout << string_repo << endl;
    cout << "Position of string \"my\": " << string_repo.get_pos("my") << endl;
    string_repo.remove_item("my");
    cout << string_repo << endl;
    string_repo.remove_items(new_strings);
    string_repo.add_item(" :) ");
    cout << string_repo << endl;
    cout << "Number of items in string repository: " << string_repo.count_items() << endl;




    Course algo("Algorithms", 3000, "Strange", 140);
    Course fundies("Fundementals of CS", 2500, "Park", 200);
    Course cpp("Programming in C++", 3520, "Bhutta", 90);
    Course ood("Object-Oriented Design", 3500, "Shesh", 220);
    Course discrete("Discrete Structures", 2300, "Nunez", 110);
    vector<Course> course_vec;
    course_vec.push_back(algo);
    course_vec.push_back(fundies);
    Repository<Course> course_repo(course_vec);

    cout << endl << endl;
    cout << course_repo << endl;
    course_repo.add_item(cpp);
    cout << course_repo << endl;
    vector<Course> new_courses;
    new_courses.push_back(ood);
    new_courses.push_back(discrete);
    course_repo.add_items(new_courses);
    cout << course_repo << endl;
    cout << "Position of fundies course: " << course_repo.get_pos(fundies) << endl;
    course_repo.remove_item(algo);
    cout << course_repo << endl;
    course_repo.remove_items(new_courses);
    cout << course_repo << endl;
    cout << "Number of items in course repository: " << course_repo.count_items() << endl;






    Book harry("Harry Potter", 357, "JK Rowling", 1997);
    Book choco("Charlie and the Chocolate Factory", 832, "Roald Dahl", 1964);
    Book fault("The Fault in Our Stars", 294, "John Green", 2012);
    Book hunger("The Hunger Games", 519, "Suzanne Collins", 2008);
    Book goodnight("Goodnight Moon", 291, "Margaret Wise Brown", 1947);
    vector<Book> book_vec;
    book_vec.push_back(harry);
    book_vec.push_back(choco);
    Repository<Book> book_repo(book_vec);

    cout << endl << endl;
    cout << book_repo << endl;
    book_repo.add_item(fault);
    cout << book_repo << endl;
    vector<Book> new_book;
    new_book.push_back(hunger);
    new_book.push_back(goodnight);
    book_repo.add_items(new_book);
    cout << book_repo << endl;
    cout << "Position of Hunger Games book: " << book_repo.get_pos(hunger) << endl;
    book_repo.remove_item(fault);
    cout << book_repo << endl;
    book_repo.remove_items(new_book);
    cout << book_repo << endl;
    cout << "Number of items in book repository: " << book_repo.count_items() << endl;


}
