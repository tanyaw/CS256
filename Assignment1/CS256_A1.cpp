/* 
 *	Course: CS 256 - C++ Programming
 *	Professor: Steve Jankly
 *	Assignment #1
 *	
 *	Tanya Wanwatanakool
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

class ATM {
    public:
        int balance;
        int pin;

        ATM() {
            balance = 1000;
        }

        void menu(int i) {
            if(pin == i) {
                cout << "--- ATM Menu---\n  1. Withdraw Money\n  2. Deposit Money\n  3. Balance Inquiry\n  4. Fast Cash $200\n  5. Exit\nPlease enter a value from 1-5: "; 
            } else {
                cout << "This pin is invalid. The ATM is shutting down now, goodbye!\n";
                std::exit(0);
            }
            return;
        }

        void withdraw(int amount) {
            if(balance < 0) {
                cout << "Your balance is negative, you cannot withdraw any cash.\n";
            } else if(balance == 0) {
                cout << "Your balance is at $0, you cannot withdraw any cash.\n";
            } else {
                balance -= amount;
                if(balance < 0) {
                    balance += amount;
                    cout << "You do not have enough money in your account to withdraw this amount.\n";
                } else {
                    cout << "You withdrew $" << amount << endl << "Your balance is: $" << balance << endl;
                }
            }   
            return;
        }

        void deposit(int amount) {
            balance += amount;
            cout << "You deposited $" << amount <<endl << "Your balance is: $" << balance << endl;
            return;
        }

        void balanceInquiry() {
            cout << "Your balance is: $ " << balance << endl;
            return;
        }

        void fastCash() {
            if(balance < 0) {
                cout << "Your balance is negative, you cannot withdraw any cash.\n";
            } else if(balance == 0) {
                cout << "Your balance is at $0, you cannot withdraw any cash.\n";
            } else {
                balance -= 200;
                if(balance < 0) {
                    balance += 200;
                    cout << "You do not have enough money in your account to withdraw this amount.\n";
                } else {
                    cout << "You withdrew $200.\n Your balance is: $" << balance << endl;
                }
            }   
            return;
        }

        void exit() {
            cout << "Thanks for using this ATM, goodbye!\n";
            std::exit(0);
            return;
        }

};

int main() {
    cout << "Welcome to the ATM machine simulator.\n";
    cout << "Please choose an integer PIN value: ";
    ATM machine;

    int i;
    cin >> i;
    machine.pin = i;

    int userInput;

    do {
        int enterPin;
        cout << "----------------------------\n";
        cout << "Please validate your pin: ";
        cin >> enterPin;
        machine.menu(enterPin);
        cin >> userInput;

        switch(userInput) {
            case 1:
                int val;
                cout << "Please enter amount to withdraw: ";
                cin >> val;
                machine.withdraw(val);
                break;
            case 2:
                cout << "Please enter amount to deposit: ";
                cin >> val;
                machine.deposit(val);
                break;
            case 3:
                machine.balanceInquiry();
                break;
            case 4:
                machine.fastCash();
                break;
            case 5:
                machine.exit();
                break;
            default:
                cout << "That's an invalid option.\n";
                machine.menu(enterPin);
                break;
        }
    } while(userInput != 5);
    

    return 0;
}