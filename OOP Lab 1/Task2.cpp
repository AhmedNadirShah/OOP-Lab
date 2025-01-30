#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
int sum=0;
for(int i=1;i<argc;i++){
sum+=stoi(argv[i]);
}
cout<<"Sum of array elements: "<<sum<<endl;
return 0;
}


