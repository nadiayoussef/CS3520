#include <iostream>
#include <vector>
using namespace std;


class Employee {
    private:
    string name;
    string email;
    string desig;
    double salary;
    int group_id;
    
    public:
    // Setters
    void set_emp_name(string emp_name) {
        name = emp_name;
    }

    void set_email(string emp_email) {
        email = emp_email;
    }

    void set_desig(string emp_desig) {
        desig = emp_desig;
    }

    void set_sal(double sal) {
        salary = sal;
    }

    void set_gid(int emp_gid) {
        group_id = emp_gid;
    }


    // Getters
    string get_name() {
        return name;
    }

    string get_email() {
        return email;
    }

    string get_desig() {
        return desig;
    }
   
    int get_sal() {
        return salary;
    }

    int get_gid() {
        return group_id;
    }


    friend istream& operator>> (istream& in, Employee& employee );
    friend ostream& operator<< (ostream& out, const Employee& employee);


};

class Group {
    private:
    string name;
    int num;
    string focus;
    vector<Employee> employees;

    public:
    // Setters
    void set_gname(string g_name) {
        name = g_name;
    }

    void set_gnum(int g_num) {
        num = g_num;
    }
    void set_focus(string g_focus) {
        focus = g_focus;
    }

    void set_emps(vector<Employee> g_emps) {
        employees = g_emps;
    }

    // Getters
    string get_gname() {
        return name;
    }

    int get_gnum() {
        return num;
    }
    string get_focus() {
        return focus;
    }

    vector<Employee> get_emps() {
        return employees;
    }

    // Overloading Group - operator
    Group operator-(const int &fire) {
        Group new_group;
        new_group.set_gname(this->get_gname());
        new_group.set_gnum(this->get_gnum());
        new_group.set_focus(this->get_focus());

        vector<Employee> new_emps = this->get_emps();
        new_emps.resize(new_emps.size() - fire);

        new_group.set_emps(new_emps);

        return new_group;
    }

    // Overloading Group + operator
    Group operator+(Group &add_group) {
        Group new_group;
        new_group.set_gname(this->get_gname());
        new_group.set_gnum(this->get_gnum());
        new_group.set_focus(this->get_focus());

        vector<Employee> new_emps = this->get_emps();
        
        for (auto emp : add_group.get_emps()) {
            new_emps.push_back(emp);
        }

        new_group.set_emps(new_emps);

        return new_group;
    }

    // Overloading Group / operator
    Group operator/(Group &div_group) {
        Group new_group;
        new_group.set_gname(this->get_gname());
        new_group.set_gnum(this->get_gnum());
        new_group.set_focus(this->get_focus());
        new_group.set_emps(this->get_emps());

        return new_group;
    }

    

    friend istream& operator>> (istream& in, Group& group);
    friend ostream& operator<< (ostream& out, const Group& group);



};

// Employee output
ostream& operator<< (ostream& out, Employee& employee) {
    out << "Employee name: " << employee.get_name() << endl;
    out << "Employee email: " << employee.get_email() << endl;
    out << "Employee designation: " << employee.get_desig() << endl;
    out << "Employee salary: " << employee.get_sal() << endl;
    out << "Employee group ID: " << employee.get_gid() << endl;
    out << endl;

    return out;
}



// Group output
ostream& operator<< (ostream& out, Group& group) {
    out << "Group name: " << group.get_gname() << endl;
    out << "Group ID Number: " << group.get_gnum() << endl;
    out << "Group focus: " << group.get_focus() << endl;
    out << "Group members: " << endl;
    for (auto member : group.get_emps()) {
        out << member.get_name() << endl;
    }
    out << endl;

    return out;
}


// Employee input
istream& operator>> (istream& in, Employee& employee) {
    in >> employee.name >> employee.email >> employee.desig;
    in >> employee.salary >> employee.group_id;
    return in;
}



// Group input
istream& operator>> (istream& in, Group& group) {
    in >> group.name >> group.num >> group.focus;
    for (auto member : group.get_emps()) {
        in >> member;
    }
    return in;
}




int main() {
    // Filler data
    Employee nadia;
    nadia.set_emp_name("Nadia");
    nadia.set_email("nadia@gamedev.com");
    nadia.set_desig("VFX");
    nadia.set_sal(35);
    nadia.set_gid(1238);

    Employee norah;
    norah.set_emp_name("Norah");
    norah.set_email("norah@gamedev.com");
    norah.set_desig("Designer");
    norah.set_sal(25);
    norah.set_gid(1238);

    Employee omar;
    omar.set_emp_name("Omar");
    omar.set_email("omar@gamedev.com");
    omar.set_desig("Developer");
    omar.set_sal(27);
    omar.set_gid(5673);

    Employee zane;
    zane.set_emp_name("Zane");
    zane.set_email("zane@gamedev.com");
    zane.set_desig("Play Tester");
    zane.set_sal(18);
    zane.set_gid(5673);

    vector<Employee> creative_team;
    creative_team.push_back(nadia);
    creative_team.push_back(norah);

    vector<Employee> technical_team;
    technical_team.push_back(omar);
    technical_team.push_back(zane);

    vector<Employee> full_team;
    full_team.push_back(nadia);
    full_team.push_back(norah);
    full_team.push_back(omar);
    full_team.push_back(zane);

    Group creative;
    creative.set_gname("Creative Team");
    creative.set_gnum(5673);
    creative.set_focus("Visuals");
    creative.set_emps(creative_team);

    Group technical;
    technical.set_gname("Technical Team");
    technical.set_gnum(1238);
    technical.set_focus("Technical Development");
    technical.set_emps(technical_team);

    Group full;
    full.set_gname("Full Team");
    full.set_gnum(0);
    full.set_focus("Game Development");
    full.set_emps(full_team);



    // Testing subtract Group operator
    cout << "Subtract test:" << endl;

    Group testSub = technical;
    cout << "Entire technical team:" << endl;
    for (auto emp : testSub.get_emps()) {
        cout << emp.get_name() << endl;
    }

    cout << "Technical team subtracting one employee:" << endl;
    testSub = testSub - 1;
    for (auto emp : testSub.get_emps()) {
        cout << emp.get_name() << endl;
    }
    cout << endl;


    Group testSubFull = full;
    cout << "Entire full team:" << endl;
    for (auto emp : testSubFull.get_emps()) {
        cout << emp.get_name() << endl;
    }
    cout << "Full team subtracting one employee:" << endl;
    testSubFull = testSubFull - 1;
    for (auto emp : testSubFull.get_emps()) {
        cout << emp.get_name() << endl;
    }
    cout << "Full team subtracting two more employees:" << endl;
    testSubFull = testSubFull - 2;
    for (auto emp : testSubFull.get_emps()) {
        cout << emp.get_name() << endl;
    }

    cout << endl << endl;


    // Testing add Group operator
    cout << "Add test:" << endl;

    Group testAdd = technical;
    cout << "Original technical team:" << endl;
    for (auto emp : testAdd.get_emps()) {
        cout << emp.get_name() << endl;
    }
    cout << "Technical team adding creative group:" << endl;
    testAdd = testAdd + creative;
    for (auto emp : testAdd.get_emps()) {
        cout << emp.get_name() << endl;
    }
    cout << "Full team added to technical and creative groups:" << endl;
    testAdd = testAdd + full;
    for (auto emp : testAdd.get_emps()) {
        cout << emp.get_name() << endl;
    }
    cout << endl << endl;



    // Testing << Group operator
    cout << "Output group test:" << endl;
    cout << creative << endl;
    cout << technical << endl;
    cout << full << endl;

    cout << endl;

    // Testing << Employee operator
    cout << "Output employee test:" << endl;
    cout << nadia << endl;
    cout << omar << endl;
    cout << norah << endl;
    cout << zane << endl;

    // // Testing >> Group operator
    Group input_group;
    cin >> input_group;
    cout << endl;



}