#include <iostream>
#include <cstring>

using namespace std;

class Person {
protected:
    int empID;

public:
    Person(int id) : empID(id) {}

    void displayData() {
        cout << "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
protected:
    char name[50];
    double monthlyIncome;

public:
    Admin(int id, const char* empName, double income) : Person(id), monthlyIncome(income) {
        strcpy(name, empName);
    }

    double bonus() {
        return monthlyIncome * 0.05 * 12;
    }

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }
};

class Accounts : public Person {
protected:
    char name[50];
    double monthlyIncome;

public:
    Accounts(int id, const char* empName, double income) : Person(id), monthlyIncome(income) {
        strcpy(name, empName);
    }

    double bonus() {
        return monthlyIncome * 0.05 * 12;
    }

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }
};

int main() {
    Admin adminList[] = {
        Admin(101, "Alice Johnson", 5000),
        Admin(102, "Bob Smith", 6000)
    };

    Accounts accountList[] = {
        Accounts(201, "Charlie Davis", 5500),
        Accounts(202, "Diana Miller", 6200)
    };

    cout << "\nDisplaying details of Admin employees:\n";
    for (int i = 0; i < 2; i++) {
        cout << "\nAdmin Employee " << i + 1 << ":\n";
        adminList[i].displayData();
    }

    cout << "\nDisplaying details of Accounts employees:\n";
    for (int i = 0; i < 2; i++) {
        cout << "\nAccounts Employee " << i + 1 << ":\n";
        accountList[i].displayData();
    }

    return 0;
}

