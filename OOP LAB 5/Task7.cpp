#include <iostream>

using namespace std;

class Student {
public:
    const int roll_no;
    Student(int roll) : roll_no(roll) {}
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <roll_number>\n";
        return 1;
    }

    int roll = atoi(argv[1]);
    Student student(roll);
    cout << "Roll No: " << student.roll_no << endl;
}

