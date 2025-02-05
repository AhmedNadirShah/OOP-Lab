#include<iostream>
#include<string>
using namespace std;
int main(int argc, char* argv[]){
int arr[5];
int *ptr=arr;
for(int i=0;i<5;i++){
*(ptr+i)=stoi(argv[i+1]);
}
int sum=0;
for(int i=0;i<5;i++){
sum+=*(ptr+i);
}
cout<<"The sum of all elements is "<<sum;
return 0;
}

