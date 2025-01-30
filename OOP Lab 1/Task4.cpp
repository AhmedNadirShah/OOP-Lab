#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(int argc, char* argv[]){
float weight;
cout<<"Enter your weight in kilogram "<<endl;
weight=stof(argv[1]);
float pound=weight*2.2;
printf("Your weight in pounds is ");
printf("%.2f",pound);
return 0;
}
