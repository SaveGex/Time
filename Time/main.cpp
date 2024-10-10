#include <iostream>
#include "Time.h"
using namespace std;


int main() {

	Time obj1(3122);
	Time obj2;
	cout << obj1 << "\nWrite value(hours/minutes/seconds or minutes/seconds or seconds):\n";
	cin >> obj2;
	Time result;
	result = (obj1 - obj2);
	cout <<'\n' << result;
	//++, –, != , == , > , <, >> , << , =, +=, –=, ().
	result++;
	cout <<'\n'<< result;
	cout << '\n' << "result != result: " << ((result != result) ? "true" : "false");
	cout << '\n' << "result == result: " << ((result == result) ? "true" : "false");
	cout << '\n' << "result > obj2: " << ((result > obj2) ? "true" : "false");
	cout << "\nobj1: " << obj1.getter_all();
	cout << '\n' << "result < obj2: " << ((result < obj2) ? "true" : "false");
	cout << '\n' << result;
	result += obj2;
	cout << '\n' << result;
	result -= obj2;
	cout << '\n' << result;


	return 0;
}