#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void add(){
	fstream file("Task5.txt",ios::app);
	if(!file){
		cout<<"File not open\n";
		return;
	}
	string task;
	getline(cin,task);
	file<<task<<endl;
	file.close();
}
void ViewTasks(){
	fstream file("Task5.txt");
	if(!file){
		cout<<"File not open\n";
		return;
	}
	string line;
	int index=0;
	while(getline(file,line)){
		cout<<++index<<") "<<line<<endl;
	}
	file.close();
}
void MarkAsDone(){
	fstream file("Task5.txt");
	if(!file){
		cout<<"File not open\n";
		return;
	}
	string line;
	int count=0;
	while(getline(file,line)){
	  count++;
	}
	file.clear();
	file.seekg(0,ios::beg);
	string* Tasks=new string[count];
	int i=0;
	while(getline(file,line)){
		Tasks[i]=line;
		i++;
	}
	cout<<"Choose which task to mark as done\n";
	int choice;
	cin>>choice;
	if(choice>1 && choice<count){
		Tasks[choice-1]="Done";
	}
	else
	cout<<"Invalid choice\n";
	file.close();
	ofstream outfile("Task5.txt",ios::out);
    for (int j = 0; j < count; j++) {
        outfile << Tasks[j] << endl;
    }
    outfile.close();
    delete[] Tasks;
}
int main() {
cout<<"How many Task you want to add"<<endl;
int num;
cin>>num;
cin.ignore();
cout<<"Enter tasks\n";
for(int i=0;i<num;i++){
add();
}
ViewTasks();
MarkAsDone();
ViewTasks();
return 0;
}

