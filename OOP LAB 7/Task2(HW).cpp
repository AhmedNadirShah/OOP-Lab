#include<iostream>
#include<string>
using namespace std;
class Shape{
private:
	float length;
	float breadth;
public:
	Shape(float l,float b):length(l),breadth(b){}
	float Area(){
		cout<<length*breadth<<endl;
	}
	Shape operator+(Shape& obj){
		return Shape(length+obj.length,breadth+obj.breadth);
	}
	void display(){
		cout<<"Length: "<<length<<endl<<"Breadth: "<<breadth<<endl;
	}
};
int main(){
Shape s1(5,6);
Shape s2(2,4);
Shape area=s1+s2;
area.Area();
area.display();
return 0;
}

