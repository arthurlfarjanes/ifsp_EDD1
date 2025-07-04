#include <iostream>
#include <clocale>

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
}

void trocar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int particionar(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            trocar(vetor[i], vetor[j]);
        }
    }
    trocar(vetor[i + 1], vetor[alto]);
    return (i + 1);
}

void ordenacaoRapida(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int indicePivo = particionar(vetor, baixo, alto);

        ordenacaoRapida(vetor, baixo, indicePivo - 1);
        ordenacaoRapida(vetor, indicePivo + 1, alto);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int dados[] = {10, 7, 8, 9, 1, 5, 2, 4, 3, 6, 2};
    int tamanho = sizeof(dados) / sizeof(dados[0]);

    std::cout << "Vetor original: ";
    imprimirVetor(dados, tamanho);

    ordenacaoRapida(dados, 0, tamanho - 1);

    std::cout << "Vetor ordenado (Quick Sort): ";
    imprimirVetor(dados, tamanho);

    return 0;
}