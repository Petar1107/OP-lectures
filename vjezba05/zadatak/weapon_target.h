#ifndef POINT_WEAPON_TARGET
#define POINT_WEAPON_TARGET
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class point3d
{
public:
	double x;
	double y;
	double z;
	//function prototypes
	point3d set_values(point3d point);
	point3d set_random_values(point3d point, double a, double b);
	double* get_x_coordinates(point3d point);
	double* get_y_coordinates(point3d point);
	double* get_z_coordinates(point3d point);
	double distance2d(point3d point1, point3d point2);
	double distance3d(point3d point1, point3d point2);
};
class weapon : public point3d
{
	const double a = 0, b = 30;
public:
	point3d weapon_point = point3d::set_random_values(weapon_point, a, b);
	int magazine_capacity = 16;
	int current_bullets = 16;
	void shoot(weapon w);
	void reload(weapon w);
};
class target : public point3d
{
	const double a = 0, b = 30;
public:
	point3d first_point = point3d::set_random_values(first_point, a, b);
	point3d second_point = point3d::set_random_values(second_point, a, b);
	bool target_contidion = false;
};
void shooting(weapon w, target* t, int number_of_targets);
#endif // !POINT_WEAPON_TARGET
