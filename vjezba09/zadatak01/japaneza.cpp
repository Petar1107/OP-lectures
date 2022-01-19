#include "japaneza.h"

Game::Game() 
{
	this->pointsToWin = 3;
	this->running = true;
}

bool Game::checkWin(int points) 
{
	return (this->pointsToWin == points);
}

bool Game::isRunning() 
{
	return running;
}
