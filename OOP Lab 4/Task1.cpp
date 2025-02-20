#include <iostream>

using namespace std;

class Circle {
public:
    double radius;

    Circle(double r) {
        this->radius = r;
    }
};

double getArea(Circle c) {
    return 3.14159 * c.radius * c.radius;
}

double getPerimeter(Circle c) {
    return 2 * 3.14159 * c.radius;
}

int main(int argc,char *argv[]) {

double r=stod(argv[1]);

    Circle c(r);
    cout << "Area: " << getArea(c) << endl;
    cout << "Perimeter: " << getPerimeter(c) << endl;

    return 0;
}




