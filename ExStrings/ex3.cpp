#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream arquivo("nomes.txt");
    string linha;

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        vector<string> partes;
        string nome;

        while (ss >> nome)
            partes.push_back(nome);

        if (partes.size() >= 2) {
            cout << partes.back() << ", ";
            for (size_t i = 0; i < partes.size() - 1; i++)
                cout << partes[i] << " ";
            cout << endl;
        }
    }

    return 0;
}
