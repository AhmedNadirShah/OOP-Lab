#include<iostream>
#include<string>
using namespace std;
class Books{
private:
	string genre;	
public:
	Books(string g):genre(g){}
	string getgenre(){return genre;}
};
class Fantasy:public Books{
private:
	string title;
	string author;
public:
	Fantasy(string t,string a):Books("Fantasy"),title(t),author(a){}
	string gettitle(){return title;}
	string getauthor(){return author;}
void display(){
	cout<<"Genre: "<<getgenre()<<endl;
	cout<<"Title: "<<gettitle()<<endl;
	cout<<"Author: "<<getauthor()<<endl;
}
};
class Mystery: public Books{
private:
	string title;
	string author;
public:
	Mystery(string t,string a):Books("Mystery"),title(t),author(a){}
	string gettitle(){return title;}
	string getauthor(){return author;}
void display(){
	cout<<"Genre: "<<getgenre()<<endl;
	cout<<"Title: "<<gettitle()<<endl;
	cout<<"Author: "<<getauthor()<<endl;
}
};
int main(){
Fantasy f("Odesa","Wasim");
Mystery m("Spaiens","Waqar");
f.display();
m.display();
return 0;
}

