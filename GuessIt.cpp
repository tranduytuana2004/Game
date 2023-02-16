#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber();

int getPlayerGuess();

void printAnswer( int& guess, int secretnumber, int& score );

void question( bool& turn );

int main()
{
    srand( time(NULL) );

    int guess;

    bool turn = 0;

   while ( turn == 0)
   {
        int secretnumber = generateRandomNumber();
        int score = 100;
    do
    {
        guess = getPlayerGuess();
        printAnswer( guess, secretnumber, score );
    } while( guess != secretnumber );

    question( turn );
   }

   return 0;
}

int generateRandomNumber()
{
    return rand() % 100 + 1;
}

int getPlayerGuess()
{
    int guess;
    cout << "Enter your guess : ";
    cin >> guess;

    return guess;
}

void printAnswer( int& guess, int secretnumber, int& score )
{
    if( guess > secretnumber )
    {
        cout << "Too big!" << endl;
        score -= 5;
    }
    else if( guess < secretnumber )
    {
        cout << "Too small" << endl;
        score -= 5;
    }
    else
    {
        cout << "Congratulation!" << endl;
        cout << "Your score is: " << score << endl;
    }
}

void question( bool& turn )
{
    cout << "Do you want to play next game?" << endl;
    cout << "0 to play and 1 to close " << endl;

    int choice;
    cin >> choice;

    if( choice == 1)
    {
        turn = 1;
        cout << "See you next time!" << endl;
    }
    else
    {
        turn = 0;
        cout << "We created a new number!" << endl;
    }
}
