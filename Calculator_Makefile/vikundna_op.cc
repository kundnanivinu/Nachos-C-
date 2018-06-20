// Operations File for Vinu Kundnani
// This file contains the functions definitions from the vikundna_op.h file

# include<vikundna_op.h>		// Header file for declaration of below defined functions
# include<stdlib.h>			// To use the standard library for functions like atof()
# include<string.h>			// To use the string functions like strlen()
# include<iostream>

using namespace std;

float add(float number1, float number2)
{
	return number1 + number2;
}

float subtract (float number1, float number2)
{
	return number1 - number2;
}

float multiply (float number1, float number2)
{
	return number1 * number2;
}

float divide(float number1, float number2)
{
	return number1 / number2;
}

float mod(float number1, float number2)
{
	return (int)number1 % (int)number2;
}

float validateInput(char input[])
{
	size_t len= strlen(input);
	
	for(int i = 0; i < len; i++)
	{
		if(isdigit(input[i]) || '.' == (input[i]));
			
		else
		{
			cout << "\nInvalid input!!" << input[i] << "\nPlease re-enter the input:\t\t";
			cin >> input;
			validateInput(input);
			break;
		}
	}
	return atof(input);
}

char validateOperator()
{
	char oper;
	cout << "\n\nEnter your operator (+, -, *, / or %):\t";
	cin >> oper;

	if('+' != oper && '-' != oper && '*' != oper && '/' != oper && '%' != oper)
	{
		cout << "\nInvalid Operator!!" << oper;
		oper= validateOperator();
	}
	else
		return oper;
}
