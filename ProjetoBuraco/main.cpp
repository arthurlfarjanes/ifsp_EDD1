#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Função para gerar a representação das cartas no formato N-99-B
string gerarCarta(int naipe, int numero, int baralho) {
    string carta = to_string(naipe) + "-" + (numero < 10 ? "0" : "") + to_string(numero) + "-" + to_string(baralho);
    return carta;
}

// Função para embaralhar o baralho
void embaralharBaralho(vector<string>& baralho) {
    random_shuffle(baralho.begin(), baralho.end());
}

// Função para distribuir as cartas entre os jogadores
void distribuirCartas(vector<string>& baralho, vector<vector<string>>& mao) {
    int cartaIndex = 0;
    for (int j = 0; j < 4; ++j) {
        for (int c = 0; c < 11; ++c) {
            mao[j][c] = baralho[cartaIndex++];
        }
    }
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios

    // Representação do baralho (2 baralhos de 52 cartas)
    vector<string> baralho;

    // Gerando as cartas para 2 baralhos
    for (int b = 1; b <= 2; ++b) {
        for (int n = 1; n <= 4; ++n) { // 1: Copas, 2: Paus, 3: Ouro, 4: Espada
            for (int num = 1; num <= 13; ++num) { // 1 a 13 para Ás até Rei
                baralho.push_back(gerarCarta(n, num, b));
            }
        }
    }

    // Embaralhando o baralho
    embaralharBaralho(baralho);

    // Mãos dos jogadores (4 jogadores, 11 cartas cada)
    vector<vector<string>> mao(4, vector<string>(11));

    // Distribuindo as cartas para os jogadores
    distribuirCartas(baralho, mao);

    // Exibindo as mãos de cada jogador
    for (int j = 0; j < 4; ++j) {
        cout << "Mão do Jogador " << j + 1 << ": ";
        for (int c = 0; c < 11; ++c) {
            cout << mao[j][c] << " ";
        }
        cout << endl;
    }

    return 0;
}
