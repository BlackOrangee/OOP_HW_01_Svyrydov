#pragma once
#include <iostream>
using namespace std;

class Fractions
{
private:
	int number;                  // Represents the whole number part of the fraction
	short afterpoint_number;     // Represents the decimal part of the fraction
	bool positive;               // Represents the sign of the fraction (true for positive, false for negative)

	// Helper function to convert a fraction into an integer
	void make_integer(int c_number, short c_afterpoint_number, int& res);

	// Helper function to convert a fraction into an integer
	void make_integer_helper(Fractions& num, Fractions& result, int& res);

	// Helper function to convert an integer into a fraction
	void make_fraction(int& c_number, short& c_afterpoint_number, bool& c_positive);

	// Helper function to adjust the fraction after multiplication
	void make_fraction_after_multiply(int& c_number, short& c_afterpoint_number);

public:
	// Sets the fraction with the given number and afterpoint_number
	void set(int in_number, short in_afterpoint_number);

	// Gets the components of the fraction (number, afterpoint_number, positive)
	void get(int& out_number, short& out_afterpoint_number, bool& out_positive);

	// Performs addition of two fractions
	void plus(Fractions num, Fractions& result);

	// Performs subtraction of two fractions
	void minus(Fractions num, Fractions& result);

	// Performs multiplication of two fractions
	void multiply(Fractions num, Fractions& result);

	// Performs comparison of two fractions
	void comparison(Fractions num1, Fractions& num2);
};


