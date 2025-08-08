#include <iostream> //the library of cpp
using namespace std; //this lets you use int, string, if else & more

int main() {
    string name; //declaring name, string = character/alphabets
    string state; //declaring state, string = character/alphabets
	int age; //declaring age, int = integer/numbers
	int postcode; //declaring state postcode
	
    cout << "What's your name? "; //cout = output/display
    cin >> name; //cout = input/requires the user to input something

	cout << "Hello, " << name << "! Welcome to UPSI!" << endl; //endl = end line, /l = new line

    cout << "How old are you? ";
    cin >> age;

	if (age >= 18) {
    	// if age is 18 or more, say they're qualified
        cout << "Nice, you're qualified!" << endl;
    } else {
    	// if age is less than 18, say they're not old enough
        cout << "Oops, sorry you're not old enough." << endl;
        return 0;
    }
    
	cout << "Which state are you from? ";
	cin >> state;
	
	cout << "Oh you're from " << state << "! I hope you enjoy it here.";
	
	cout << "\nWhat postcode is your state? ";
	cin >> postcode;
	
	cout << "Great! You know your state postcode which is : " << postcode << " " << state;
	

cout << "\nPlease click any key to exit.";
    
//to keep the window open, insert this before return 0;:
    cin.ignore();
    cin.get();
    
    return 0;
}
