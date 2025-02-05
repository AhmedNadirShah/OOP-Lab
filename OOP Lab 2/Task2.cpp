#include<iostream>
#include<string>
using namespace std;
void* Add(void* arr){
int element=5;
int* intArr = ((int*)arr);
for(int i=0;i<5;i++){
intArr[i]+=element;
}
return intArr;
}
int main(int argc, char* argv[]){
int arr[5];
for(int i=0;i<5;i++){
arr[i]=stoi(argv[i+1]);
}
void* Ans=Add((void*)arr);
int* intAns = ((int*)Ans);
for(int i=0;i<5;i++){
cout<<intAns[i]<<" ";
}
return 0;
}

