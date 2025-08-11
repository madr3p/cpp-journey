/*target answer 38
when user guess 98 > response > less than 98
				60 > response > less than 60
				28 > response > more than 28
			    38 > response, bingo, you got the number!
*/

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main()
{
    // Seed random number generator once at the beginning
    srand(time(0));

    int answer;
    int userInput;

    // Loop for 2 rounds
    for (int round = 1; round <= 2; round++) {
        cout << "=== ROUND " << round << " ===" << endl;

        // Generate a new random number for each round
        answer = rand() % 1000  + 1;
        userInput = 0;

        do {
            cout << "Please enter your guess: ";
            cin >> userInput;

            if (userInput == answer) {
                cout << "Bingo! You got the number!" << endl;
            } else if (userInput > answer) {
                cout << "Wrong answer! Guess smaller!" << endl;
            } else {
                cout << "Wrong answer! Guess bigger!" << endl;
            }

        } while (userInput != answer);

        cout << "Well done! You've completed round " << round << "!\n" << endl;
    }

    cout << "🎉 Game Over! Thanks for playing!" << endl;

    return 0;
}
