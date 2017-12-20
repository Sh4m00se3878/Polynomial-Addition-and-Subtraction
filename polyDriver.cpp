#include <iostream>
#include "Poly.h"
using namespace std;


int main(){

	//Instantiating a polynomial object.
	polynomial p1(2), p2, p3;

	p1.assign_coef(-2 , 2);
	p1.assign_coef(5, 6);
	p1.assign_coef(-5, 8);

	cout << p1 << endl;

	p2.assign_coef(-2, 2);
	p2.assign_coef(5, 8);

	cout << p2 << endl;

	p3 = p1 - p2;

	cout << p3 << endl;

	system("pause");
	return 0;
}