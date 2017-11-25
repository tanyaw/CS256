/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #3
 *	Tanya Wanwatanakool
 */

//Polynomial Class Implementation
#include "Polynomial.h"

//Define Polynomial overloaded constructor
Polynomial::Polynomial(int i)
{
	coeff = new int[(i+1)];
	variable = 'x';
	power = i;
	greater = false;
}

//Destructor
Polynomial::~Polynomial()
{
	if(coeff != nullptr)
		delete[] coeff;
	coeff = nullptr;
}

//Set indeterminate variable of polynomial
void Polynomial::setVariable(char c) 
{
	variable = c;
}

//Set power of polynomial function
void Polynomial::setPower(int pow)
{
	power = pow;
}

//Set coefficients of each term
void Polynomial::setCoefficient(int index, int coefficient)
{
	coeff[index] = coefficient;
}

//Set greater if polynomial degree is larger
void Polynomial::setGreater(bool b) 
{
	greater = b;
}

//Get variable of polynomial
char Polynomial::getVariable() const
{
	return variable;
}

//Get power of polynomial
int Polynomial::getPower() const
{
	return power;
}

//Get coefficient of term at specified position
int Polynomial::getCoefficient(int position) const
{
	return coeff[position];
}

bool Polynomial::getGreater() const
{
	return greater;
}

//Print Method to display polynomial function
void Polynomial::print() 
{
	int exp = power;
	for(int i=0; i < (power+1); i++)
	{
		cout << getCoefficient(i);
		
		if(exp > 0)
		{
			cout << variable << "^" << exp << " + ";
		} 
		exp -= 1;
	}
	cout << endl;
}

//Helper Method to determine degree of larger Polynomial
int Polynomial::getLargerPower(Polynomial &p1, Polynomial &p2)
{
	int pow;
	if(p1.power >= p2.power)
	{
		pow = p1.power;
		p1.greater = true;
	}
	else
	{
		pow = p2.power;
		p2.greater = true;
	}
	return pow;
}

//Helper Method to handle combingin like-terms of larger Polynomial
int Polynomial::mathCoefficients(Polynomial &p1, Polynomial &p2, Polynomial &p3)
{
	int exp1 = p1.power;
	int exp2 = p2.power;
	int offset = 0;
	while(exp1 != exp2)
	{
		if(p1.greater) 
		{
			p3.setCoefficient(offset, p1.getCoefficient(offset));
			exp1 -= 1;
		} 
		else 
		{
			p3.setCoefficient(offset, p2.getCoefficient(offset));
			exp2 -= 1;
		} 
		offset++;
	}
	return offset;
}

//Overloaded + operator to add two Polynomial objects
Polynomial operator+(Polynomial &p1, Polynomial &p2)
{
	//Create Polynomial object
	Polynomial p3 = Polynomial( p1.getLargerPower(p1, p2) );

	//Handle coefficients of larger terms
	int offset = p3.mathCoefficients(p1, p2, p3);

	//Add coefficients of polynomial w/ terms of same degree 
	for(int i=0; i < (p1.power + 1); i++)
	{
		if(p1.greater) 
		{
			p3.setCoefficient( (i+offset), p1.getCoefficient(i+offset) + p2.getCoefficient(i) );
		} 
		else 
		{
			p3.setCoefficient( (i+offset), p1.getCoefficient(i) + p2.getCoefficient(i+offset) );
		}
	}
	return p3;
}

//Print Method to display multiplied polynomial objects
void Polynomial::printMult()
{
	for(int i=(power+1); i >= 0; i--)
	{
		if(getCoefficient(i-1) != 0)
		{
			cout << getCoefficient(i-1);
			if((i-1) > 0)
			{
			cout << variable << "^" << (i-1) << " + ";
			} 
		}
	}
	cout << endl;
}

//Overloaded - operator to subtract two Polynomial objects
Polynomial operator-(Polynomial &p1, Polynomial &p2)
{
	//Create Polynomial object
	Polynomial p3 = Polynomial( p1.getLargerPower(p1, p2) );

	//Handle coefficients of larger terms
	int offset = p3.mathCoefficients(p1, p2, p3);

	//Subtract coefficients of polynomial w/ terms of same degree
	for(int i=0; i < (p1.power + 1); i++)
	{
		if(p1.greater) {
			p3.setCoefficient((i+offset), p1.getCoefficient(i+offset) - p2.getCoefficient(i));
		} 
		else 
		{
			p3.setCoefficient((i+offset), p1.getCoefficient(i) - p2.getCoefficient(i+offset));
		}
	}

	return p3;
}

//Overloaded * operator to multiply two Polynomial objects
Polynomial operator *(Polynomial &p1, Polynomial &p2)
{
	//Create Polynomial object and temp arrays
	int size = (p1.power+1) * (p2.power+1);
	Polynomial p3 = Polynomial(size);

	//Intiliaze coefficient array values to 0
	for(int i=0; i < size; i++)
	{
		p3.setCoefficient(i, 0);
	}

	//Multiply coefficients, Add exponents(indices)
	int exp1 = p1.power;
	int exp2 = p2.power;
	for(int i=0; i < (p1.power+1); i++) 
	{
		for(int j=0; j < (p2.power+1); j++) 
		{
			int val = p1.getCoefficient(i) * p2.getCoefficient(j);
			
			if(p3.getCoefficient(exp1+exp2) == 0)
			{
				p3.setCoefficient((exp1+exp2), val);
			} 
			else
			{
				p3.setCoefficient( (exp1+exp2), (p3.getCoefficient(exp1+exp2) + val) );
			}
			exp2--;		//Decrement exponent value of Polynomial2
		}
		
		exp1--;		//Decrement exponent value of Polynomial1
		exp2 = p2.power;	//Reset exponent value of Polynomial2
	}

	return p3;
}

