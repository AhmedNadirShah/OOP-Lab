#include <iostream>

using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p) {
        name = n;
        type = t;
        if (p > 0)
            price = p;
        else
            price = 0.0;
    }
};

class CoffeeShop {
public:
    string name;
    MenuItem menu[5]; // Fixed-size menu
    string orders[10]; // Fixed-size order list
    int menuSize;
    int orderCount;

    CoffeeShop(string shopName, MenuItem m[], int size) {
        name = shopName;
        menuSize = size;
        orderCount = 0;
        for (int i = 0; i < size; i++)
            menu[i] = m[i];
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                if (orderCount < 10) {
                    orders[orderCount] = itemName;
                    orderCount++;
                    return "Order added!";
                }
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 0; i < orderCount - 1; i++)
                orders[i] = orders[i + 1];
            orderCount--;
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "[]" << endl;
            return;
        }
        cout << "[ ";
        for (int i = 0; i < orderCount; i++)
            cout << orders[i] << " ";
        cout << "]" << endl;
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (orders[i] == menu[j].name)
                    total += menu[j].price;
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuSize == 0)
            return "No items on menu";

        int minIndex = 0;
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < menu[minIndex].price)
                minIndex = i;
        }
        return menu[minIndex].name;
    }

    void drinksOnly() {
        cout << "[ ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink")
                cout << menu[i].name << " ";
        }
        cout << "]" << endl;
    }

    void foodOnly() {
        cout << "[ ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food")
                cout << menu[i].name << " ";
        }
        cout << "]" << endl;
    }
};

int main(int argc, char* argv[]) {
    MenuItem menu[] = {
        MenuItem("Coffee", "drink", 2.5),
        MenuItem("Tea", "drink", 1.8),
        MenuItem("Sandwich", "food", 5.0),
        MenuItem("Cake", "food", 3.5),
        MenuItem("Juice", "drink", 2.0)
    };

    CoffeeShop shop("Café Bliss", menu, 5);

    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <command> [item]" << endl;
        return 1;
    }

    string command = argv[1];

    if (command == "order" && argc == 3) {
        string item = argv[2];
        cout << shop.addOrder(item) << endl;
    } else if (command == "fulfill") {
        cout << shop.fulfillOrder() << endl;
    } else if (command == "listOrders") {
        shop.listOrders();
    } else if (command == "dueAmount") {
        cout << "Total Due: $" << shop.dueAmount() << endl;
    } else if (command == "cheapest") {
        cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    } else if (command == "drinks") {
        cout << "Drinks: ";
        shop.drinksOnly();
    } else if (command == "food") {
        cout << "Food: ";
        shop.foodOnly();
    } else {
        cout << "Invalid command" << endl;
    }

    return 0;
}

