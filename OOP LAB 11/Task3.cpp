#include<iostream>
#include<string>
using namespace std;
template<typename T>
class SafeArray{
int size;
T* entry;
public:
SafeArray(int s):size(s){
	entry=new T[size];
}
T& operator[](int index){
	if(index<0 || index>size){
		throw"Array out of bound";
	}
		else
		return entry[index];
	}	
};
int main(){
SafeArray<int> a(5);
cout<<"Enter elements\n";
for(int i=0;i<5;i++){
	cin>>a[i];
}
try{
	cout<<"Element: "<<a[2]<<endl;
	cout<<"Element: "<<a[10]<<endl;
}
catch(const char* c){
	cout<<"Error: "<<c<<endl;
}
return 0;
}

