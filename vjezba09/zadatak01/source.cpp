#include "japaneza.h"
#include "player.h"
int main() 
{
	Game game;
	HumanPlayer human;
	ComputerPlayer computer;

	while (game.isRunning()==true)
	{
		human.chooseSumOfCoins();
		human.checkCurrentHand(computer.guessSumOfCoins());
		if (game.checkWin(human.getPoints())) 
		{
			cout << "You win\n";
			game.running = false;
		}
		computer.chooseSumOfCoins();
		computer.checkCurrentHand(human.guessSumOfCoins());
		if (game.checkWin(computer.getPoints())) 
		{
			cout << "Game Over \n";
			game.running = false;
		}
	}
}
