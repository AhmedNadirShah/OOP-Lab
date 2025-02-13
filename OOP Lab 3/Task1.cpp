#include<iostream>
#include<string>
using namespace std;
class User{
public:
int Age;
string Name;	
};
int main(int argc, char* argv[]){
User obj;
obj.Age=stoi(argv[1]);
obj.Name=argv[2];
cout<<"My name is "<<obj.Name<<" and my age is "<<obj.Age;
return 0;
}
