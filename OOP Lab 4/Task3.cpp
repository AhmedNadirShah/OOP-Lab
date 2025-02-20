#include <iostream>

using namespace std;

class Invoice {
public:
	string partNumber;
	string partDescription;
	int quantity;
	double pricePerItem;

	Invoice(string pNum, string pDesc, int qty, double price) {
		partNumber = pNum;
		partDescription = pDesc;
		quantity = (qty > 0) ? qty : 0;
		pricePerItem = (price > 0) ? price : 0.0;
	}

	double getInvoiceAmount() {
		return quantity * pricePerItem;
	}
};

int main() {
	string partNum, partDesc;
	int qty;
	double price;

	cout << "Enter part number: ";
	getline(cin, partNum);

	cout << "Enter part description: ";
	getline(cin, partDesc);

	cout << "Enter quantity: ";
	cin >> qty;

	cout << "Enter price per item: ";
	cin >> price;

	Invoice invoice(partNum, partDesc, qty, price);

	cout << "Invoice Amount: " << invoice.getInvoiceAmount() << endl;

	return 0;
}

