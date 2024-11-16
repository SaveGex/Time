#pragma once
#ifndef Time_h
#define Time_h

#include <cassert>
#include <ctime>
#include <iostream>
#include <string>
#include <stdexcept> 

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

    Time() : Time(0, 0, 0) {}

    string getter_all();

    Time& operator+=(Time& obj);

    Time& operator-=(Time& obj);
    Time& operator-=(Time&& obj);

    friend istream& operator>>(istream& in, Time& obj);

    friend ostream& operator<<(ostream& out, const Time& obj);
};

#endif // !Time_h
