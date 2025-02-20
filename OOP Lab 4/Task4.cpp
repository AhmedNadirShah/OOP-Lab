#include <iostream>

using namespace std;

class Books {
public:
    string title;
    string author;
    string publisher;
    double price;
    int stock;

    Books(string t, string a, string p, double pr, int s) {
        title = t;
        author = a;
        publisher = p;
        if (pr > 0)
            price = pr;
        else
            price = 0.0;
        if (s > 0)
            stock = s;
        else
            stock = 0;
    }

    int isAvailable(string searchTitle, string searchAuthor) {
        if (title == searchTitle && author == searchAuthor)
            return 1;
        return 0;
    }

    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stock << " copies available" << endl;
    }

    void sellBook(int copies) {
        if (copies <= stock) {
            cout << "Total Cost: $" << (copies * price) << endl;
            stock -= copies;
        } else {
            cout << "Required copies not in stock." << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <title> <author> <copies>" << endl;
        return 1;
    }

    string searchTitle = argv[1];
    string searchAuthor = argv[2];
    int copies = 0;
    
    for (int i = 0; argv[3][i] != '\0'; i++) {
        if (argv[3][i] < '0' || argv[3][i] > '9') {
            cout << "Invalid number of copies!" << endl;
            return 1;
        }
        copies = copies * 10 + (argv[3][i] - '0');
    }

    Books book1("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 10.99, 5);
    Books book2("1984", "George Orwell", "Secker & Warburg", 8.99, 3);

    if (book1.isAvailable(searchTitle, searchAuthor)) {
        book1.displayDetails();
        book1.sellBook(copies);
    } else {
        if (book2.isAvailable(searchTitle, searchAuthor)) {
            book2.displayDetails();
            book2.sellBook(copies);
        } else {
            cout << "Book not available." << endl;
        }
    }

    return 0;
}


