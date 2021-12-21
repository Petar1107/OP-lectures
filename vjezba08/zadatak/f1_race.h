/*1. Napišite klasu timer koja sadrži privatne članove h, m tipa int i s tipa double,
koja predstavlja rezultat u trci Formule 1. Napišite potrebne konstruktore
i operatore kako bi za grupu vozača izračunali:
· prosječnu brzinu svih vozača,
· postignuto vrijeme najbržeg vozača,
· razliku vremena do vremena najbržeg vozača (u sekundama),
· ispisati postignuta vremena u obliku stringa "h:m:s"
Klasa treba imati operatore: +=, -=, +, -, /=, /, <<, operator double
2. Zbog kršenja pravila svi su vozači kažnjejni sa dodatnih m sekundi. Napisati
funkcijski objekt kojim će se postignuto vrijeme vozača povećati za m sekundi.
Pomoć: Za najbržu vožnju koristite funkciju min_element iz <algorithm>.
Da bi funkcija ispravno računala potrebno je definirati operator<.*/
#ifndef F1_RACE_H
#define F1_RACE_H
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class timer
{
	int h, m;
	double s;
public:
	timer()
	{
		h = 0;
		m = 0;
		s = 0;
	}
	timer(int H, int M, double S)
	{
		h = H;
		m = M;
		s = S;
	}
	int get_hours(timer tm);
	int get_minutes(timer tm);
	int get_seconds(timer tm);
	timer operator+(const timer& tm);
	timer operator += (const timer& tm);
	timer operator / (int v_size);
	timer operator /= (int v_size);
	bool operator<(const timer& other);
	double operator - (const timer& other);
	timer operator=(const timer& other);
	friend ostream& operator<<(ostream& output, const timer tm);
};
class penalty {
	double s;
public:
	penalty()
	{
		s = 0;
	}
	penalty(double S) 
	{
		s = S;
	}
	penalty operator() (timer tm);
};
#endif // !F1_RACE_H
