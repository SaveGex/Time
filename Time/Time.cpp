
#include "Time.h"

void Time::time_transition(){
	if (this->hour < 0) {
		this->hour = 0;
	}
	if (this->minute < 0) {
		this->minute = 0;
	}
	if (this->second < 0) {
		this->second = 0;
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
	time_transition();
}

Time::Time(int minute, int second) {
	if (second < 0) {
		this->second = 0;
	}
	if (minute < 0) {
		this->minute = 0;
	}
	time_transition();
}

Time::Time(int seconds) : second{ seconds } {
	time_transition();
}

Time::Time() : Time(0,0,0)
{
}

Time& Time::operator++(int) {
	this->minute++;
	time_transition();
	return *this;
}

Time Time::operator-(int& seconds) {
	if (seconds > (hour * 60 * 60) + (minute * 60) + second) {
		hour = minute = second = 0;
	}
	else {
		while (seconds > 0) {
			if (hour > 0) {
				int hour_buf = seconds * 60 * 60;
				if (hour < hour_buf) {
					hour = 0;
					seconds = (hour_buf - hour) / 60 / 60;
				}
				else {
					hour -= hour_buf;
					seconds = 0;
				}
			}
			if (minute > 0) {
				int minute_buf = seconds * 60;
				if (minute < minute_buf) {
					minute = 0;
					seconds = (minute_buf - minute) / 60;
				}
				else {
					minute -= minute_buf;
					seconds = 0;
				}
			}
			if (second > 0) {
				if (second < seconds) {
					seconds = 0;
					second = 0;
				}
				else {
					second -= seconds;
					seconds = 0;
				}
			}
		}
	}
	time_transition();
	return Time((hour * 60 * 60) + (minute * 60) + second);
}

Time Time::operator-(Time& obj){
	return Time(this->hour - obj.hour, this->minute - obj.minute, this->second - obj.second);
}

Time& Time::operator=(Time obj)
{
	this->hour = obj.hour;
	this->minute = obj.minute;
	this->second = obj.second;	
	return *this;
}

Time Time::operator=(Time& obj)
{
	return Time(obj.hour, obj.minute, obj.second);
}

Time& Time::operator+=(Time& obj)
{
	this->hour += obj.hour;
	this->minute += obj.minute;
	this->second += obj.second;
	time_transition();
	return *this;
}

Time& Time::operator-=(Time& obj) {
	this->hour -= obj.hour;
	this->minute -= obj.minute;
	this->second -= obj.second;
	time_transition(); 
	return *this; 
}


bool Time::operator!=(Time& obj){
	if (this->hour != obj.hour && this->minute != obj.minute && this->second != obj.second) {
		return true;
	}
	return false;
}

bool Time::operator==(Time& obj){
	if (this->hour == obj.hour && this->minute == obj.minute && this->second == obj.second) {
		return true;
	}
	return false;
}

bool Time::operator>(const Time& obj){
	if ((this->hour * 60 * 60 + this->minute * 60 + this->second) > (obj.hour * 60 * 60 + obj.minute * 60 + obj.second)) {
		return true;
	}

	return false;
}

bool Time::operator<(const Time& obj)
{
	if ((this->hour * 60 * 60 + this->minute * 60 + this->second) < (obj.hour * 60 * 60 + obj.minute * 60 + obj.second)) {
		return true;
	}

	return false;
}

istream& operator>>(istream& in, Time& obj)
{
	in >> obj.second;
	obj.time_transition();
	return in;
}

ostream& operator<<(ostream& out, Time& obj)
{
	out << " hours: " << obj.hour << " minutes: " << obj.minute << " seconds: " << obj.second;
	return out;
}
