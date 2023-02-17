// Nadia Youssef, Varshini Sundaresan, Emma Karedenes

#include <iostream>
#include <cstring>
using namespace std;

/*
a) planet_record.planet_id_number
b) planet_ptr->planet_number
c) planet_record.planet_name
d) planet_ptr->planet_name
e) planet_record.personal.age
f) planet_ptr->personal_ptr->age
g) planet_record.personal.origin
h) planet_ptr->personal_ptr->origin
*/

    struct planet { 
        unsigned int planet_number; 
        char* planet_name; 
        struct { 
            char origin [ 10 ]; 
            int age;
        }
        personal, *personal_ptr = &personal; 
    }
    planet_record, *planet_ptr = &planet_record, all_records[5]; 

int main() {
    planet_record.planet_number = 123;
    planet_record.planet_name = (char *)"Venus";
    strcpy(planet_record.personal.origin, "0123456789");
    planet_record.personal.age = 4503;


    cout << planet_record.planet_number << endl;
    cout << planet_ptr->planet_number << endl;
    cout << planet_record.planet_name << endl;
    cout << planet_ptr->planet_name << endl;
    cout << planet_record.personal.age << endl;
    cout << planet_ptr->personal_ptr->age << endl;
    cout << planet_record.personal.origin << endl;
    cout << planet_ptr->personal_ptr->origin << endl;
    cout << endl << endl;

    for(int i = 0; i < 5; i++)
    {
        planet pl;
        pl.planet_number = 1234;
        pl.planet_name = (char *)"Mars";
        strcpy(pl.personal.origin, "0123456789");
        pl.personal.age = 443543;
        all_records[i] = pl;
    }


    for (int i = 0; i < 5; i++)
    {
        cout << "Planet " << (i + 1) << endl;
        cout << "Id: " << all_records[i].planet_number << endl;
        cout << "Name: " << all_records[i].planet_name << endl;
        cout << "Origin: " << all_records[i].personal.origin << endl;
        cout << "Age: " << all_records[i].personal.age << endl;
        cout << endl;
    }


    // Dynamically allocated array
    cout << endl << "Dynamically allocated: " << endl << endl;
    planet planet_records[5];
    planet *ptr_records = planet_records;
    // Ptr_records->array[0].instance_trait;
    // Loop to fill planet_records with (one) planets
    for (int i = 0; i < 5; i++)
    {
        planet pl_dyn;
        pl_dyn.planet_number = 4321;
        pl_dyn.planet_name = (char *)"Neptune";
        strcpy(pl_dyn.personal.origin, "9876543210");
        pl_dyn.personal.age = 22222;

        planet *pl_ptr = NULL;
        pl_ptr = new planet;
        *pl_ptr = pl_dyn;

        planet_records[i] = *pl_ptr;

       delete pl_ptr;
    }

    // Loop to print planets from planet_records
    for (int i = 0; i < 5; i++) {
        cout << "Planet " << (i + 1) << endl;
        cout << "Id: " << ptr_records[i].planet_number << endl;
        cout << "Name: " << ptr_records[i].planet_name << endl;
        cout << "Origin: " << ptr_records[i].personal.origin << endl;
        cout << "Age: " << ptr_records[i].personal.age << endl;
        cout << endl << endl;
    }
}