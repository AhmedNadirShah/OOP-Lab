#include<iostream>
#include<string>
#include<fstream>
using namespace std;
string encrypt(string str) {
	for(int i=0; i<str.length(); i++) {
		str[i]=str[i]+(i+1);
	}
	return str;
}
string decrypt(string str) {
	for(int i=0; i<str.length(); i++) {
		str[i]=str[i]-(i+1);
	}
	return str;
}
int main() {
	ofstream file;
	file.open("Task1.txt");

	if(!file) {
		cout<<"File not open\n";
		return 1;
	}

	string str;
	string Encrypt;
	string Decrypt;

	cout<<"Enter word\n";
	getline(cin,str);
	file<<str<<endl;
	Encrypt=encrypt(str);
	file<<Encrypt<<endl;
	Decrypt=decrypt(Encrypt);
	file<<Decrypt<<endl;
	file.close();

	return 0;
}
