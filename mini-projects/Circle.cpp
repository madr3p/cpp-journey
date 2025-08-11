#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    // Input
    double radius;
    double pi = 3.149;  // You can change this to a more accurate value

    cout << "Please enter radius: ";
    cin >> radius;
    if (radius <= 0) {
    	cout << "Invalid radius, please try again.";
    	return 0;
	} else {
		cout << endl;
	}
	
    // Calculation
    double perimeterCircle;
    double areaCircle;
    
	perimeterCircle = 2 * pi * radius;
    areaCircle = pi * radius * radius;

    // Display the calculation   
    cout << "Perimeter: " << perimeterCircle << endl;
    cout << "Area: " << areaCircle << endl;

    return 0;
}
