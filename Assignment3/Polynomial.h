/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #3
 *	Tanya Wanwatanakool
 */

//Polynomial Class Declaration
#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
using namespace std;

class Polynomial
{
	private:
		char variable;	//indeterminate character
		int power;		//Degree of polynomial function
		int *coeff;		//Coefficient integer array
		bool greater;	//True for polynomial with larger power

	public:
		Polynomial(int);	//Constructor
		~Polynomial();		//Destructor

		//Setters and Getters
		void setVariable(char);
		void setPower(int);
		void setCoefficient(int, int);
		void setGreater(bool);
		char getVariable() const;
		int getPower() const;
		int getCoefficient(int) const;
		bool getGreater() const;

		//Helper Methods
		void print();
		void printMult();
		int getLargerPower(Polynomial  &p1, Polynomial &p2);
		int mathCoefficients(Polynomial &p1, Polynomial &p2, Polynomial &p3);

		//Overloaded arithmetic operators +, -, *
		friend Polynomial operator+(Polynomial &p1, Polynomial &p2);
		friend Polynomial operator-(Polynomial &p1, Polynomial &p2);
		friend Polynomial operator*(Polynomial &p1, Polynomial &p2);


};
#endif

