#include<iostream>
#include<string>
using namespace std;
class Wallet{
	double balance;
	double limit;
public:
	Wallet():balance(0.0),limit(5000.0){}
	double withdraw(double amount){
		if(balance>amount && amount<limit){
		balance-=amount;
		return balance;
	}
		else if(balance>amount){
		cout<<"Invalid request\n";
		return balance;
	}
	    else 
	    cout<<"Exceeding limit\n";
	    return balance;
	}
	double deposit(double amount){
		if(amount<limit){
		balance+=amount;
		return balance;
	}
	else
	cout<<"Exceeding limit\n";
	return balance;
	}	
	double getbalance(){
		return balance;
	}
};
class User{
	string UserID;
	string name;
	Wallet mywallet;
public:
	User(string id,string n):UserID(id),name(n){}
	string getname(){
		return name;
	}
	string getid(){
		return UserID;
	}
	double withdraw(double amount){
		return mywallet.withdraw(amount);
	}
	double deposit(double amount){
		return mywallet.deposit(amount);
	}
	void display(){
		cout<<"Name: "<<getname()<<endl;
		cout<<"ID: "<<getid()<<endl;
		cout<<"Balance: "<<mywallet.getbalance();
	}
};
int main(){
	User u("1001","Ahmed");
	u.deposit(6000.0);
	u.withdraw(7000.0);
	u.display();
}
