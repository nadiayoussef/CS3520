#include <iostream>
using namespace std;


class Employee {
    private:
    int emp_id;
    int salary;
    static string comp_account;


    public:
    string name;
    bool supervisor;
    static string comp_name;


    string print();

    void set_id(int new_id);
    void set_salary(int new_sal);
    void set_comp_account(string new_account);


    int get_id();
    int get_salary();
    string get_comp_account();


    // Empty constructor
    Employee() {
    }

    // Constructor with parameters
    Employee(int id, int sal, string nm, bool super) {
        emp_id = id;
        salary = sal;
        name = nm;
        supervisor = super;
    }
};

    string Employee::comp_name = "Software Development LLC.";
    string Employee::comp_account = "dev@software.com";

string Employee::print() {
    string print;
    print = name + "'s employee ID is " + to_string(emp_id) + ".  They have a salary of $" + to_string(salary) + " a year, and is";
    if(!supervisor) {
        print.append(" not");
    }
    print.append(" a supervisor.");

    return print;
}


void Employee::set_id(int new_id) {
    emp_id = new_id;
}



void Employee::set_salary(int new_sal) {
    salary = new_sal;
}


void Employee::set_comp_account(string new_account) {
    comp_account = new_account;
}



int Employee::get_id() {
    return emp_id;
}

int Employee::get_salary() {
    return salary;
}

string Employee::get_comp_account() {
    return comp_account;
}




int main() {

    Employee first;
    first.set_id(0267);
    first.set_salary(500000);
    first.name  = "Varshini";
    first.supervisor = false;
    Employee second(3681, 500001, "Nadia", true);
    // Employee second;
    // second.set_id(3681);
    // second.set_salary(500001);
    // second.name  = "Nadia";
    // second.supervisor = true;


    cout << "First employee memory address: " << &first << endl;
    cout << "Second employee memory address: " << &second << endl;
    cout << endl;

    int first_id = first.get_id();
    int first_sal = first.get_salary();
    string first_acc = first.get_comp_account();
    cout << "First employee ID: " << first_id << " - address: " << &first_id << endl;
    cout << "First employee salary: " << first_sal << " - address: " << &first_sal << endl;
    cout << "First employee company account: " << first_acc << " - address: " << &first_acc << endl;
    cout << "First employee name: " << first.name << " - address: " << &first.name << endl;
    cout << "First employee supervisor status: " << boolalpha << first.supervisor << " - address: " << &first.supervisor << endl;
    cout << "First employee company name: " << first.comp_name << " - address: " << &first.comp_name << endl;
    
    cout << endl;

    int second_id = second.get_id();
    int second_sal = second.get_salary();
    string second_acc = second.get_comp_account();
    cout << "Second employee ID: " << second_id << " - address: " << &second_id << endl;
    cout << "Second employee salary: " << second_sal << " - address: " << &second_sal << endl;
    cout << "Second employee company account: " << second_acc << " - address: " << &second_acc << endl;
    cout << "Second employee name: " << second.name << " - address: " << &second.name << endl;
    cout << "Second employee supervisor status: " << boolalpha << second.supervisor << " - address: " << &second.supervisor << endl;
    cout << "Second employee company name: " << second.comp_name << " - address: " << &second.comp_name << endl;

    cout << endl;

    cout << first.print() << endl;
    cout << second.print() << endl;
    
}