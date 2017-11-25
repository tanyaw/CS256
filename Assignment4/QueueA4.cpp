/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #4
 *	Tanya Wanwatanakool
 */

//Queue Implementation using LinkedListA4
#include "LinkedListA4.h"
#include <iostream>
using namespace std;

class QueueA4: public LinkedListA4
{
	private:
		ListNode *front; 	//Front of Queue Linked List
		ListNode *rear;		//End of Queue Linked list
		int queueSize;

	public:
		//Append node at end of Queue
		void enqueue(int x)
		{
			if(isFull())
				cout << "Cannot push, Queue is full.\n";
			else
			{
				appendNode(x);
				queueSize++;
			}
		}

		//Remove node from beginning of Queue
		void dequeue()
		{
			if (isEmpty())
				cout << "Cannot delete, Queue is empty.\n";
			else
			{
				deleteNode(0);
				queueSize--;
			}
		}

		//Checks if Queue is full
		bool isFull() const
		{
			if(queueSize == 100)
				return true;
			else
				return false;
		}

		//Checks if Queue is empty
		bool isEmpty() const
		{
			if(queueSize == 0)
				return true;
			else
				return false;
		}

		//Deletes pointer to Queue
		void clear() 
		{
			delete front;
		}
};

