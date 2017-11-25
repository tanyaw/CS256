/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #4
 *	Tanya Wanwatanakool
 */

#include <iostream>
#include "StackA4.cpp"
#include "QueueA4.cpp"
using namespace std;

//Function Prototypes
int menu();
void runLinkedList();
void runStack();
void runQueue();

//Global Variables
int element;
int menuOption;
string userInput;
bool run = true;

int main()
{
	cout << "--- CS256 Assignment #4 ---\n";
	cout << "1. Linked List\n";
	runLinkedList();

	cout << "2. Stack\n";
	runStack();

	cout <<"3. Queue\n";
	runQueue();

	return 0;
}

//Hepler Method, Prompt user with menu options
int menu() 
{
	int userInput;
	cout << "***** MENU *****\n";
	cout << "1. Enter a value?\n2. Delete a value?\n3. Exit.\n";
	cout << "Enter a menu option: ";
	cin >> userInput;

	return userInput;
}

void runQueue()
{
	QueueA4 queue;
	run = true;

	do
	{
		menuOption = menu();

		//Insert value to Queue
		if (menuOption == 1) {
			cout << "Enter a value: ";
			cin >> element;

			queue.enqueue(element);
		}
		//Delete values from Queue
		else if (menuOption == 2)
		{	
			queue.dequeue();
		} 
		//Exit while-loop
		else if (menuOption == 3)
		{
			run = false;
		}	
		else
		{
			cout << "Invalid option";
		}

		//Print current list of elements
		cout << "Current elements in Queue: ";
		queue.printAllElements();

	} while(run);

	//Print final list of elements
	cout << "FINAL VALUES OF QUEUE: ";
	queue.printAllElements();
	cout << "-----------------------------------------\n\n";
}

void runStack()
{
	StackA4 stack;
	run = true;
	
	do
	{
		menuOption = menu();

		//Insert value to Stack
		if (menuOption == 1) {
			cout << "Enter a value: ";
			cin >> element;
			
			stack.push(element);
		}
		//Delete values from Stack
		else if (menuOption == 2)
		{	
			stack.pop();
		} 
		//Exit while-loop
		else if (menuOption == 3)
		{
			run = false;
		}	
		else
		{
			cout << "Invalid option";
		}

		//Print current list of elements
		cout << "Current elements in Stack: ";
		stack.printAllElements();

	} while(run);

	//Print final list of elements
	cout << "FINAL VALUES OF STACK: ";
	stack.printAllElements();
	cout << "-----------------------------------------\n\n";
}

void runLinkedList()
{
	LinkedListA4 list;

	do
	{
		menuOption = menu();

		//Insert values to list
		if (menuOption == 1) {
			cout << "Enter a value: ";
			cin >> element;
			
			cout << "Insert at the (1)start or (2)end of list?(1/2) ";
			cin >> userInput;
			if (userInput.compare("1") == 0) 
			{
				list.insertNode(element);
			}
			else if (userInput.compare("2") == 0) 
			{
				list.appendNode(element);
			} 
			else 
			{
				cout << "Invalid option.";
			}
		}
		//Delete values from list
		else if (menuOption == 2)
		{
			cout << "Delete at the (1)start or (2)ed of the list?(1/2) ";
			cin >> userInput;

			if(userInput.compare("1") == 0)
			{
				list.deleteNode(0);
			}
			else if(userInput.compare("2") == 0)
			{
				list.deleteNode(1);
			} 
			else
			{
				cout << "Invalid option.\n";
			}
		} 
		//Exit while-loop
		else if (menuOption == 3)
		{
			run = false;
		}	
		else
		{
			cout << "Invalid option";
		}

		//Print current list of elements
		cout << "Current LinkedList: ";
		list.printAllElements();

	} while(run);

	//Print final list of elements
	cout << "FINAL VALUES OF LINKEDLIST: ";
	list.printAllElements();
	cout << "-----------------------------------------\n\n";
}

