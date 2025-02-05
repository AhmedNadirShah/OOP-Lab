#include<iostream>
#include<cstring>
using namespace std;
int main(){
int count=0;
int n=5;
int* arr=new int[n];
cout<<"Enter Array Elements"<<endl;
while(true){
int input;
cin>>input;
if(input==-1){
break;
}
if(count==n){
int newSize= n*2;
int*newArr=new int[n*2];
memcpy(newArr,arr,n*sizeof(int));
delete[] arr;
arr=newArr;
n=newSize;
}
arr[count++]=input;
}
for(int i=0;i<count;i++){
cout<<arr[i]<<endl;
}
delete[] arr;
return 0;
}

