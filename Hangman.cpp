// Hangman
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main (){
    const int maxWrong = 8;
    vector<string> words;
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string theWord = words[0];
    int wrong = 0;
    string soFar(theWord.size(), '-');
    string used = "";

    cout << "Welcome to Hangman. Goodluck!\n";

    while ((wrong < maxWrong) && (soFar != theWord)){
        cout << "\nYou have " << (maxWrong - wrong) << " incorrect guesses left.";
        cout << "\nYou've used the following letters: " << used << endl;
        cout << "\nSo far, the word is: " << soFar << endl;
    

        char guess;
        cout << "\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess);
        while (used.find(guess) != string::npos){
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (theWord.find(guess) != string::npos){
            cout << "That's right!" << guess << " is in the world.\n";

            for (int i = 0; i < theWord.length(); ++i){
                if (theWord[i] ==  guess){
                    soFar[i] = guess;
                }
            }
        }
        else{
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }
    if (wrong == maxWrong){
        cout << "\nYou've been hanged! ";
    }
    else{
        cout <<"\nYou guessed it!";
    }
    cout << "\nThe word was" << theWord;
    return 0;
}