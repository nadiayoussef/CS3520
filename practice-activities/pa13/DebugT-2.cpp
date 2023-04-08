// Debug T-2
// Function template finds biggest of two or three objects. The function works on any data type which has greater than operator defined.

#include <iostream>
#include <string>
using namespace std;
template <class T>
// Function description above says this should compare three objects, not two objects and an integer
void findBiggest(T a, T b, T c) // change b data type from int to T
{
   T large = a;
   if (b > large)
      large = b;
   if (c < large)
      large = c;
   cout << "The largest of " << a << " " << b << " " << c << " is " << a << endl;
}


template <class T>
void findBiggest(T a, T b)
{
   T large = a;
   if (b > large) // == should be > to compare which is larger
      large = b;
   cout << "The larger of " << a << " " << b << " is " << large << endl; // Change "largest" to "large"

}


class BankAccount
{
   friend ostream &operator<<(ostream &, const BankAccount &);

private:
   string name;
   int amount;

public:
   BankAccount(const string, const int); // constructor missing the string input for the BankAccount's name
   bool operator>(const BankAccount &);
   bool operator<(const BankAccount &); // Need to also define a < operator as it is used in the 3-object findBiggest function
};


BankAccount::BankAccount(const string name, const int amount) // unnecessary &, does not need to be a reference variable (?)
{
   // Need to include -> to differentiate the class variable from the local constructor variable since their names are the same
   this->name = name;
   this->amount = amount;
}


ostream &operator<<(ostream &out, const BankAccount &bh)
{
   // Need to include bh. before name and amount to indicate that it is the name/amount from the given bh object
   out << "Name: " << bh.name << " Amount: " << bh.amount << endl; // Misplaced quotation, should go before << operator
   return out;
}


bool BankAccount::operator>(const BankAccount &bh)
{
   bool flag = false; // == should be singular = in order to assign value rather than check equality
   if (amount > bh.amount)
      flag = true;
   return flag;
}

// Define added < operator overload
bool BankAccount::operator<(const BankAccount &bh)
{
   bool flag = false;
   if (amount < bh.amount)
      flag = true;
   return flag;
}




int main()
{
   BankAccount bAA("A", 800);
   BankAccount bAB("B", 120);
   BankAccount bAC("C", 500);
   findBiggest(bAA, bAB);
   findBiggest(bAB, bAC);
   findBiggest(bAC, bAA);
   findBiggest(bAA, bAB, bAC);
   return 0;
}
