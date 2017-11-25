/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #4
 *	Tanya Wanwatanakool
 */

//LinkedListA4 Implementation
#include "LinkedListA4.h"
#include <iostream>
using namespace std;

//Define Constructor
LinkedListA4::LinkedListA4()
{ 
	head = nullptr;
}

//Define Destructor
LinkedListA4::~LinkedListA4()
{
	ListNode *nodePtr;	//To traverse the list
	ListNode *nextNode;	//To point to the next node

	//Position nodePtr at the head of the list
	nodePtr = head;

	//While nodePTr is not at the end of the list
	while (nodePtr != nullptr)
	{
		//Save a pointer to the next node
		nextNode = nodePtr->next;

		//Delete the current node
		delete nodePtr;

		//Position nodePtr at the next node
		nodePtr = nextNode;
	}
}

//Append Node at the end of the list
void LinkedListA4::appendNode(int num)
{
	ListNode *newNode; // To point to a new node
	ListNode *nodePtr; // To move through the list

	// Allocate a new node and store num there
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	// If there are no nodes in the list make newNode the first node
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at end
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Find the last node in the list
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

//Insert Node at the beginning of the list
void LinkedListA4::insertNode(int num)
{
	ListNode *newNode;	// A new node
	ListNode *nodePtr;	// To traverse the list

	// Allocate a new node and store num there
	newNode = new ListNode;
	newNode->value = num;

	newNode->next = head;
	head = newNode;
}

void LinkedListA4::deleteNode(int index)
{
	ListNode *nodePtr;		//To traverse the list

	//If the list is empty, do nothing
	if (!head)
	{
		cout << "Empty list.\n";
		return;
	}

	if(head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}

	//Determine if first node is value
	if(index == 0)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	//Last index
	else if (index == 1)
	{
		//Initilaize nodePtr to head of list
		nodePtr = head;

		while(nodePtr->next && nodePtr->next->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		delete nodePtr->next;
		nodePtr->next = nullptr;
	}
}

//Helper Method, print elements in list
void LinkedListA4::printAllElements() const
{
	ListNode *nodePtr;	//To traverse the list

	//If list is empty
	if (!head)
	{
		cout << "Empty List.\n";
	}
	else
	{
		nodePtr = head;		//Initiliaze nodePtr to head of list

		//Print list of elements
		cout << " [ ";
		while (nodePtr != nullptr) 
		{
			cout << nodePtr->value << " ";
			nodePtr = nodePtr->next;
		}
		cout << "]\n\n";
	}
}

