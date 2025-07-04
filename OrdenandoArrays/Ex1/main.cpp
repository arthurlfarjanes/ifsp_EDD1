#include <iostream>
#include <algorithm>
#include <vector>

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
}

void ordenacaoPorContagem(int vetor[], int tamanho) {
    if (tamanho <= 1) {
        return;
    }

    int maiorValor = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maiorValor) {
            maiorValor = vetor[i];
        }
    }

    std::vector<int> contagem(maiorValor + 1, 0);

    for (int i = 0; i < tamanho; i++) {
        contagem[vetor[i]]++;
    }

    for (int i = 1; i <= maiorValor; i++) {
        contagem[i] += contagem[i - 1];
    }

    std::vector<int> saida(tamanho);
    for (int i = tamanho - 1; i >= 0; i--) {
        saida[contagem[vetor[i]] - 1] = vetor[i];
        contagem[vetor[i]]--;
    }

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = saida[i];
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int dados[] = {4, 2, 2, 8, 3, 3, 1, 0, 9, 5, 4, 7};
    int tamanho = sizeof(dados) / sizeof(dados[0]);

    std::cout << "Vetor original: ";
    imprimirVetor(dados, tamanho);

    ordenacaoPorContagem(dados, tamanho);

    std::cout << "Vetor ordenado: ";
    imprimirVetor(dados, tamanho);

    return 0;
}