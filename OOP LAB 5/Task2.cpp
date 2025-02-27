#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Car{
private:
	string Name;
	int id;
public:
Car(string CarName,int CarID): Name(CarName), id(CarID) {};
string getName(){
	return Name;
}
int getID(){
	return id;
}
};
class Garage{
public:
	vector<Car*> cars;
void ParkCar(Car* car){
	cars.push_back(car);
}
void listCars(){
	for (int i=0;i<cars.size();i++) {
  cout << cars[i]->getName() <<endl;
  cout << cars[i]->getID() <<endl;
}
}
};
int main(){
	Car obj1("Ahmed",1234);
	Car obj2("Wasim",5678);
	Garage garage;
	garage.ParkCar(&obj1);
	garage.ParkCar(&obj2);
	garage.listCars();
}
