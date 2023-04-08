// The goal of this debug exercise is to understand the concept of object slicing.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

// Expected output -
// Name: tesla model Year: 2019
// Name: Hyundai model Year: 2020 Mileage: 23
// Name: Ford model Year: 2012 Miles driven: 20000
// Name: Ford model Year: 2017 Miles driven: 10000

#include <iostream>

using namespace std;

class Car // capitalize car as it is a class name (style)
{
private:
    string name;
    int modelYear;
    // (Moved to public)
    // void assign(const Car &c) // ??
    // {
    //     name = c.name;
    //     modelYear = c.modelYear;
    // }

public:
    Car(const string &n, const int my) : name(n), modelYear(my) {}

    // Need to include getters to be able to access the Car variables outside the Car class in the derived classes
    string getName() const
    {
        return this->name;
    }
    int getMY() const
    {
        return this->modelYear;
    }

    virtual void print() const
    {
        // Need to include this-> in order to access name and modelYear
        cout << "Name: " << this->name << " model Year: " << this->modelYear << endl;
    }

    virtual const Car &operator=(const Car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
        return *this;
    }

    // Moved function to public so it can be accessed by the derived classes
    void assign(const Car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
    }
};


class Sedan : public Car // capitalize sedan as it is a class name (style)
{
private:
    int mileage;

public:
    Sedan(const string &n, const int my, const int m) : Car(n, my), mileage(m) {}

    virtual void print() const
    {
        // Need to use getters to access the name and model year as they are private variables of the Car class
        cout << "Name: " << this->getName() << " model Year: " << this->getMY() << " Mileage: " << mileage << endl;
    }
};



class Suv : public Car // capitalize suv as it is a class name (style)
{
    int miles;

public:
    Suv(const string &n, const int my, const int m) : Car(n, my), miles(m) {}

    virtual void print() const
    {
        // Need to use getters to access the name and model year as they are private variables of the Car class
        cout << "Name: " << this->getName() << " model Year: " << this->getMY() << " Miles driven: " << miles << endl;
    }

    // missing & to denote the c object as a reference variable
    virtual const Suv &operator=(const Car &c)
    {
        if (const Suv *b = dynamic_cast<const Suv *>(&c))
        {
            // specifiying the Suv version of the assign function
            Suv::assign(*b);
        }
        return *this;
    }

protected:
    void assign(const Suv &c)
    {
        Car::assign(c);
        miles = c.miles;
    }
};

// Original function will object slice and remove mileage information if passing a Sedan or Suv object
// void printCarInfo(const Car c)
// {
//     c.print();
// }

// This function uses a template and takes in a reference variables so it can take any of the Car's derived classes
// and not object slice them because it will use their own print method
template<class T>
void printCarInfo(const T &car) {
    car.print();
}



int main()
{
    Car tesla = Car("tesla", 2019);
    Sedan hyundai = Sedan("Hyundai", 2020, 23);
    Suv ford = Suv("Ford", 2012, 20000);

    printCarInfo(tesla);
    printCarInfo(hyundai);

    Car &ref = ford;
    printCarInfo(ref);
    Suv ford2 = Suv("Ford", 2017, 10000);
    ref = ford2;
    printCarInfo(ref);
    return 0;
}