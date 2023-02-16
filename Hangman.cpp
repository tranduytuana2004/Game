#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

const string WORD_LIST[] = {
"angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house", "island", "jewel",  "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
        "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};
const int SIZE_OF_LIBRARY = sizeof( WORD_LIST ) / sizeof( string );
const int MAX_BAD_GUESS = 7;
const string PICTURE[] =
{
    "   -------------    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
"   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |           |    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          /     \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          / \\  \n"
         "   |     \n"
         " -----   \n",

};

string library()
{
    ifstream file("input.txt");
    if (!file) {
        cout << "Cannot open file" << endl;
    }
    else {
        vector<string> words;
        string line;
        while (file >> line) {
            words.push_back(line);
        }
    }
    int randomIndex = rand() % SIZE_OF_LIBRARY;

    return WORD_LIST[ randomIndex ];
}

char newWord()
{
    char key;
    cout << "Enter your guess: ";
    cin >> key;

    return key;
}

void renderGame( string guessedWord, int badGuessCount )
{
    cout << PICTURE[ badGuessCount ] << endl;
    cout << guessedWord << endl;
}

bool contain( string secretWord, char guess )
{
    return ( secretWord.find_first_of( guess ) != string::npos );
}

string update( string& guessedWord, string secretWord, char guess )
{
    for( int i = 0; i < guessedWord.size(); ++i )
    {
        if( guess == secretWord[i] )
        {
            guessedWord[i] = guess;
        }
    }

    return guessedWord;
}

void over( int badGuessCount, string guessedWord, string secretWord )
{
    if ( badGuessCount < MAX_BAD_GUESS )
    {
        cout << guessedWord << endl;
        cout << "Congratulation! You win" << endl;
    }
    else
    {
        system("cls");
        cout << PICTURE[7] << endl;
        cout << "You lost! Good luck next time" << endl;
        cout << secretWord;
    }
}
int main()
{
    srand(time(NULL));
    string secretWord = library();
    string guessedWord = string(secretWord.size(), '_' );
    int badGuessCount = 0;

    do
    {
        system("cls");
        renderGame( guessedWord, badGuessCount );
        char guess = newWord();
        if( contain( secretWord, guess) )
        {
             guessedWord = update( guessedWord, secretWord, guess );
        }
        else
        {
            ++badGuessCount;
        }
    } while( badGuessCount < MAX_BAD_GUESS && guessedWord != secretWord );

    over( badGuessCount, guessedWord, secretWord );

    return 0;
}
