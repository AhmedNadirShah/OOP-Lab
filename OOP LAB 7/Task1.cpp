#include<iostream>
#include<string>
using namespace std;
class Fraction{
private:
	int numer;
	int denom;
public:
	Fraction(int n,int d):numer(n),denom(d){
		if(denom<0){
			denom=-denom;
			numer=-numer;
		}
	}
	int getnumer(){
		return numer;
	}
	int getdenom(){
		return denom;
	}
	int GCD(int n,int d){
		while(d!=0){
			int temp=d;
			d=n%d;
			n=temp;
		}
		return n;
	}
	Fraction simplify(){
		int gcd=GCD(numer,denom);
		return Fraction(numer/gcd,denom/gcd);
	}
	void display(){
		cout<<numer<<"/"<<denom<<endl;
	}
Fraction operator+(Fraction& obj){
	int newNumer=getnumer()*obj.getdenom()+getdenom()*obj.getnumer();
	int newDenom=getdenom()*obj.getdenom();
	return Fraction(newNumer,newDenom).simplify();
}
Fraction operator-(Fraction& obj){
	int newNumer=getnumer()*obj.getdenom()-getdenom()*obj.getnumer();
	int newDenom=getdenom()*obj.getdenom();
	return Fraction(newNumer,newDenom).simplify();
}
Fraction operator*(Fraction& obj){
	int newNumer=getnumer()*obj.getnumer();
	int newDenom=getdenom()*obj.getdenom();
	return Fraction(newNumer,newDenom).simplify();
}
Fraction operator/(Fraction& obj){
	int newNumer=getnumer()*obj.getdenom();
	int newDenom=getdenom()*obj.getnumer();
	return Fraction(newNumer,newDenom).simplify();
}
Fraction operator==(Fraction& obj){
	if(getnumer()==obj.getnumer() && getdenom()==obj.getdenom()){
		cout<<"Equal\n";
	}
}
Fraction operator!=(Fraction& obj){
	if(getnumer()!=obj.getnumer() || getdenom()!=obj.getdenom()){
		cout<<"Not Equal\n";
	}
}
Fraction operator <(Fraction& obj){
	if(getnumer()<obj.getnumer() && obj.getdenom()<getdenom()){
		cout<<"The second fraction is larger\n";
	}
}
Fraction operator >(Fraction& obj){
	if(getnumer()>obj.getnumer() && obj.getdenom()>getdenom()){
		cout<<"The first fraction is larger\n";	
}
}
Fraction operator<=(Fraction& obj){
	if(getnumer()<=obj.getnumer() && obj.getdenom()<=getdenom()){
		cout<<"The second fraction is larger\n";
	}
}
Fraction operator>=(Fraction& obj){
	if(getnumer()>=obj.getnumer() || obj.getdenom()>=getdenom()){
		cout<<"The first fraction is larger\n";	
}
}
friend ostream& operator<<(ostream& os, Fraction& obj);
friend istream& operator>>(istream& is, Fraction& obj);
};
ostream& operator<<(ostream& os, Fraction& obj){
	os<<obj.getnumer()<<"/"<<obj.getdenom()<<endl;
}
istream& operator>>(istream& is, Fraction& obj){
	is>>obj.numer>>obj.denom;
}
int main(){
Fraction f1(3,3);
Fraction f2(3,3);
Fraction sum=f1+f2;
Fraction sub=f1-f2;
Fraction mul=f1*f2;
Fraction div=f1/f2;
f1==f2;
f1!=f2;
f1<f2;
f1>f2;
f1<=f2;
f1>=f2;
sum.display();
sub.display();
mul.display();
div.display();
Fraction f3(0,0);
cout<<"Enter fraction"<<endl;
cin>>f3;
cout<<f3;
return 0;
}

