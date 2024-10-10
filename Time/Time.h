#pragma once
#ifndef Time_h
#define Time_h

#include <cassert>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class Time {
private:

	int hour = 0;
	int minute = 0;
	int second = 0;

	void time_transition();

public:


	Time(int hour, int minute, int second);
	Time(int minute, int second);
	Time(int seconds);
	Time();

	string getter_all() {
		return " hours: " + to_string(hour) + " minutes: " + to_string(minute) + " seconds: " + to_string(second);
	}

	Time& operator++(int);
	
	Time operator-(int& seconds);
	Time operator-(Time& obj);
	Time& operator=(Time obj);
	Time operator=(Time& obj);
	Time& operator+=(Time& obj);
	Time& operator-=(Time& obj);

	bool operator!=(Time& obj);
	bool operator==(Time& obj);
	bool operator>(const Time& obj);
	bool operator<(const Time& obj);
	
	friend istream& operator>>(istream& in, Time& obj);
	friend ostream& operator<<(ostream& out, Time& obj);


};

#endif // !Time_h
