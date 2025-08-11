#include <iostream>
using namespace std; //allow us to use int, etc
/*
get the arrea and perimeter for a rectangle
1. get the formula
2. determine the user input (2-lenght&width)
3. ensure the user input is more than 0
4. perform the calculation with the given right inputs
5. display the calculated result to the user
*/


int main(int argc, char** argv) {
	//perimeter ==> 2 * (length + width)
	//area ==> lenght * width
	
	//define 2 variable - with int data type
	int length;
	int width;

	cout<<"Please enter length : ";
	cin>>length;
	
	cout<<"Please enter width : ";
	cin>>width;
	cout<<endl;
	
	//execute the calculation
	int perimeter;
	int area;
	
	perimeter = 2 * (length + width);
	area = length + width;
	
	//display the calculation
	cout<<"Area : "<<area<<endl;
	cout<<"Perimeter : "<<perimeter<<endl;

	return 0;
}