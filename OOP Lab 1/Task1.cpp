#include<iostream>
#include<string>
using namespace std;
int main(int argc,char* argv[]){
float arr[20],*point=arr;
int n=20;
for(int i=0;i<n;i++){
*(point+i)=stof(argv[i+1]);
}
float temp;
for(int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
if(*(point+j)>*(point+j+1)){
temp=*(point+j);
*(point+j)=*(point+j+1);
*(point+j+1)=temp;
}
}
}
cout<<"The second highest number is "<<*(point+n-2)<<endl;
return 0;
}
 0;
}


