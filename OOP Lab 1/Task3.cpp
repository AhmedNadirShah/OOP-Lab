#include<iostream>
#include<string>
using namespace std;
int main(int argc,char* argv[]){
int id=stoi(argv[1]);
string name=argv[2];
int consumed=stoi(argv[3]);
float bill=0.0;
float surchargeAmount=0.0;
if(consumed>=0){
if(consumed<199){
bill=consumed*16.20;
}
else if(consumed>200 && consumed<300){
bill=consumed*20.10;
}
else if(consumed>300 && consumed<500){
bill=consumed*27.10;
}
else if(consumed>500){
bill=consumed*35.90;
}
}
else{
cout<<"Enter correct value";
}
if(bill>18000){
surchargeAmount=18000*0.15;
bill+=surchargeAmount;
}
cout<<id<<endl;
cout<<name<<endl;
cout<<consumed<<endl;
cout<<bill<<endl;
cout<<surchargeAmount<<endl;
return 0;
}


