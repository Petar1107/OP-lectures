#include "weapon_target.h"
int main(void)
{
	/*point3d point1, point2;
	double distance_in_plane,distance_in_space;
	set_random_values(point1,1,30);
	set_random_values(point2,1,30);
	distance_in_plane = distance2d(point1, point2);
	distance_in_space = distance3d(point1, point2);
	cout << distance_in_plane << " " << distance_in_space << endl;*/
	srand(time(NULL));
	int const number_of_targets = 20;
	target t[number_of_targets];
	weapon w;
	shooting(w, t, number_of_targets);
}
