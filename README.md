# Polynomial Addition and Subtraction
-Allows a user to create and manipulate a Polynomial object. 
-Polynomial Driver and Driver2 are for testing purposes.
-We were given the header file which consisted of the following descriptions for the functions:

// FILE: poly.h
// CLASS PROVIDED:
//   class polynomial 
//     A polynomial has one variable x, real number coefficients, and
//     non-negative integer exponents. Such a polynomial can be viewed
//     as having the form:
//       A[n]*x^n + A[n-1]*x^(n-1) + ... A[2]*x^2 + A[1]*x + A[0]
//     where the A[n] are the real number coefficients and x^i represents
//     the variable x raised to the i power. The coefficient A[0] is
//     called the "constant" or "zeroth" term of the polynomial.

//   This version works by storing the coefficients in
//      a dynamic array. The coefficient for the x^k term is stored
//      in location [k] of the dynamic array. When a new term is
//      added beyond the current size of the array, then the
//      dynamic array is replaced by a new, larger array.


// MEMBER CONSTANTS
//   const size_t DEFAULT_CAPACITY
//     The size of the initial array to store the coefficients.
//
// DEFAULT CONSTRUCTOR for the polynomial class
//     POSTCONDITION: This polynomial has been create with all zero
//     coefficients, the size is set to the DEFAULT_CAPACITY, and the 
//     current degree is set to 0.
// INITIALIZATION CONSTRUCTOR for the polynomial class
//     POSTCONDITION: This polynomial has been create with all zero
//     coefficients, the size is set to the init_size parameter passed to the function, 
//     and the current degree is set to 0.

// MODIFICATION MEMBER FUNCTIONS for the polynomial class
//   void assign_coef(double coefficient, size_t exponent)
//     POSTCONDITION: Sets the coefficient for the specified exponent.
//
//   void reserve(size_t number)
//     POSTCONDITION: The size of the array for coefficients has been changed 
//     to the requested number (but not less that the size needed to store the
//     current non-zero coefficients). In effect, this guarantees that member
//     functions will not need to allocate new memory for exponents through

// CONSTANT MEMBER FUNCTIONS for the polynomial class
//   double coefficient(size_t exponent) const
//     POSTCONDITION: Returns coefficient at specified exponent of this
//     polynomial.
//
//   double getsize( ) const
//     POSTCONDITION: Returns size of the coef array
//
//   size_t degree( ) const
//     POSTCONDITION: The function returns the value of the largest exponent
//     with a non-zero coefficient.
//     If all coefficients are zero, then the function returns zero.
//
//   double eval(double x) const;
//		POSTCONDITION:  Evaluates a polynomial with a given value of x. 
//      For example, given the polynomial 3x^2-7x and a value of x to be 2,
//      the result would be 3 * (2^2) - 7 * (2^1) = 3 * 4 - 7 * 2 = 12 - 14 = -2

// NON-MEMBER BINARY OPERATORS for the polynomial Class
//   polynomial operator -(const polynomial& p1, const polynomial& p2)
//     POSTCONDITION: return-value is a polynomial with each coefficient
//     equal to the difference of the coefficients of p1 & p2 for any given
//     exponent.
//
//   polynomial operator +(const polynomial& p1, const polynomial& p2)
//     POSTCONDITION: return-value is a polynomial with each coefficient
//     equal to the sum of the coefficients of p1 & p2 for any given
//     exponent.
//
// NON-MEMBER OUTPUT FUNCTIONS for the polynomial Class
//   ostream& operator << (ostream& out, const polynomial& p)
//     POSTCONDITION: The polynomial has been printed to ostream out, which,
//     in turn, has been returned to the calling function.
//
// DYNAMIC MEMORY 
//   Since this class uses dynamic memory, the copy constructor and assignment
//   operator are written, and there is a destructor implemented. 