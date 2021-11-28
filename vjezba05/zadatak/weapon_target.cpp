/*Napisati klasu za poziciju točke u prostoru koja ima tri double podatka : dužinu,
širinu i visinu(x, y, z koordinate).Klasa ima sljedeće funkcije :
◦ Funkciju za postavljanje vrijednosti članova(treba imati pretpostavljene vrijednosti 0).
◦ Funkciju za postavljanje pseudorandom vrijednosti članova(granice intervala
	su parametri funkcije).
	◦ Funkciju za dohvaćanje vrijednosti članova.
	◦ Funkciju koja računa udaljenost do druge točke u 2D ravnini(zanemarujući z
		koordinatu).
	◦ Funkciju koja računa udaljenost do druge točke u 3D prostoru.
	U main funkciji postavite vrijednost za dvije točke u prostoru i ispišite obe udaljenosti.
	2. Napisati klasu koja predstavlja oružje.Oružje ima svoj položaj u prostoru(jedna
		točka u prostoru), broj metaka koji stanu u jedno punjenje i trenutni broj metaka u
	punjenju.Može pucati(shoot) i ponovo se puniti(reload).
	3. Napisati klasu koja predstavlja metu.Meta je oblika kvadra i zadana je donjom
	lijevom i gornjom desnom točkom.Ima dva stanja : pogođena i nepogođena.
	4. Napisati program koji će generirati n meta i jednog pucača(oružje).Uz pretpostavku
	da je položaj oružja horizontalan i da se oružje može zakretati za 360◦
	, izračunati
	koliko je meta pogođeno jednim punjenjem.
	Označite sa const funkcije i vrijednosti koje su konstantne.*/
#include "weapon_target.h"
#include <iostream>
point3d point3d::set_values(point3d point)
{
	point.x = 0;
	point.y = 0;
	point.z = 0;
	return point;
}
point3d point3d::set_random_values(point3d point, double a, double b)
{
	point.x = (b - a) * ((((double)rand()) / (double)RAND_MAX)) + a;
	point.y = (b - a) * ((((double)rand()) / (double)RAND_MAX)) + a;
	point.z = (b - a) * ((((double)rand()) / (double)RAND_MAX)) + a;
	return point;
}
double* point3d::get_x_coordinates(point3d point)
{
	return &point.x;
}
double* point3d::get_y_coordinates(point3d point)
{
	return &point.y;
}
double* point3d::get_z_coordinates(point3d point)
{
	return &point.z;
}
double point3d::distance2d(point3d point1, point3d point2)
{
	double distance;
	distance = sqrt((pow(point1.x - point1.x, 2)) + (pow(point2.y - point1.y, 2)));
	return distance;
}
double point3d::distance3d(point3d point1, point3d point2)
{
	double distance;
	distance = sqrt((pow(point1.x - point1.x, 2)) + (pow(point2.y - point1.y, 2)) + (pow(point2.z - point1.z, 2)));
	return distance;
}
void weapon::reload(weapon w)
{
	w.current_bullets = w.magazine_capacity;
}
void weapon::shoot(weapon w)
{
	if (w.current_bullets >= 1)
		w.current_bullets--;
	else
		reload(w);
}
void shooting(weapon w, target* t, int number_of_targets)
{
	int number_of_hits = 0;
	int hits_with_one_magazine = 0;
	cout << "weapon height: " << w.weapon_point.z << endl;
	for (int i = 0; i < number_of_targets; i++)
	{
		cout << "target " << i << endl;
		cout << "lower target height: " << t[i].first_point.z << endl;
		cout << "higher targer  height: " << t[i].second_point.z << endl;
		cout << endl;
		if (w.weapon_point.z > t[i].first_point.z && w.weapon_point.z < t[i].second_point.z)
		{
			w.shoot(w);
			number_of_hits++;
			t[i].target_contidion = true;
			if (i < w.magazine_capacity)
			{
				hits_with_one_magazine++;
			}
		}
	}
	cout << "Total hits: " << number_of_hits << endl;
	cout << "number of hits with one magazine: " << hits_with_one_magazine << endl;
}
