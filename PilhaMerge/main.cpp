#include <iostream>
using namespace std;

const int MAX = 30;

// ------------------------
// Pilha com lista encadeada
// ------------------------
struct Node {
    int valor;
    Node* proximo;
};

class PilhaLista {
private:
    Node* topo;

public:
    PilhaLista() {
        topo = nullptr;
    }

    ~PilhaLista() {
        while (!vazia()) {
            desempilhar();
        }
    }

    void empilhar(int valor) {
        Node* novo = new Node{valor, topo};
        topo = novo;
    }

    int desempilhar() {
        if (vazia()) {
            cout << "Pilha vazia!\n";
            return -1;
        }
        int valor = topo->valor;
        Node* temp = topo;
        topo = topo->proximo;
        delete temp;
        return valor;
    }

    bool vazia() {
        return topo == nullptr;
    }
};

// ------------------------
// Pilha com vetor
// ------------------------
class PilhaVetor {
private:
    int dados[MAX];
    int topo;

public:
    PilhaVetor() {
        topo = -1;
    }

    void empilhar(int valor) {
        if (topo >= MAX - 1) {
            cout << "Pilha cheia!\n";
            return;
        }
        dados[++topo] = valor;
    }

    int desempilhar() {
        if (vazia()) {
            cout << "Pilha vazia!\n";
            return -1;
        }
        return dados[topo--];
    }

    bool vazia() {
        return topo == -1;
    }
};

// ------------------------
// Função principal
// ------------------------
int main() {
    int numeros[30];
    int anterior = -1;

    cout << "Digite 30 numeros inteiros em ordem crescente:\n";
    for (int i = 0; i < 30; i++) {
        int num;
        do {
            cout << "Numero " << i + 1 << ": ";
            cin >> num;
            if (i > 0 && num <= anterior) {
                cout << "Erro: o numero deve ser maior que o anterior (" << anterior << ").\n";
            }
        } while (i > 0 && num <= anterior);

        numeros[i] = num;
        anterior = num;
    }

    // Pilhas: pares com lista, ímpares com vetor
    PilhaLista pilhaPar;
    PilhaVetor pilhaImpar;

    // Empilhar os números nas pilhas correspondentes
    for (int i = 0; i < 30; i++) {
        if (numeros[i] % 2 == 0) {
            pilhaPar.empilhar(numeros[i]);
        } else {
            pilhaImpar.empilhar(numeros[i]);
        }
    }

    // Mostrar os valores em ordem decrescente (desempilhando)
    cout << "\n--- Valores pares (desempilhando lista encadeada): ---\n";
    while (!pilhaPar.vazia()) {
        cout << pilhaPar.desempilhar() << " ";
    }

    cout << "\n\n--- Valores impares (desempilhando vetor): ---\n";
    while (!pilhaImpar.vazia()) {
        cout << pilhaImpar.desempilhar() << " ";
    }

    cout << "\n";
    return 0;
}
