#include <iostream>  
#include "poly.h"
#include <cassert>

using namespace std;

polynomial::polynomial(){ // Default Constructor
	size = DEFAULT_CAPACITY;
	current_degree = 0;
	coef = new double[size];

	for (size_t i = 0; i < size; i++){
		coef[i] = 0;
	}
}

polynomial::polynomial(size_t init_size){ // Constructor with Parameters
	size = init_size;
	current_degree = 0;
	coef = new double[init_size];

	for (size_t i = 0; i < size; i++){
		coef[i] = 0;
	}
}

polynomial::polynomial(const polynomial& source) { // Copy Constructor
	coef = new double[source.size];
	size = source.size;
	current_degree = source.current_degree;

	for (size_t i = 0; i <= size; i++) {
		coef[i] = source.coef[i];
	}
}

polynomial::~polynomial(){
	delete[] coef;
}

void polynomial::operator =(const polynomial& source){

	double * new_coef;
	if (this == &source)
		return;

	if (size != source.size) {
		new_coef = new double[source.size];
		delete[] coef;
		coef = new_coef;
		size = source.size;
	}

	current_degree = source.current_degree;

	for (size_t i = 0; i < size; i++) {
		coef[i] = source.coef[i];
	}
}

void polynomial::assign_coef(double co, size_t exp){ // Assigns a coefficient to an exponent 

	if (exp >= size) {
		reserve(exp);
	}

	if (exp > current_degree){
		current_degree = exp;
	}
	
	coef[exp] = co;
}

void polynomial::reserve(size_t number){ // Changes the size of the coefficient array (

	number += number * .10; // increases size by 10 percent

	double *new_array;
	new_array = new double[number];

	if (number < size)
		number = size;  // Don't allocate less than what is needed

	for (size_t i = 0; i < number; i++) { // add zeroes to all other unassigned degrees
		new_array[i] = 0;					// first make all values 0
	}

	for (size_t i = 0; i < getSize(); i++){ // copy old array elements into new array
		new_array[i] = coef[i];				// copy elements into new array
	}

	delete[] coef;		// free memory from coef
	coef = new_array;	// coef now points to new_array
	size = number;
}

void polynomial::setCurrent_degree(int init_degree){ // Sets the current degree of the polynomial
		current_degree = init_degree;
}


void polynomial::setSize(size_t init_size){ // Sets the size of the polynomial
	size = init_size;
}

double polynomial::eval(double x) const{ // evaluates the polynomial
	double sol = 0;

	for (size_t i = 0; i < size; i++){
		sol += (coefficient(i) * pow(x, i));
	}
	return sol;
}

ostream& operator << (ostream& cout, const polynomial& r) { // displays the polynomial

	for (size_t i = r.getSize() - 1; i >= 0; i--) {
		double co = r.coefficient(i);

		if (i > r.getSize()) { // Breaks 
			break;
		}

		if (r.degree() == i){ // Check to see if coefficient is the first in the polynomial (first in sequence) (CHANGE DIS)
			if (co != 0) { // Checks if coefficent is not equal to zero.
				if (co > 0) {	// Checks if coefficient is greater than zero.
					if (i == 0) { // Checks if exponent or beginning of array is equal to zero.
						cout << " " << co;
					}
					else {
						if (i == 1) {
							cout << " " << co << "x";
						}
						else {
							cout << " "  << co << "x^" << i;
						}
					}
				}
				else if (co < 0){
					if (i == 0) {
						cout << "-" << co*(-1);
					}
					else {
						if (i == 1) {
							cout << "-" << co*(-1) << "x";
						}
						else {
							cout << "-" << co*(-1) << "x^" << i;
						}
					}
				}
			}
		}
		else if (r.degree() != i){
			if (co != 0) { // Checks if coefficent is not equal to zero.
				if (co > 0) {	// Checks if coefficient is greater than zero.
					if (i == 0) { // Checks if exponent or beginning of array is equal to zero.
						cout << " + " << co;
					}
					else {
						if (i == 1) {
							cout << " + " << co << "x";
						}
						else {
							cout << " + " << co << "x^" << i;
						}
					}
				}
				else{
					if (i == 0) {
						cout << " - " << co*(-1);
					}
					else {
						if (i == 1) {
							cout << " - " << co*(-1) << "x";
						}
						else {
							cout << " - " << co*(-1) << "x^" << i;
						}
					}
				}
			}
		}
	}

	return cout;
}

polynomial operator +(const polynomial& l, const polynomial& r) { // adds two polynomials together
	polynomial p;

	double *new_Rarray;
	new_Rarray = new double[l.getSize()];	// used for left polynomial's size

	double *new_Larray;
	new_Larray = new double[r.getSize()];	// used for right polynomial's size

	if (l.getSize() >= r.getSize()){ // make the l and r same size

		for (size_t i = 0; i < l.getSize(); i++) { // add zeroes to all unassigned degrees
			new_Rarray[i] = 0;					// make other values 0
		}

		for (size_t i = 0; i < r.getSize(); i++) { // copy old array elements into new array
			new_Rarray[i] = r.coefficient(i);	// copy elements into new array
		}

		for (size_t i = 0; i < l.getSize(); i++) { // Polynomial addition
			if ((l.coefficient(i) != 0) || (new_Rarray[i] != 0)) {
				if ((new_Rarray[i] + l.coefficient(i)) != 0){
					p.assign_coef(new_Rarray[i] + l.coefficient(i), i);
				}
				else {}
			}
		} 
		return p;
	}
		
	else {
		for (size_t i = 0; i < r.getSize(); i++) { // add zeroes to all other unassigned degrees
			new_Larray[i] = 0;					// make other values 0
		}

		for (size_t i = 0; i < l.getSize(); i++) { // copy old array elements into new array
			new_Larray[i] = l.coefficient(i);	// copy elements into new array
		}

		for (size_t i = 0; i < r.getSize(); i++) { // Polynomial addition
			if ((r.coefficient(i) != 0) || (new_Larray[i] != 0)) {
				if ((new_Rarray[i] + l.coefficient(i)) != 0){
					p.assign_coef(new_Larray[i] + r.coefficient(i), i);
				}
				else {}
			} 
		}
		return p;
	}
}

polynomial operator -(const polynomial& l, const polynomial& r) {
	polynomial p;

	double *new_Rarray;
	new_Rarray = new double[l.getSize()];	// used for left polynomial's size

	double *new_Larray;
	new_Larray = new double[r.getSize()];	// used for right polynomial's size

	if (l.getSize() >= r.getSize()){ // make the l and r same size

		for (size_t i = 0; i < l.getSize(); i++) { // add zeroes to all unassigned degrees
			new_Rarray[i] = 0;					// make other values 0
		}

		for (size_t i = 0; i < r.getSize(); i++) { // copy old array elements into new array
			new_Rarray[i] = r.coefficient(i);	// copy elements into new array
		}

		for (size_t i = 0; i < l.getSize(); i++) { // Polynomial subtraction
			if ((l.coefficient(i) != 0) || (new_Rarray[i] != 0)) {
				if ((l.coefficient(i)) - new_Rarray[i] != 0){
					p.assign_coef(l.coefficient(i) - new_Rarray[i], i);
				}
				else {}
			}
		}
		return p;
	}

	else {
		for (size_t i = 0; i < r.getSize(); i++) { // add zeroes to all other unassigned degrees
			new_Larray[i] = 0;					// make other values 0
		}

		for (size_t i = 0; i < l.getSize(); i++) { // copy old array elements into new array
			new_Larray[i] = l.coefficient(i);	// copy elements into new array
		}

		for (size_t i = 0; i < r.getSize(); i++) { // Polynomial subtraction
			if ((r.coefficient(i) != 0) || (new_Larray[i] != 0)) {
				if ((new_Larray[i] - r.coefficient(i)) != 0){
					p.assign_coef(new_Larray[i] - r.coefficient(i), i);
				}
				else {}
			}
		}
		return p;
	}
}

