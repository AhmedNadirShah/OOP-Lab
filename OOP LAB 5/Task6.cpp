#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 10;

struct MenuItem {
    string name, type;
    double price;
};

class CoffeeShop {
public:
    const string name;
    MenuItem menu[MAX_ITEMS];
    int menuSize;
    string orders[MAX_ITEMS];
    int orderSize;

    CoffeeShop(string n) : name(n), menuSize(0), orderSize(0) {}

    void addMenuItem(string name, string type, double price) {
        if (menuSize < MAX_ITEMS) {
            menu[menuSize].name = name;
            menu[menuSize].type = type;
            menu[menuSize].price = price;
            menuSize++;
        }
    }

    string addOrder(string item) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == item) {
                if (orderSize < MAX_ITEMS) {
                    orders[orderSize++] = item;
                    return "";
                }
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (orderSize == 0) return "All orders have been fulfilled";
        string item = orders[0];
        for (int i = 0; i < orderSize - 1; i++) {
            orders[i] = orders[i + 1];
        }
        orderSize--;
        return "The " + item + " is ready!";
    }

    void listOrders() {
        for (int i = 0; i < orderSize; i++) {
            cout << orders[i] << " ";
        }
        cout << endl;
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderSize; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (orders[i] == menu[j].name) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuSize == 0) return "";
        int cheapestIndex = 0;
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < menu[cheapestIndex].price) {
                cheapestIndex = i;
            }
        }
        return menu[cheapestIndex].name;
    }

    void drinksOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }

    void foodOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <item_to_order>\n";
        return 1;
    }

    CoffeeShop shop("Brew");
    shop.addMenuItem("Latte", "drink", 4.5);
    shop.addMenuItem("Croissant", "food", 3.5);

    string item = argv[1];
    cout << shop.addOrder(item) << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Due: $" << shop.dueAmount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "Drinks: ";
    shop.drinksOnly();

    cout << "Food: ";
    shop.foodOnly();
    return 0;
}

