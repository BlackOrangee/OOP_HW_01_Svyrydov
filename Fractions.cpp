#include "Fractions.h"


void Fractions::make_integer(int c_number, short c_afterpoint_number, int& result)
{
	result = c_number * 100; // Convert the whole number part to the equivalent fraction value
	if (c_number < 0 && c_afterpoint_number > 0)
	{
		c_afterpoint_number *= -1; // Adjust the sign of the decimal part if necessary
	}
	result += c_afterpoint_number; // Combine the whole number and decimal parts to form the final fraction value
}

void Fractions::make_integer_helper(Fractions num, Fractions& result, int& res)
{
	make_integer(number, afterpoint_number, result.number); // Convert the current fraction to an integer
	make_integer(num.number, num.afterpoint_number, res); // Convert the input fraction to an integer
}

void Fractions::make_fraction(int& c_number, short& c_afterpoint_number, bool& c_positive)
{
	c_afterpoint_number = c_number % 100; // Extract the decimal part from the number
	c_number /= 100; // Extract the whole number part from the number

	if (c_number == 0 && c_afterpoint_number < 0)
	{
		c_positive = false; // Set the sign of the fraction to negative if the whole number part is 0 and the decimal part is negative
	}

	if (c_afterpoint_number < 0)
	{
		c_afterpoint_number *= -1; // Adjust the sign of the decimal part if necessary
	}
}

void Fractions::make_fraction_after_multiply(int& c_number, short& c_afterpoint_number)
{
	c_number /= 100; // Remove the decimal part from the number
	c_afterpoint_number = c_number % 100; // Extract the new decimal part from the number
	c_number /= 100; // Extract the new whole number part from the number
}

void Fractions::set(int in_number, short in_afterpoint_number)
{
	number = in_number; // Set the whole number part of the fraction
	afterpoint_number = in_afterpoint_number; // Set the decimal part of the fraction
}

void Fractions::get(int& out_number, short& out_afterpoint_number, bool& out_positive)
{
	out_number = number; // Get the whole number part of the fraction
	out_afterpoint_number = afterpoint_number; // Get the decimal part of the fraction
	out_positive = positive; // Get the sign of the fraction
}

void Fractions::plus(Fractions num, Fractions& result)
{
	int res = 0;

	make_integer_helper(num, result, res);

	result.number += res; // Add the integer value of the input fraction to the result

	make_fraction(result.number, result.afterpoint_number, result.positive); // Convert the result back to a fraction
}

void Fractions::minus(Fractions num, Fractions& result)
{
	int res = 0;

	make_integer_helper(num, result, res);

	result.number -= res; // Subtract the integer value of the input fraction from the result

	make_fraction(result.number, result.afterpoint_number, result.positive); // Convert the result back to a fraction
}

void Fractions::multiply(Fractions num, Fractions& result)
{
	int res = 0;

	make_integer_helper(num, result, res);

	result.number *= res; // Multiply the integer value of the input fraction with the result

	make_fraction_after_multiply(result.number, result.afterpoint_number); // Adjust the result fraction after multiplication
}

void Fractions::comparison(Fractions num, short& result)
{
	int number1 = 0;
	int number2 = 0;
	make_integer(number, afterpoint_number, number1); // Convert the current fraction to an integer
	make_integer(num.number, num.afterpoint_number, number2); // Convert the input fraction to an integer

	if (number1 > number2)
	{
		result = 1; // Set the result to 1 if the current fraction is greater than the input fraction
	}
	else if (number1 < number2)
	{
		result = -1; // Set the result to -1 if the current fraction is less than the input fraction
	}
	else
	{
		result = 0; // Set the result to 0 if the current fraction is equal to the input fraction
	}
}