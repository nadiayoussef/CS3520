#include <iostream>
#include <iomanip>
#include <ctime>
#include <future>
using namespace std;

unsigned long long int fibonacci(unsigned int n);

int main(void)
{
	int fib1;
	int fib2;
	int fib3;
	cout << "Proide a number greater than 30: ";
	cin >> fib1;
	while(fib1 < 30) {
		cout << "Given number not greater than 30, try again: ";
		cin >> fib1;
	}

	cout << "Proide another number greater than 30: ";
	cin >> fib2;
	while(fib2 < 30) {
		cout << "Given number not greater than 30, try again: ";
		cin >> fib2;
	}

	cout << "Proide the last number greater than 30: ";
	cin >> fib3;
	while(fib3 < 30) {
		cout << "Given number not greater than 30, try again: ";
		cin >> fib3;
	}

	cout << endl << endl;


	cout << fixed << setprecision(6);
	cout << "Sequential calls to fibonacci(" << fib1 << "), fibonacci(" << fib2
		 << ") and fibonacci(" << fib3 << ")." << endl;





	cout << "Calculating fibonacci(" << fib1 << ")" << endl;
	time_t startTime1 = time(nullptr);
	unsigned long long int result1 = fibonacci(fib1);
	time_t endTime1 = time(nullptr);

	cout << "fibonacci(" << fib1 << ") = " << result1 << endl;
	cout << "Calculation time = "
		<< difftime(endTime1, startTime1) / 60.0 << "minutes\n";
	cout << "Thread id for " << fib1 << ": " << this_thread::get_id() << endl << endl;






	cout << "Calculating fibonacci(" << fib2 << ")" << endl;
	time_t startTime2 = time(nullptr);
	unsigned long long int result2 = fibonacci(fib2);
	time_t endTime2 = time(nullptr);

	cout << "fibonacci(" << fib2 << ") = " << result2 << endl;
	cout << "Calculation time = "
		<< difftime(endTime2, startTime2) / 60.0 << " minutes\n";
	cout << "Thread id for " << fib2 << ": " << this_thread::get_id() << endl << endl;




	cout << "Calculating fibonacci(" << fib3 << ")" << endl;
	time_t startTime3 = time(nullptr);
	unsigned long long int result3 = fibonacci(fib3);
	time_t endTime3 = time(nullptr);

	cout << "fibonacci(" << fib3 << ") = " << result3 << endl;
	cout << "Calculation time = "
		<< difftime(endTime3, startTime3) / 60.0 << "minutes\n";
	cout << "Thread id for " << fib3 << ": " << this_thread::get_id() << endl << endl;

	cout << endl;

	cout << "Total calculation time = "
		<< difftime(endTime3, startTime1) / 60.0 << " minutes" << endl;
} // end main

// Recursively calculates fibonacci numbers
unsigned long long int fibonacci(unsigned int n) {
	// base case
	if (0 == n || 1 == n) {
		return n;
	}
	else { // recursive step
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}