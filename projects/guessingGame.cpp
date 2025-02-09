#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void displayWordProgress(const string& word, const vector<char>& guessedLetters) {
    for (char c : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
            cout << c;
        } else {
            cout << "_";
        }
    }
    cout << endl;
}

bool containsLetter(const string& word, char letter) {
    return word.find(letter) != string::npos;
}

bool isWordGuessed(const string& word, const vector<char>& guessedLetters) {
    for (char c : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) == guessedLetters.end()) {
            return false;
        }
    }
    return true;
}

string chooseRandomWord(int choice) {
    srand(static_cast<unsigned int>(time(0)));
    vector<string> animalNames = {"gorilla", "elephant", "dog", "cat", "bird"};
    vector<string> teams = {"falcons", "eagles", "panthers"};
    vector<string> districts = {"nyabihu", "muhanga", "kamonyi", "nyanza", "ngororero"};
    vector<string> movies = {"superman", "batman", "theflash", "wonderwoman", "endgame"};
    vector<string> books = {"nancydrew", "hacking", "science"};

    vector<string> chosenCategory;
    switch (choice) {
    case 1:
        chosenCategory = animalNames;
        break;
    case 2:
        chosenCategory = teams;
        break;
    case 3:
        chosenCategory = districts;
        break;
    case 4:
        chosenCategory = movies;
        break;
    case 5:
        chosenCategory = books;
        break;
    default:
        cout << "Invalid category selected" << endl;
        return "";
    }

    return chosenCategory[rand() % chosenCategory.size()];
}

void guessingGame(const string& word) {
    int maxAttempts = 3;
    vector<char> guessedLetters;
    int attempts = 0;

    cout << "The length of the word to guess is: " << word.size() << " letters." << endl;

    while (attempts < maxAttempts) {
        cout << "\nEnter a letter to guess, or type 'exit' to quit: ";
        string input;
        cin >> input;

        if (input == "exit") {
            cout << "Exiting the game." << endl;
            return;
        }

        char guess = input[0];

        if (containsLetter(word, guess)) {
            cout << "Correct! '" << guess << "' is in the word." << endl;
            guessedLetters.push_back(guess);
        } else {
            cout << "Sorry, '" << guess << "' is not in the word." << endl;
            attempts++;
        }

        displayWordProgress(word, guessedLetters); // Show the current state of the guessed word

        if (isWordGuessed(word, guessedLetters)) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            return;
        }

        cout << "Attempts remaining: " << maxAttempts - attempts << endl;
    }

    cout << "You've run out of attempts! The word was: " << word << endl;
}

int main() {
    cout << "Welcome to the Word Guessing Game!" << endl;

    while (true) {
        cout << "\nChoose a category to start guessing:" << endl;
        cout << "1. Animal Names" << endl;
        cout << "2. Teams" << endl;
        cout << "3. Districts" << endl;
        cout << "4. Movies" << endl;
        cout << "5. Books" << endl;
        cout << "Enter '0' to exit." << endl;

        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "Thank you for playing! Exiting the game." << endl;
            break;
        }
        string word = chooseRandomWord(choice);
        if (word.empty()) continue;

        guessingGame(word);

        cout << "Would you like to play again? (y/n): ";
        char playAgain;
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thank you for playing! Exiting the game." << endl;
            break;
        }
    }

    return 0;
}
