/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #4
 *	Tanya Wanwatanakool
 */

//Stack Implementation using LinkedListA4
#include "LinkedListA4.h"
#include <iostream>
using namespace std;

class StackA4 : public LinkedListA4
{
	private:
		int stackSize;	//Track size of Stack
		ListNode *top;

	public:
		//Insert element to Stack
		void push(int x)
		{
			if(isFull())
				cout << "Cannot push, Stack is full.\n";
			else
			{
				insertNode(x);
				stackSize++;
			}
		}

		//Remove element from Stack
		void pop()
		{
			if(isEmpty())
				cout << "Cannot delete, Stack is empty.\n";
			else
			{
				deleteNode(1);
				stackSize--;
			}
		}

		//Checks if Stack is full
		bool isFull() const
		{
			if(stackSize == 100)
				return true;
			else
				return false;
		}

		//Checks if Stack is empty
		bool isEmpty() const
		{
			if(stackSize == 0)
				return true;
			else
				return false;
		}
};

