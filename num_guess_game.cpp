#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    int randomNumber = rand() % 100 + 1; // Select a random number between 1 and 100
    int userGuess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (userGuess < randomNumber) {
            cout << "The number is too low." << endl;
        } else if (userGuess > randomNumber) {
            cout << "The number is too high." << endl;
        } else {
            cout << "The number is right." << endl;
            break; // Exit the loop if the guess is correct.
        }
    }

    cout << "Thank you for playing the Number Guessing Game!" << endl;
    return 0;
}
