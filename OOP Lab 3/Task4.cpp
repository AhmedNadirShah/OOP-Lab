#include<iostream>
#include<string>
using namespace std;
class Employee{
public:
string firstName;
string lastName;
double monthlySalary;
};
int main(int argc, char* argv[]){
int yearlySalary1,yearlySalary2;
Employee EmployeeTest1;
Employee EmployeeTest2;
EmployeeTest1.firstName=argv[1];
EmployeeTest1.lastName=argv[2];
EmployeeTest1.monthlySalary=stod(argv[3]);
if(EmployeeTest1.monthlySalary<0.0){
EmployeeTest1.monthlySalary=0.0;
}
EmployeeTest2.firstName=argv[4];
EmployeeTest2.lastName=argv[5];
EmployeeTest2.monthlySalary=stod(argv[6]);
if(EmployeeTest2.monthlySalary<0.0){
EmployeeTest2.monthlySalary=0.0;
}
yearlySalary1=EmployeeTest1.monthlySalary*12;
yearlySalary2=EmployeeTest2.monthlySalary*12;
yearlySalary1+=yearlySalary1*0.1;
yearlySalary2+=yearlySalary2*0.1;
cout<<EmployeeTest1.firstName<<"Your incremented yearly Salary is "<<yearlySalary1<<endl;
cout<<EmployeeTest2.firstName<<"Your incremented yearly Salary is Employee 2 "<<yearlySalary2<<endl;
}
