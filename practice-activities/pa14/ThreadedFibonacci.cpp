#include <iostream>
#include <iomanip>
#include<future>
#include <ctime>
#include <future>
using namespace std;

class ThreadData {
public:
	time_t startTime; // time thread starts processing
	time_t endTime; // time thread finishes processing
};

unsigned long long int fibonacci(unsigned int n); // function prototype
ThreadData startFibonacci(unsigned int n); // function prototype

int main() {
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
	cout << "Calculating fibonacci(" << fib1 << "), fibonacci(" << fib2
		<< "), and fibonacci(" << fib3 << ") "
		<< "in separate threads." << endl;

	cout << "Starting thread to calculate fibonacci(" << fib1 << ")" << endl;
	auto futureResult1 = async(launch::async, startFibonacci, fib1);
	cout << "Starting thread to calculate fibonacci(" << fib2 << ")" << endl;
	auto futureResult2 = async(launch::async, startFibonacci, fib2);
	cout << "Starting thread to calculate fibonacci(" << fib3 << ")" << endl;
	auto futureResult3 = async(launch::async, startFibonacci, fib3);

	// wait for results from each thread
	ThreadData result1 = futureResult1.get();
	ThreadData result2 = futureResult2.get();
	ThreadData result3 = futureResult3.get();


	// determine time that first thread started
	time_t startTime = (result1.startTime > result3.startTime) ?
		result1.startTime : result3.startTime;

	// determine time that last thread terminated
	time_t endTime = (result1.endTime > result3. endTime) ?
		result1.endTime : result3.endTime;

	// display total time for calculations
	cout << "Total calculation time = "
		<< difftime(endTime, startTime)/ 60.0 << " minutes" << endl;
} // end main

// exectutes function fibonacci asynchronously
ThreadData startFibonacci(unsigned int n) {
	
	// create a ThreadData object to store times
	ThreadData result = { 0,0 };

	cout << "Calculating fibonacci (" << n << ")" << endl;
	result.startTime = time(nullptr); // time before calculation
	auto fibonacciValue = fibonacci(n);
	result.endTime = time(nullptr); // time after calculation

	// display fibonacci calculation result and total calculation time
	cout << "fibonacci(" << n << ") = " << fibonacciValue << endl;
	cout << "Calculation time = "
		<< difftime(result.endTime, result.startTime) / 60.0
		<< " minutes\n" << endl;
	cout << "Thread id for " << n << ": " << this_thread::get_id() << endl;
	return result;
}

// Recursively calculates fibonacci numbers
unsigned long long int fibonacci(unsigned int n) {
	// base case
	if (0 == n || 1 == n) {
		return n;
	}
	// recursive step
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}