#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Logger {
private:
    string base;
    int index;
    ofstream file;
    const long maxSize = 1048576;

    string intToStr(int num) {
        if (num == 0) return "0";
        string str = "";
        while (num > 0) {
            char digit = '0' + (num % 10);
            str = digit + str;
            num /= 10;
        }
        return str;
    }

    string name(int i) {
        return base + intToStr(i) + ".txt";
    }

    long size(const string& fname) {
        ifstream f(fname.c_str(), ios::binary | ios::ate);
        if (!f.is_open()) return 0;
        return f.tellg();
    }

    void open() {
        file.open(name(index).c_str(), ios::app);
    }

    void rotate() {
        if (size(name(index)) >= maxSize) {
            file.close();
            index++;
            open();
        }
    }

public:
    Logger(const string& baseName) {
        base = baseName;
        index = 1;
        open();
    }

    ~Logger() {
        if (file.is_open()) file.close();
    }

    void log(const string& msg) {
        rotate();
        file << msg << endl;
    }
};

int main() {
    Logger logger("log");

    for (int i = 0; i < 200000; ++i) {
        string entry = "Entry ";
        int num = i;
        if (num == 0) {
            entry += "0";
        } else {
            string digits = "";
            while (num > 0) {
                char d = '0' + (num % 10);
                digits = d + digits;
                num /= 10;
            }
            entry += digits;
        }

        logger.log(entry);
    }

    cout << "Logging done" << endl;
    return 0;
}

