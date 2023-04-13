#include <iostream>
using namespace std;

class Book {
  friend ostream &operator<<(ostream &, const Book &);

  private:
    string title;
    int id;
    string author;
    int pub_year;

  public:
    Book(string t, int c, string a, int y);
    // getters
    string get_title();
    int get_id();
    string get_author();
    int get_year();

    // setters
    void set_title(string t);
    void set_id(int i);
    void set_author(string a);
    void set_year(int y);

    bool operator==(const Book &);   
    bool operator!=(const Book &); 
    
};
