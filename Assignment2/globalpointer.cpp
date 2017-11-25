/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #2
 *	
 *	Tanya Wanwatanakool
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

//Define Constants
#define ARR_SIZE 100

//Define Global Variables
int size = 0;
int* p;

//Define Function Prototypes
void push(int i);
int pop();
bool check_full();
bool check_empty();


int main() 
{
	//1. Initalize stack and pointer
	int stack[ARR_SIZE];
	p = stack;

	//2. Prompt User input
	cout << "---Welcome to Base Converter---" << endl;
	int num;
	cout << "Please enter a number: ";
	cin >> num;

	int base;
	cout << "Base Conversions\n 1. Binary\n 2. Octal\n 3. Hexademical\nPlease select a menu option: ";
	cin >> base;

	//3. Map User's selection to Base value
	if(base == 1) {
		base = 2;
	} else if(base == 2) {
		base = 8;
	} else {
		base = 16;
	}

	//4. Perform Base Conversion calculations
	int quotient = num;
	int remainder;
	while(quotient != 0) 
	{
		remainder = quotient % base;
		push(remainder);
		quotient = quotient / base;
	}

	//5. Print Base Conversion result
	cout << "The conversion is: ";
	while(check_empty() == false) 
	{
		for(int i=0; i < size; i++) 
		{
			int val = pop();

			//Reformat result for hexadecimal output
			if(base == 16) {
				if(val == 10) {
					cout << "A";
				} else if(val == 11) {
					cout << "B";
				} else if(val == 12) {
					cout << "C";
				} else if(val == 13) {
					cout << "D";
				} else if(val == 14) {
					cout << "E";
				} else if(val == 15) {
					cout << "F";
				} else {
					cout << val;
				}
			} 
			//Print result directly to console
			else {
				cout << val;
			}
		}
	}
	cout << endl;

	return 0;
}

//Stack method inserts an element to the "top" of the stack
void push(int i) 
{
	//Case 1: First push to stack
	if(check_empty()) {
		*p = i;
	} 
	//Case 2: Increment pointer when pushing to stack
	else if (check_full() == false) {
		p++;
		*p = i;
	} 
	//Error: Stack is full
	else {
		cout << "Error: You tried pushing on a full stack. Exiting...";
		exit(0);
	}
	size++;
	return;
}

//Stack method deletes the first element from the stack
int pop() 
{
	if(check_empty() == false) {
		int cur_element = *p;
		p--;
		size--;
		return cur_element;
	} 
	//Error: Stack is empty
	else {
		cout << "Error: You tried popping from an empty stack. Exiting...";
		exit(0);
	}
}

//Stack method checks if the stack is full
bool check_full() 
{
	if(size == 100) {
		return true;
	}
	return false;
}

//Stack method checks if the stack is empty
bool check_empty() 
{
	if(size == 0) {
		return true;
	}
	return false;
}