#include<iostream>
#include<string>
using namespace std;
class Student{
	int id;
	string name;
public:
	Student():id(0),name(" "){}
	Student(int ID,string n):id(ID),name(n){
	}
	string getname(){
		return name;
	}
	int getid(){
		return id;
	}
	void setStudent(){
		cout<<"Enter Name:"<<endl;
		cin>>name;
		cout<<"Enter ID:"<<endl;
		cin>>id;		
	}
	void infodisplay(){
		cout<<"Name: "<<name<<endl;
		cout<<"Id: "<<id<<endl;
	}
};
class marks: public Student{
protected:
	int marks_OOP, marks_DS, marks_PF, marks_DB;
public:
	marks() : marks_OOP(0), marks_DS(0), marks_PF(0), marks_DB(0) {}
	marks(int ID,string n,int o,int ds,int pf, int db):Student(ID,n),marks_OOP(o), marks_DS(ds), marks_PF(pf), marks_DB(db) {}
	void setmarks(int o,int ds,int pf, int db){
		marks_OOP=o;
		marks_DS=ds;
		marks_PF=pf;
		marks_DB=db;
	}
	void getmarks(){
	cout<<marks_OOP<<endl<<marks_DS<<endl<<marks_PF<<endl<<marks_DB;
	}
};
class result: public marks{
protected:
	int total;
	double average;
public:
	void display(){
	    infodisplay();
		total=marks_OOP+marks_DS+marks_PF+marks_DB;
		cout<<total<<endl;
		average=(total/4.0)*100;
		cout<<average<<endl;
	}
};
int main(){
result r;
r.setStudent();
r.setmarks(55,65,72,81);
r.getmarks();
cout<<endl;
r.display();
return 0;
}

