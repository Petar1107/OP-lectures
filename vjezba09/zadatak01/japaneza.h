#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game 
{
private:
	int pointsToWin;

public:
	Game();
	bool running;
	bool checkWin(int points);
	bool isRunning();
};
