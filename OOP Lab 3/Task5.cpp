#include<iostream>
#include<string>
using namespace std;
class book{
public:
string name;
string ISBN;
string author;
string publisher;
book(){}
book(string name,string ISBN,string author,string publisher){
this->name=name;
this->ISBN=ISBN;
this->author=author;
this->publisher=publisher;
}
string getName(){
return this->name;
}
string getISBN(){
return this->ISBN;
}
string getAuthor(){
return this->author;
}
string getPublisher(){
return this->publisher;
}
void getBookInfo(){
cout<<"Name: "<<name<<endl;
cout<<"ISBN: "<<ISBN<<endl;
cout<<"Author: "<<author<<endl;
cout<<"Publisher: "<<publisher<<endl;
}
};
int main(){
book bookTest[5];
for(int i=0; i<5; i++){
cout<<"Book "<<i+1<<":"<<endl;
cout<<"Name: ";
cin>>bookTest[i].name;
cout<<"ISBN: ";
cin>>bookTest[i].ISBN;
cout<<"Author: ";
cin>>bookTest[i].author;
cout<<"Publisher: ";
cin>>bookTest[i].publisher;
}
for(int i=0;i<5;i++){
cout<<"Book "<<i+1<<":"<<endl;
bookTest[i].getBookInfo();
}
return 0;
}

