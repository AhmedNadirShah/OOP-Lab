#include<iostream>
#include<string>
using namespace std;
class Vehicle{
private:
	int price;
public:
	Vehicle(int p):price(p){}
	int getprice(){
		return price;
	}
};
class Car:public Vehicle{
private:
	int Capacity;
	int Numdoors;
	string fueltype;
public:
	Car(int P,int C,int D,string F):Vehicle(P),Capacity(C),Numdoors(D),fueltype(F){}
	int getCapacity(){return Capacity;}
	int getDoors(){return Numdoors;}
	string getfuel(){return fueltype;}
};
class MotorCycle:public Vehicle{
private:
	int numCylinders;
	int numGears;
	int numWheels;
public:
	MotorCycle(int P,int C,int G,int W):Vehicle(P),numCylinders(C),numGears(G),numWheels(W){}
	int getCylinders(){return numCylinders;}
	int getGears(){return numGears;}
	int getWheels(){return numWheels;}	
};
class Audi:public Car{
private:
	string Model;
public:
	Audi(int P,int C,int D,string F,string M):Car(P,C,D,F),Model(M){}
	string getModel(){return Model;}
void display(){
	cout<<"Price: "<<getprice()<<endl;
	cout<<"Capacity: "<<getCapacity()<<endl;
	cout<<"Number of Doors: "<<getDoors()<<endl;
	cout<<"Fuel Type: "<<getfuel()<<endl;
	cout<<"Model: "<<getModel()<<endl;
}
};
class Yamaha:public MotorCycle{
private:
	string MakeType;
public:
	Yamaha(int P,int C,int G,int W,string t):MotorCycle(P,C,G,W),MakeType(t){}
	string getMakeType(){return MakeType;}
void display(){
	cout<<"Price: "<<getprice()<<endl;
	cout<<"Number of Cylinder: "<<getCylinders()<<endl;
	cout<<"Number of Gears: "<<getGears()<<endl;
	cout<<"Number of Wheels: "<<getWheels()<<endl;
	cout<<"Make Type: "<<getMakeType()<<endl;
}
};
int main(){
Audi a(5000,5,4,"Petrol","Electra");
Yamaha y(2000,6,4,2,"Seventy");
a.display();
y.display();
return 0;
}

