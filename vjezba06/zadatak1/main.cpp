#include "hangman_model.h"
using namespace std;
int main()
{
	char selectedLetter;
	model m;
	controler c;
	view v;
	m.pickRandomMovie(m.movie);
	v.refreshConsole(m);
	while (c.checkIfGameIsOver(m.lives,m.censoredMovie))
	{
		selectedLetter = c.userEntry();
		if (c.checkLetter(selectedLetter,m.movie)) {
			c.updateMovieDisplay(m.movie,m.censoredMovie, selectedLetter);
		}
		else {
			vector <char> v = m.getUsedLetters();
			v.push_back(selectedLetter);
			m.SetUsedLetters(v);
			c.updateLives(m.lives);
		}
		v.refreshConsole(m);
	}
	if (m.movie == m.censoredMovie)
	{
		cout << "YOU WIN!!!" << endl;
	}
	else
	{ 
		cout << "Randomly selected movie was: " << m.movie << endl;
		cout << "GAME OVER" << endl;
	}
	
}
