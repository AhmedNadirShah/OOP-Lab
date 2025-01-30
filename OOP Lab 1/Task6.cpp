#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(int argc, char* argv[]){
string Name= argv[1];
float Score_1= stof(argv[2]);
float Score_2= stof(argv[3]);
float Score_3= stof(argv[4]);
float Score_4= stof(argv[5]);
float Score_5= stof(argv[6]);
float average_score=0;
cout<<fixed<<setprecision(2);
average_score=(Score_1+Score_2+Score_3+Score_4+Score_5)/5.0;
cout<<"Student Name:  "<<Name<<endl;
cout<<"Test Scores: ";
for(int i=2;i<7;i++){
cout<<stof(argv[i])<<" ";
} 
cout<<endl;
cout<<"Average Score: "<<average_score;
return 0;
}

