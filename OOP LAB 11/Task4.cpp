#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Base{
protected:
	T a,b;
public:
	Base(T i, T j):a(i),b(j){}
	virtual void multiply(){
		cout<<a*b<<endl;
	}
};
template<typename T>
class Derived:public Base<T>{
public:
	Derived(T i, T j):Base<T>(i,j){}
	void multiply(){
		cout<<this->a*this->b<<endl;
	}
};
int main(){
Base<int>* B= new Base<int>(2,3);
Derived<int>* D= new Derived<int>(1,2);
B->multiply();
D->multiply();
return 0;
}

