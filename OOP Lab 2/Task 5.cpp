#include<iostream>
#include<string>
using namespace std;
struct student{
int id;
string name;
};
sortId(student arr[],int n){
for(int i=0;i<n;i++){
for(int j=0;j<n-i-1;j++){
if(arr[j].id>arr[j+1].id){
student temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
sortChar(student arr[],int n){
for(int i=0;i<n;i++){
for(int j=0;j<n-i-1;j++){
if(arr[j].name[0]>arr[j+1].name[0]){
student temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
int main(){
cout<<"How many students data you want to enter"<<endl;
int N;
cin>>N;
student st[N];
cout<<"Enter the Elements"<<endl;
for(int i=0;i<N;i++){
cout<<"For student "<<i+1<<":"<<endl;
cout<<"id: ";
cin>>st[i].id;
cout<<"Name: ";
cin>>st[i].name;
}
sortId(st,N);
cout<<"Student Id in asscending"<<endl;
for(int i=0;i<N;i++){
cout<<st[i].id<<" "<<st[i].name<<endl;
}
cout<<endl;
sortChar(st,N);
cout<<"Student name in asscending"<<endl;
for(int i=0;i<N;i++){
cout<<st[i].id<<" "<<st[i].name<<endl;
}
return 0;
}

