#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    string msg;
    cout << "Digite uma mensagem: ";
    getline(cin, msg);

    int col = (80 - msg.length()) / 2; 
    
    gotoxy(col, 5);
    cout << msg;

    for (int i = 0; i < msg.length(); i++) {
        for (int y = 5; y <= 20; y++) {
            gotoxy(col + i, y);
            cout << msg[i];
            Sleep(30);
            if (y != 20) {
                gotoxy(col + i, y);
                cout << " ";
            }
        }
    }

    gotoxy(0, 22);
    return 0;
}
