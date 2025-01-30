#include<iostream>
#include<iomanip>
using namespace std;
int main(int argc, char* argv[]) {
string Movie_Name = argv[1];
float Adult_Ticket_Price = stof(argv[2]);
float Child_Ticket_Price = stof(argv[3]);
int Number_of_Adult_Tickets_Sold = stoi(argv[4]);
int Number_of_Child_Tickets_Sold = stoi(argv[5]);
float Donation_Percentage = stof(argv[6]);
int Total_Tickets_Sold = Number_of_Adult_Tickets_Sold + Number_of_Child_Tickets_Sold;
float Gross_Amount = (Adult_Ticket_Price * Number_of_Adult_Tickets_Sold) + (Child_Ticket_Price * Number_of_Child_Tickets_Sold);
float Amount_Donated = Gross_Amount * (Donation_Percentage / 100);
float Net_Sale = Gross_Amount - Amount_Donated;
cout << fixed << setprecision(2);
cout << "Movie Name: " << right << setw(30) << Movie_Name << "\n";
cout << "Number of Tickets Sold: " << right << setw(20) << Total_Tickets_Sold << "\n";
cout << "Gross Amount: " << right << setw(15) << Gross_Amount << "$"<< "\n";
cout << "Percentage of Gross Amount Donated: " << right << setw(10) << Donation_Percentage << "%" << "\n";
cout << "Amount Donated: " << right << setw(15) << Amount_Donated << "$" << "\n";
cout << "Net Sale: " << right << setw(20) << Net_Sale<< "$" << "\n";
return 0;
}



