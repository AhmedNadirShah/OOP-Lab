#include <iostream>
#include <string>
using namespace std;

class BadTypeException {
public:
    string message;
    BadTypeException(string msg) : message(msg) {}
};

template <typename T>
class TypeSafeContainer {
    T item;
    bool isSet;
public:
    TypeSafeContainer() : isSet(false) {}

    void store(T value) {
        item = value;
        isSet = true;
    }

    T get() {
        if (!isSet) {
            throw BadTypeException("No value stored.");
        }
        return item;
    }
};

int main() {
    TypeSafeContainer<float> container;

    try {
        container.store(5);
        cout << "Stored: " << container.get() << endl;
    } 
	catch (BadTypeException& e) {
        cout << "Exception: " << e.message << endl;
    }

    return 0;
}

