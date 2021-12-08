#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
class model
{
	vector <char> usedLetters;
public:
	string movie;
	string guessMovie;
	string censoredMovie;
	int lives = 8;
	bool ingame = true;
	void pickRandomMovie(string& movie);
	void SetUsedLetters(vector <char> u);
	vector <char> getUsedLetters();
};

class controler
{
public:
	char userEntry();
	bool checkLetter(char chosenLetter, string movie);
	void updateLives(int& lives);
	void updateMovieDisplay(string movie, string& censoredMovie, char chosenLetter);
	bool checkIfGameIsOver(int lives, string censoredMovie);
};

class view
{
public:
	void displayCurrentProgress(string movie, string censoredMovie, int lives);
	void displayUsedLetters(vector <char>& usedLetters);
	void displayHangman(int lives);
	void refreshConsole(model m);
};
#endif // !HANGMAN_H

