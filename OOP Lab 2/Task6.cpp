#include <iostream>
#include <string>
using namespace std;

struct SubjectInfo{
string subject;
};

struct student{
int ID;
SubjectInfo subjects[3];
};

int main(){
int num;
cout<<"Enter the number of students: ";
cin>>num;
student* students=new student[num];
for(int i=0;i<num;i++){
cout<<"Enter Student ID: ";
cin>>students[i].ID;
cout<<"Enter 3 subjects:"<<endl;
for(int j=0;j<3;j++){
cout<<"Subject "<<j+1<<": ";
cin>>students[i].subjects[j].subject;
}}
cout<<"\nStudent Details:\n";
for(int i=0;i<num;i++){
cout<<"Student ID: "<<students[i].ID<<endl<<"Subjects: "<<endl;
for(int j=0;j<3;j++){
cout<<students[i].subjects[j].subject<<endl;
}
cout<<endl;
}
delete[] students;
return 0;
}


