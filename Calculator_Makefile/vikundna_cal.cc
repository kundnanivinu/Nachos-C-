
// Main File for Vinu Kundnani
// This file contains the main() program and includes the vikundna_op.h header file

# include<vikundna_op.h>
# include<iostream>

using namespace std;

int main()
{
	char option, oper;
	char input[10];
	float operand1, operand2;	
	float result;
	
	cout << "\t\t\tCPS 400- Assignment 1\n";
	cout << "\t\tBasic Calculator- Demonstrating Pass by Value\n";
	cout << "\t\tNet ID: vikundna \t\t SUID: 470316255";
	do
	{
		oper= validateOperator();		// get the valid operator(only +,-,/,*,%)

		cout << "\n\nEnter the first operand:\t\t";
		cin >> input;
		operand1 = validateInput(input);	// get the valid operands (only numbers and decimals)
	
		cout << "Enter the second operand:\t\t";
		cin >> input;
		operand2 = validateInput(input);

		switch(oper)
		{
			case '+':
				result= add(operand1, operand2);
				cout << "\nThe result of calculation is( "<< operand1 << " + " << operand2 << "):\t" << result;
				break;
			case '-':
				result= subtract(operand1, operand2);
				cout << "\nThe result of calculation is( "<< operand1 << " - " << operand2 << "):\t" << result;
				break;
			case '*':
				result= multiply(operand1, operand2);
				cout << "\nThe result of calculation is( "<< operand1 << " * " << operand2 << "):\t" << result;
				break;
			case '/':
				if (0 == int(operand2))	// check for 0 as a denominator
					cout << "Divide by zero error! Operand2 (Denominator) cannot be zero";
				else
				{
					result= divide(operand1, operand2);
					cout << "\nThe result of calculation is( "<< operand1 << " / " << operand2 << "):\t" << result;
				}	
				break;
			case '%':
				result= mod(operand1, operand2);
				cout << "\nThe result of calculation is( "<< (int)operand1 << " % " << (int)operand2 << "):\t" << result;
				break;
		}

	
		cout << "\n\n Do you want to do more calculation? (Y/N):\t\t";
		cin >> option;
	}while('y' == option || 'Y' == option);	// coding convention to follow, constants on left side while comparison and variables on right

	return 0;
}
