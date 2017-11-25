/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #4
 *	Tanya Wanwatanakool
 */

// Header file for LinkedListA4

#ifndef LINKEDLISTA4_H
#define LINKEDLISTA4_H

class LinkedListA4
{
	public:
		// Declare a structure for the list
		struct ListNode
		{
			int value; // The value in this node
			struct ListNode *next; // To point to the next node
		};

		ListNode *head; // List head pointer

		// Constructor
		LinkedListA4();

		// Destructor
		~LinkedListA4();

		// Linked list operations
		void appendNode(int);
		void insertNode(int);
		void deleteNode(int);
		void printAllElements() const;
};
#endif

