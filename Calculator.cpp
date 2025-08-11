
#include <iostream>
using namespace std;
int main()
{
	//2 input variable declaration with default value
	int num1 =0;
	int num2 =0;
	cout<<"Please enter 2 numbers." << endl;
	cout<<"Please enter num1 : ";
	cin>>num1;
	cout<<"Please enter num2 : ";
	cin>>num2;
	
	//perform the operation and declare 2 more variables to hold the result
	int total = num1 + num2;
	int product = num1 * num2;
	
	//display
	cout<<"Total of num1 and num2 : "  << total << endl;
	cout<<"Product of num1 and num2 : "  << product << endl;

	return 0;
}
