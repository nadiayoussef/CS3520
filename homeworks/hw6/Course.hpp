#include <iostream>
using namespace std;

class Course {
  friend ostream &operator<<(ostream &, const Course &);
 
  private:
    string name;
    int crn;
    string prof;
    int capacity;

  public:
    Course(string n, int c, string p, int cap);
    // getters
    string get_name();
    int get_crn();
    string get_prof();
    int get_capacity();

    // setters
    void set_name(string s);
    void set_crn(int c);
    void set_prof(string p);
    void set_capacity(int cap);
    bool operator==(const Course &);   
    bool operator!=(const Course &);   

};
