#include<iostream>
#include<string>
using namespace std;
struct employee{
string employee_id;
string name;
int salary;
};
struct organization{
string organization_name;
int organisation_number;
employee emp;
};
int main(){
organization org;
org.emp.employee_id= "NUFAST123ABC";
org.emp.name= "Linus Sebastian";
org.emp.salary= 400000;
org.organization_name= "NU-Fast";
org.organisation_number= 127;

cout<<"Organisation Name: "<<org.organization_name<<endl;
cout<<"Organisation Number: "<<org.organisation_number<<endl;
cout<<"Employee id: "<<org.emp.employee_id<<endl;
cout<<"Employee name: "<<org.emp.name<<endl;
cout<<"Employee Salary: "<<org.emp.salary<<endl;
return 0;
}

