#include<iostream>
#include<string>
using namespace std;
class Engine{
public:
bool isRunning;
void start(){
    cout<<"Engine Started"<<endl;
    isRunning=true;
    cout<<"Is Running "<<isRunning<<endl;
}
void stop(){
    cout<<"Engine Stoped"<<endl;
    isRunning=false;
    cout<<"Is Running "<<isRunning<<endl;
}
};
class Car{
private:
Engine engine;
public:
	Car(string Name){
	cout<<Name<<" Engine Constructed"<<endl;	
	}
	~Car(){
	cout<<"Engine Destroyed"<<endl;	
	}
void startCar(){
   engine.start();
}
void stopCar(){
   engine.stop();
}
};
int main(){
    Car obj("Mehran");
    obj.startCar();
    obj.stopCar();
    return 0;
}
