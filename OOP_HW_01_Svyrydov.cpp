// Class Fractional number with a sign (Fractions).
// The number must be represented by two fields :
// the integer part is a signed integer, 
// the fractional part is an unsigned short integer.
// Implement arithmetic operations of:
// addition, subtraction and comparison operations.
//

#include <iostream>
#include "Fractions.h"
using namespace std;

// This function takes user input for a fraction.
void input(Fractions& num)
{
	int number;
	short ap_number;
	cout << "\n\n\tEnter number, and after point number: ";
	cin >> number >> ap_number;
	num.set(number, ap_number); // Set the fraction based on the user input
}

// This function prints a fraction in the format "number.afterpoint_number".
void Print(Fractions& num)
{
	int number;
	short afterpoint_number;
	bool positive;
	num.get(number, afterpoint_number, positive); // Get the components of the fraction

	if (number == 0 && !positive)
	{
		cout << "-"; // Print a negative sign if the fraction is negative
	}

	if (afterpoint_number < 10)
	{
		cout << number << ".0" << afterpoint_number; // Print the fraction with a leading zero for afterpoint_number less than 10
	}
	else
	{
		cout << number << "." << afterpoint_number; // Print the fraction as is
	}
}

// This function performs addition of two fractions.
void Add(Fractions& num1, Fractions& num2, Fractions& result)
{
	input(num1); // Take user input for the first fraction
	input(num2); // Take user input for the second fraction
	num1.plus(num2, result); // Perform addition of the two fractions

	cout << "\n\t";
	Print(num1); cout << " + "; Print(num2); cout << " = ";
	Print(result); // Print the result of the addition
}

// This function performs subtraction of two fractions.
void Subtract(Fractions& num1, Fractions& num2, Fractions& result)
{
	input(num1); // Take user input for the first fraction
	input(num2); // Take user input for the second fraction
	num1.minus(num2, result); // Perform subtraction of the two fractions

	cout << "\n\t";
	Print(num1); cout << " - "; Print(num2); cout << " = ";
	Print(result); // Print the result of the subtraction
}

// This function performs multiplication of two fractions.
void Multiply(Fractions& num1, Fractions& num2, Fractions& result)
{
	input(num1); // Take user input for the first fraction
	input(num2); // Take user input for the second fraction
	num1.multiply(num2, result); // Perform multiplication of the two fractions

	cout << "\n\t";
	Print(num1); cout << " * "; Print(num2); cout << " = ";
	Print(result); // Print the result of the multiplication
}

// This function performs comparison of two fractions.
void Comparison(Fractions& num1, Fractions& num2)
{
	short result = 0;
	input(num1); // Take user input for the first fraction
	input(num2); // Take user input for the second fraction
	num1.comparison(num2, result); // Compare the two fractions

	if (result > 0)
	{
		cout << "\n\tThe number ";	Print(num1);
		cout << " is bigger then ";	Print(num2);
	}
	else if (result < 0)
	{
		cout << "\n\tThe number ";	Print(num2);
		cout << " is bigger then ";	Print(num1);
	}
	else
	{
		cout << "\n\tThe numbers are the same\n\t";
	}
}

// This function displays a menu and performs operations on fractions based on the user's choice.
void menu(Fractions& num1, Fractions& num2, Fractions& result)
{
	int choice = 0;
	cout << "\n\n\t1 -- Add two numbers\n\t2 -- Subtract from number\n\t3 -- Multiply two numbers\n\t4 -- Comparison two numbers\n\t";
	cin >> choice;

	switch (choice)
	{
	case 1:
		Add(num1, num2, result); // Call the function to add two fractions
		break;
	case 2:
		Subtract(num1, num2, result); // Call the function to subtract one fraction from another
		break;
	case 3:
		Multiply(num1, num2, result); // Call the function to multiply two fractions
		break;
	case 4:
		Comparison(num1, num2); // Call the function to comparison two fractions
	default:
		cerr << "\n\n\tWrong input"; // Print an error message for invalid input
		break;
	}
}

int main()
{
	Fractions num1;
	Fractions num2;
	Fractions result;

	do
	{
		menu(num1, num2, result); // Call the menu function to perform operations on fractions
	} while (true); // Repeat the menu indefinitely
}
