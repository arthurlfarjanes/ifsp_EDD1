#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string msg, limpa;

    cout << "Digite uma mensagem: ";
    getline(cin, msg);

    for (char c : msg) {
        if (c != ' ') {
            limpa += toupper(c);
        }
    }

    string reversa = limpa;
    reverse(reversa.begin(), reversa.end());

    if (limpa == reversa)
        cout << "É um palíndromo!" << endl;
    else
        cout << "Nao é um palíndromo." << endl;

    return 0;
}
