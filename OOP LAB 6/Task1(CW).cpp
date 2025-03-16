#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
	int AccountNumber;
	int Balance;
public:
	BankAccount(int num = 0, int bal = 0)
		: AccountNumber(num), Balance(bal) {}

	int getnum() { return AccountNumber; }
	int getbal() { return Balance; }

	void setnum(int num) { AccountNumber = num; }

	void deposit() {
		int amount;
		cout << "Enter deposit amount: ";
		cin >> amount;
		Balance += amount;
		cout << "Deposit successful! New balance: " << Balance << endl;
	}

	void withdraw() {
		int amount;
		cout << "Enter withdraw amount: ";
		cin >> amount;
		if (amount > Balance) {
			cout << "Not enough money in your account.\n";
		} else {
			Balance -= amount;
			cout << "Withdrawal successful! New balance: " << Balance << endl;
		}
	}
};
class Employee {
public:
	string name;
	int id;

	void freeze(BankAccount& obj) {
		cout << "Enter Account Number to freeze: ";
		int Accnum;
		cin >> Accnum;
		if (obj.getnum() == Accnum) {
			cout << "Account " << Accnum << " is now frozen.\n";
			obj.setnum(-1);  // Indicating frozen account
		}
	}
};
class Teller : public Employee {
public:
	void choice(BankAccount& account) {
		int input;
		do {
			cout << "1. Withdraw\n2. Deposit\n3. Freeze Account\n4. Exit\n";
			cin >> input;
			switch (input) {
				case 1:
					account.withdraw();
					break;
				case 2:
					account.deposit();
					break;
				case 3:
					freeze(account);
					break;
				case 4:
					return;
				default:
					cout << "Enter correct input.\n";
			}
		} while (input != 4);
	}
};
class Manager : public Employee {
public:
	void choice(BankAccount& account) {
		int input;
		do {
			cout << "1. Withdraw\n2. Deposit\n3. Freeze Account\n4. Exit\n";
			cin >> input;
			switch (input) {
				case 1:
					account.withdraw();
					break;
				case 2:
					account.deposit();
					break;
				case 3:
					freeze(account);
					break;
				case 4:
					return;
				default:
					cout << "Enter correct input.\n";
			}
		} while (input != 4);
	}
};
class Customer {
public:
	void choice(BankAccount& account) {
		int input;
		do {
			cout << "1. Withdraw\n2. Deposit\n3. Exit\n";
			cin >> input;
			switch (input) {
				case 1:
					account.withdraw();
					break;
				case 2:
					account.deposit();
					break;
				case 3:
					return;
				default:
					cout << "Enter correct input.\n";
			}
		} while (input != 3);
	}
};
int main() {
	BankAccount accounts[3] = {
		BankAccount(1001, 5000),
		BankAccount(1002, 10000),
		BankAccount(1003, 2000)
	};
	Customer customer;
	Teller teller;
	Manager manager;

	int input;
	do {
		cout << "Enter 1 for Customer\nEnter 2 for Employee\nEnter 3 to Exit\n";
		cin >> input;

		switch (input) {
			case 1: {
				cout << "Enter your account number: ";
				int accNum;
				cin >> accNum;
				for (int i = 0; i < 3; i++) {
					if (accounts[i].getnum() == accNum) {
						cout << "Account found! Your balance: " << accounts[i].getbal() << endl;
						customer.choice(accounts[i]);
						break;
					}
				}
				break;
			}

			case 2: {
				cout << "Enter your position (Teller/Manager): ";
				string position;
				cin >> position;

				cout << "Enter the account number to manage: ";
				int accNum;
				cin >> accNum;

				for (int i = 0; i < 3; i++) {
					if (accounts[i].getnum() == accNum) {
						if (position == "Manager") {
							manager.choice(accounts[i]);
						} else if (position == "Teller") {
							teller.choice(accounts[i]);
						} else {
							cout << "Invalid position. Try again.\n";
						}
						break;
					}
				}
				break;
			}

			case 3:
				cout << "Exiting the program.\n";
				break;

			default:
				cout << "Enter a valid option.\n";
		}
	} while (input != 3);
	return 0;
}

