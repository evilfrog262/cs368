#include <iostream>
#include <string>
#include "ComplexNumber.h"

using namespace std;

/*
Here is the main method that tests the class.  It works great.
*/

int main () {

	ComplexNumber c1 = ComplexNumber(4.2,8.3);
	ComplexNumber c2 = ComplexNumber(3.1,-9.2);
	ComplexNumber temp = c1;

	cout << "Enter a complex number C1: "<<endl;
	cin >> c1;

	if (cin.fail() && !cin.bad()) {
		cin.clear();
		string s;
		getline(cin,s);
		cout << "invalid input" << endl;
		return -1;
	}

	cout << "Enter a complex number C2: "<<endl;
	cin >> c2;

	if (cin.fail() && !cin.bad()) {
		cin.clear();
		string s;
		getline(cin,s);
		cout << "invalid input" << endl;
		return -1;
	}

	cout << "For C1 = " << c1 << " and C2 = " << c2 << " :" << endl;

	cout << "C1 + C2 = " << (c1 + c2) << endl;

	cout << "C1 - C2 = " << (c1 - c2) << endl;

	cout << "C1 * C2 = " << (c1 * c2) << endl;

	if(c1==c2)
		cout << "C1 == C2 is true" << endl;
	else
		cout << "C1 == C2 is false" << endl;

	if(c1!=c2)
		cout << "C1 != C2 is true" << endl;
	else
		cout << "C1 != C2 is false" << endl;

	temp = c1;
	cout << "After C1 += C2, C1 = " << (temp += c2) << endl;

	temp = c1;
	cout << "After C1 -= C2, C1 = " << (temp -= c2) << endl;

	temp = c1;
	cout << "After C1 *= C2, C1 = " << (temp *= c2) << endl;

	return 0;
}
