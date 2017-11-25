/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #3
 *	Tanya Wanwatanakool
 */

//Driver Class
#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
	//1. Prompt user to enter Polynomial
	cout << "---First Polynomial---" << endl;
	int pow;
	cout << "Enter degree of polynomial: ";
	cin >> pow;

	//Create polynomial object
	Polynomial p1 = Polynomial(pow);

	//Prompt user for coefficients
	int coeff;
	for(int i=0; i < (pow+1); i++)
	{
		cout << "Enter a coefficient value: ";
		cin >> coeff;
		p1.setCoefficient(i, coeff);
	}

	//Print polynomial function
	cout << "Polynomial1 = ";
	p1.print();


	//2. Prompt user to enter Polynomial 
	cout << endl << "---Second Polynomial---" << endl;
	int pow2;
	cout << "Enter degree of polynomial: ";
	cin >> pow2;

	//Create polynomial object
	Polynomial p2 = Polynomial(pow2);
	
	//Prompt user for coefficients
	int coeff2;
	for(int i=0; i < (pow2+1); i++)
	{
		cout << "Enter a coefficient value: ";
		cin >> coeff2;
		p2.setCoefficient(i, coeff2);
	}

	//Print polynomial function
	cout << "Polynomial2 = ";
	p2.print();


	//3. Perform Polynomial arthimetic calculations
	cout << endl << "---Polynomial Calculations---" << endl;
	Polynomial p3 = p1 + p2;
	cout << "1) Polynomial1 + Polynomial2 = ";
	p3.print();

	Polynomial p4 = p1 - p2;
	cout << "2) Polynomial1 - Polynomial2 = ";
	p4.print();

	cout << "3) Polynomial1 * Polynomial2 = ";
	Polynomial p5 = p1 * p2;
	p5.printMult();
	
	//Deallocate memory
	p1.~Polynomial();
	p2.~Polynomial();
	p3.~Polynomial();
	p4.~Polynomial();
	p5.~Polynomial();

	return 0;
}

