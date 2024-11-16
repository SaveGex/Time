#include "Time.h"

void Time::time_transition() {
    if (hour < 0 || minute < 0 || second < 0) {
        throw invalid_argument("Time values cannot be negative!");
    }
    while (second >= 60 || minute >= 60) {
        if (second >= 60) {
            second -= 60;
            minute++;
        }
        if (minute >= 60) {
            minute -= 60;
            hour++;
        }
    }
}

Time::Time(int hour, int minute, int second) : hour{ hour }, minute{ minute }, second{ second } {
    try {
        time_transition();
    }
    catch (const exception& e) {
        cerr << "Error in constructor: " << e.what() << endl;
    }
}

Time::Time(int minute, int second) : minute{ minute }, second{ second } {
    try {
        time_transition();
    }
    catch (const exception& e) {
        cerr << "Error in constructor: " << e.what() << endl;
    }
}

Time::Time(int seconds) : second{ seconds } {
    try {
        time_transition();
    }
    catch (const exception& e) {
        cerr << "Error in constructor: " << e.what() << endl;
    }
}

string Time::getter_all() {
    return " hours: " + to_string(hour) + " minutes: " + to_string(minute) + " seconds: " + to_string(second);
}

Time& Time::operator+=(Time& obj) {
    try {
        this->hour += obj.hour;
        this->minute += obj.minute;
        this->second += obj.second;
        time_transition();
    }
    catch (const exception& e) {
        cerr << "Error in operator+=: " << e.what() << endl;
    }
    return *this;
}

Time& Time::operator-=(Time& obj) {
    try {
        this->hour -= obj.hour;
        this->minute -= obj.minute;
        this->second -= obj.second;
        time_transition();
    }
    catch (const exception& e) {
        cerr << "Error in operator-=: " << e.what() << endl;
    }
    return *this;
}

Time& Time::operator-=(Time&& obj){
    try {
        this->hour -= obj.hour;
        this->minute -= obj.minute;
        this->second -= obj.second;
        time_transition();
    }
    catch (const exception& e) {
        cerr << "Error in operator-=: " << e.what() << endl;
    }
    return *this;
}

istream& operator>>(istream& in, Time& obj) {
    try {
        in >> obj.second;
        obj.time_transition();
    }
    catch (const exception& e) {
        cerr << "Error in operator>>: " << e.what() << endl;
    }
    return in;
}

ostream& operator<<(ostream& out, const Time& obj) {
    out << " hours: " << obj.hour << " minutes: " << obj.minute << " seconds: " << obj.second;
    return out;
}