#include "hangman_model.h"
using namespace std;

void model::SetUsedLetters(vector <char> u)
{
    usedLetters = u;
}
vector <char> model::getUsedLetters()
{
    return usedLetters;
}
void model::pickRandomMovie(string& movie) {

    srand(time(NULL));
    int  counter = 0;
    ifstream file("movie.txt");
    string strInFile;
    while (getline(file, strInFile))
        counter++;
    file.clear();
    file.seekg(0);
    int Counter2 = 0;
    int numberOfTheline = rand() % counter;
    while (getline(file, movie))
    {
        Counter2++;
        if (numberOfTheline == Counter2)
            break;
    }
};
char controler::userEntry() 
{
    char selectedLetter;
    cout << "Enter the letter: " << endl;
    cin >> selectedLetter;
    return selectedLetter;
};

bool controler::checkLetter(char charGuess, string movie)
{
    return ((movie.find(charGuess) != string::npos) || (movie.find(toupper(charGuess)) != string::npos));
};

void controler::updateLives(int& lives) 
{
    lives--;
};

void controler::updateMovieDisplay(string movie, string& censoredMovie, char selectedLetter) 
{
    int index = 0;
    while ((index = movie.find(selectedLetter, index)) != string::npos)
    {
        censoredMovie[index] = movie[index];
        index = index + 1;
    }
    index= 0;
    while ((index = movie.find(toupper(selectedLetter), index)) != string::npos)
    {
        censoredMovie[index] = movie[index];
        index = index + 1;
    }
};

bool controler::checkIfGameIsOver(int lives, string censoredMovie) 
{
    if (lives > 0 && censoredMovie.find('_') != string::npos)
        return true;
    else
        return false;
};
void view::displayCurrentProgress(string movie, string censoredMovie, int lives) 
{
    cout << "Remaining lives: " << lives << endl;
    cout << "Guess Movie: " << censoredMovie << endl;
};
void view::displayUsedLetters(vector <char>& usedLetters)
{
    cout << "Used letters: ";
    for (int i = 0; i < usedLetters.size(); i++)
        cout << usedLetters[i] << " ";
    cout << endl;
};
void view::displayHangman(int numberOfLives) 
{
    if (numberOfLives == 0)
    {
        cout << "_______  " << endl <<
            "|  /  |  " << endl <<
            "| /   O  " << endl <<
            "|/   /|\\ "<< endl <<
            "|     |  " << endl <<
            "|    / \\" << endl <<
            "|        " << endl <<
            "|________" << endl;
    }
    if (numberOfLives ==  1)
    {
        cout << "_______  " << endl <<
            "|  /  |  " << endl <<
            "| /   O  " << endl <<
            "|/   /|\\" << endl <<
            "|     |  " << endl <<
            "|    /   " << endl <<
            "|        " << endl <<
            "|________" << endl;
    }
    if (numberOfLives == 2)
    {
        cout << "_______  " << endl <<
            "|  /  |  " << endl <<
            "| /   O  " << endl <<
            "|/   /|\\ "<< endl <<
            "|     |  " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|________" << endl;
    }
    if (numberOfLives == 3)
    {
        cout << "_______  " << endl <<
            "|  /  |  " << endl <<
            "| /   O  " << endl <<
            "|/   /|\\ "<< endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|________" << endl;
    }
    if (numberOfLives == 4)
    {
        cout << "_______  " << endl <<
            "|  /  |  " << endl <<
            "| /   O  " << endl <<
            "|/    |\\ "<< endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|________" << endl;
    }
    if (numberOfLives == 5)
    {
        cout << "_______  " << endl <<
            "|  /  |  " << endl <<
            "| /   O  " << endl <<
            "|/    |  " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|________" << endl;
    }
    if (numberOfLives == 6)
    {
        cout << "_______  " << endl <<
            "|  /  |  " << endl <<
            "| /   O  " << endl <<
            "|/       " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|________" << endl;
    }
    if (numberOfLives == 7)
    {
        cout << "_______  " << endl <<
            "|  /  |  " << endl <<
            "| /      " << endl <<
            "|/       " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|________" << endl;
    }
    if (numberOfLives == 8)
    {
        cout << "_______  " << endl <<
            "|  /     " << endl <<
            "| /      " << endl <<
            "|/       " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|        " << endl <<
            "|________" << endl;
    }
};
void view::refreshConsole(model m)
{
    vector <char> used=m.getUsedLetters();
    system("cls");
    displayCurrentProgress(m.movie,m.censoredMovie, m.lives);
    displayUsedLetters(used);
    displayHangman(m.lives);
};
