#include <iostream>
#include <limits>   // For std::numeric_limits
#include <random>
#include <chrono>   // For std::chrono::system_clock
using namespace std;

int main() {
    char choice;

    do {
        int guess;

        // Use current time as seed for random generator
        auto seed = chrono::system_clock::now().time_since_epoch().count();
        //Mersenne Twister 19937 random number engine
        mt19937 gen(seed);

        int lower_bound = 1;
        int upper_bound = 20;

        uniform_int_distribution<> distr(lower_bound, upper_bound);

        int random_number = distr(gen);

        cout << "Guess My Number From 1 To 20" << endl;

        // Handle incorrect input types while running
        while (!(cin >> guess)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();                    // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        }

        while (guess != random_number) {
            if (guess < random_number) {
                cout << "Too Low!!!" << endl;
            } else if (guess > random_number) {
                cout << "Too High!!!" << endl;
            }

            // Handle incorrect input types again
            while (!(cin >> guess)) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();                    // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            }
        }

        cout << "You Guessed It!!!" << endl;

        cout << "\nPress Y to Play Again" << endl;
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Exiting the program..." << endl;

    return 0;
}
