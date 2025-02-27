#include <iostream>
#include <windows.h>

using namespace std;

class Blender {
public:
    void startBlending() {
        DWORD startTime = GetTickCount();
        while (true) {
            DWORD currentTime = GetTickCount();
            DWORD elapsedTime = (currentTime - startTime) / 1000;
            if (elapsedTime >= 4) break;
            cout << "Blending...\n";
            Sleep(500);
        }
        cout << "Blending done!\n";
    }
};

class Grinder {
public:
    void startGrinding() {
        cout << "Grinding started...\n";
        Sleep(5000);
        cout << "Grinding done!\n";
    }
};

class JuiceMachine {
    Blender blender;
    Grinder grinder;
public:
    void blend() { blender.startBlending(); }
    void grind() { grinder.startGrinding(); }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <blend|grind>\n";
        return 1;
    }

    JuiceMachine machine;
    string input = argv[1];

    if (input == "blend") {
        cout << "Blending juice...\n";
        machine.blend();
    } else if (input == "grind") {
        cout << "Grinding juice...\n";
        machine.grind();
    } else {
        cout << "Invalid input. Use 'blend' or 'grind'.\n";
    }

    return 0;
}


