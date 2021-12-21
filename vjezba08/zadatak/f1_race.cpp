#include "f1_race.h"
int timer::get_hours(timer tm)
{
	return h;
}
int timer::get_minutes(timer tm) 
{
	return m;
}
int timer::get_seconds(timer tm) 
{
	return s;
}
timer timer::operator + (const timer& tm)
{
	this->h = this->h + tm.h;
	this->m = this->m + tm.m;
	this->s += this->s + tm.s;
	if (this->s > 59)
	{
		this->s = this->s - 60;
		this->m++;
	}
	if (this->m > 59)
	{
		this->m = this->m - 60;
		this->h++;
	}
	return *this;
}
timer timer::operator += (const timer& tm)
{
	this->h += tm.h;
	this->m += tm.m;
	this->s += tm.s;
	if (this->s > 59) 
	{
		this->s = this->s - 60;
		this->m++;
	}
	if (this->m > 59) 
	{
		this->m = this->m - 60;
		this->h++;
	}
	return *this;
}
timer timer:: operator / (int v_size)
{
	double time_in_sec = 3600 * this->h + 60 * this->m + this->s;
	time_in_sec /= v_size;

	this->h = time_in_sec / 3600;
	this->m = time_in_sec - (h * 3600) / 60;
	this->s = time_in_sec - (h * 3600) + (m * 60);
	return *this;
}
timer timer::operator /= (int v)
{
	double time_in_sec = 3600 * this->h + 60 * this->m + this->s;
	time_in_sec /= v;

	this->h = time_in_sec / 3600;
	this->m = (time_in_sec - h * 3600) / 60;
	this->s = time_in_sec - h * 3600 - m * 60;
	return *this;
}
ostream& operator<<(ostream& output, const timer tm) 
{
	output << tm.h << ":" << tm.m << ":" << tm.s << endl;
	return output;
}

bool timer::operator<(const timer& other) 
{
	double time1 = 3600 * this->h + 60 * this->m + this->s;
	double time2 = 3600 * other.h + 60 * other.m + other.s;
	return time1 < time2;
}
timer timer::operator=(const timer& other) 
{
	h = other.h;
	m = other.m;
	s = other.s;
	return *this;
}

double timer::operator - (const timer& other)
{
	double time1 = 3600 * this->h + 60 * this->m + this->s;
	double time2 = 3600 * other.h + 60 * other.m + other.s;
	return time1 - time2;
}
penalty penalty::operator()(timer tm)
{
	int seconds = tm.get_seconds(tm);
	s += seconds;
	return *this;
}
