#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player 
{
private:
	int currentPoints;
	int points;

public:
	Player();
	void checkCurrentHand(int guess);
	int getPoints();
	void setHand(int coin);
	int getHand();
	void resetHand();
};

class ComputerPlayer : public Player
{
public:
	void chooseSumOfCoins();
	int guessSumOfCoins();
};

class HumanPlayer : public Player
{
public:
	void chooseSumOfCoins();
	int guessSumOfCoins();
};
