#include <iostream>
#include "poly.h"

using namespace std;

void cctest(polynomial);

int main()
{
	polynomial P1, P2, P3;
	int howmany;
	double c, x, result;
	size_t e;

	cout << "Enter how many coeffiecients the polynomial : ";
	cin >> howmany;
	while (howmany > 0)
	{
		cout << "Enter coefficient : ";
		cin >> c;
		cout << "Enter exponent : ";
		cin >> e;
		P1.assign_coef(c, e);
		howmany--;
	}

	cout << "Enter how many coeffiecients the polynomial : ";
	cin >> howmany;
	while (howmany > 0)
	{
		cout << "Enter coefficient : ";
		cin >> c;
		cout << "Enter exponent : ";
		cin >> e;
		P2.assign_coef(c, e);
		howmany--;
	}

	cout << "The first polynomial is " << P1 << endl
		<< "The second polynomial is " << P2 << endl << endl;

	P3 = P2;
	cout << "Testing = operator ... " << endl
		<< "The second polynomial is " << P3 << endl << endl;

	cout << "Results of Addition : " << P1 + P2 << endl;
	cout << "Results of Subtraction : " << P1 - P2 << endl << endl;

	cout << "Testing Evaluate ..." << endl;
	cout << "  Enter value of x : ";
	cin >> x;
	result = P1.eval(x);
	cout << "  The result of P1 when x is " << x << " is " << result << endl << endl;

	cout << "Testing copy constructor..." << endl;
	cctest(P1);

	system("pause");
	return 0;
}

void cctest(polynomial P)
{
	cout << "  The first polynomial is " << P << endl << endl;
}