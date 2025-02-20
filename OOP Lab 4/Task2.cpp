#include <iostream>
#include <cstdlib>

using namespace std;

class Account {
private:
	double balance;

public:
	Account(double initialBalance) {
		this->balance = (initialBalance >= 0) ? initialBalance : 0;
	}

	void credit(double amount) {
		this->balance += amount;
	}

	void debit(double amount) {
		if (amount > this->balance) {
			cout << "Debit amount exceeded account balance." << endl;
		} else {
			this->balance -= amount;
		}
	}

	double getBalance() {
		return this->balance;
	}
};

int main(int argc, char* argv[]) {
	if (argc != 4) {
		cout << "Usage: " << argv[0] << " <initial_balance> <deposit_amount> <withdraw_amount>" << endl;
		return 1;
	}

	double initialBalance = atof(argv[1]);
	double depositAmount = atof(argv[2]);
	double withdrawAmount = atof(argv[3]);

	Account acc(initialBalance);
	acc.credit(depositAmount);
	acc.debit(withdrawAmount);

	cout << "Final Balance: " << acc.getBalance() << endl;

	return 0;
}

