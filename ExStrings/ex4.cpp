#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

string abreviacao(const string& nome) {
    return toupper(nome[0]) + string(".");
}

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
            string sobrenome = partes.back();
            cout << uppercase << sobrenome << ", ";

            for (size_t i = 0; i < partes.size() - 1; i++) {
                if (i == 0)
                    cout << partes[i] << " ";
                else
                    cout << abreviacao(partes[i]) << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
