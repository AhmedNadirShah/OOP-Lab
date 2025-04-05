#include<iostream>
#include<string>
using namespace std;
class number{
protected:
	int num;
public:
	number(int n):num(n){}
    number operator --(){
		num*=4;
		return num;
	}
	number operator--(int){
		number temp=num;
		num/=4;
		return temp;
	}
void display(){
	cout<<"Number: "<<num<<endl;
}
};
int main(){
number n1(2);
--n1;
n1.display();
n1--;
n1.display();
return 0;
}
