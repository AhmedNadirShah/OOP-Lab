#include<iostream>
#include<string>
using namespace std;
class Employee {
protected:
    int id;
    string name;
public:
    Employee(int Id, string n) : id(Id), name(n) {}
    virtual void displayInfo(){
        cout << "Employee ID: " << id << "Name: " << name << endl;
  }
};
class IOrderTaker{
	virtual void taker(string order)=0;
};
class IOrderPreparer{
	virtual void preparer(string order)=0;
};
class IBiller{
	virtual void biller(int amount)=0;	
};
class Waiter: public Employee, public IOrderTaker{
	public:
		Waiter(int Id,string n):Employee(Id,n){}
		void taker(string order){
			cout<<"Waiter "<<name<<" has your order of "<<order<<endl;
		}		
};
class Chef: public Employee, public IOrderPreparer{
	public:
		Chef(int Id,string n):Employee(Id,n){}
		void preparer(string order){
			cout<<"Chef "<<name<<" is preparing your order of "<<order<<endl;
		}		
};
class Cashier: public Employee, public Biller{
	public:
		Cashier(int Id,string n):Employee(Id,n){}
		void biller(int amount){
			cout<<"Cashier "<<name<<" has your bill of "<<order<<endl;
		}		
};
class Manager:public Employee,public IOrderTaker,public Biller{
	public:
		Manager(int Id,string n):Employee(Id,n){}
		void taker(string order){
			cout<<"Waiter "<<name<<" has your order of "<<order<<endl;
		}		
		void biller(int amount){
			cout<<"Cashier "<<name<<" has your bill of "<<order<<endl;
		}					
};
class Menu {
protected:
    string items[5];
    int prices[5];
public:
    Menu() { 
	for (int i = 0; i < 5; i++) { 
	items[i] = ""; 
	prices[i] = 0; 
	} 
}
    void addItem(int index, string item, int price) { 
	if (index>= 0 && index<5) 
	{ 
	items[index] = item; 
	prices[index] = price; 
	} 
	}
    virtual int calculateTotal(int *quantities) = 0;
    void displayMenu() { 
	for (int i=0; i<5; i++){
	if (!items[i].empty()){
	cout << i + 1 << ") " << items[i] << " -Rs " << prices[i] << endl; 
	}
}
};
class FoodMenu : public Menu {
public:
     int calculateTotal(int *quantities){
        int total = 0;
        for (int i=0; i<5; i++){
        total += prices[i]*quantities[i];
    }
        return total;
    }
};
class BeverageMenu : public Menu {
public:
    int calculateTotal(int *quantities){
        int total = 0;
        for (int i=0; i<5; i++) {
		total += prices[i]*quantities[i];
	}
        return total*2;
    }
};
int main() {
    Waiter waiter(101, "Wasim");
    Chef chef(102, "Waqar");
    Cashier cashier(103, "Razzaq");
    Manager manager(104, "Shoaib");

    FoodMenu foodMenu;
    foodMenu.addItem(0, "Kabab", 500);
    foodMenu.addItem(1, "Biryani", 200);

    BeverageMenu beverageMenu;
    beverageMenu.addItem(0, "Coke", 50);
    beverageMenu.addItem(1, "Chai", 40);

    cout << "Food Menu:\n"<<foodMenu.displayMenu();
    cout << "\nBeverage Menu:\n"<<beverageMenu.displayMenu();

    waiter.takeOrder("Kabab and Coke");
    chef.prepareOrder("Kabab");

    int foodQuantities[5] = {1, 0, 0, 0, 0};
    int beverageQuantities[5] = {1, 0, 0, 0, 0};

    double totalFood = foodMenu.calculateTotal(foodQuantities);
    double totalBeverage = beverageMenu.calculateTotal(beverageQuantities);
    double totalBill = totalFood + totalBeverage;

    cashier.generateBill(totalBill);
    return 0;
}

