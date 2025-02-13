#include<iostream>
#include<string>
using namespace std;
class Glass{
public:
int LiquidLevel=200;
void drink(int millileters){
cout<<"How much drink is left"<<endl;
cin>>millileters;
LiquidLevel=millileters;
}
void Refill(){
if(LiquidLevel<100){
LiquidLevel=200;
cout<<"Drink is refilled"<<endl;
}
else
cout<<"Sorry, Can not Refill now"<<endl;
}
};
int main(){
Glass obj;
int input, millileters;
do{
cout<<"Enter 1 to refill\n"<<"Enter 2 to exit\n";
cin>>input;
switch(input){
case 1:
obj.drink(millileters);
obj.Refill();
break;
case 2:
cout<<"We will exit the program shortly";
return 0;
default:
cout<<"Enter the correct input"<<endl;
}
}
while(input!=0);
}
