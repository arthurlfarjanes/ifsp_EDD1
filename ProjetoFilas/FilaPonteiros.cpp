#include <iostream>
using namespace std;

struct No {
    int senha;
    No* proximo;
};

struct Fila {
    No* inicio;
    No* fim;
    int tamanho;
};

// Inicializa uma fila vazia
void inicializar(Fila* fila) {
    fila->inicio = nullptr;
    fila->fim = nullptr;
    fila->tamanho = 0;
}

// Enfileira um novo elemento
void enfileirar(Fila* fila, int valor) {
    No* novo = new No;
    novo->senha = valor;
    novo->proximo = nullptr;

    if (fila->fim != nullptr) {
        fila->fim->proximo = novo;
    } else {
        fila->inicio = novo;
    }

    fila->fim = novo;
    fila->tamanho++;
}

// Desenfileira e retorna o valor
int desenfileirar(Fila* fila) {
    if (fila->inicio == nullptr) {
        return -1; // Fila vazia
    }

    No* temp = fila->inicio;
    int valor = temp->senha;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == nullptr) {
        fila->fim = nullptr;
    }

    delete temp;
    fila->tamanho--;
    return valor;
}

// Verifica se a fila esta vazia
bool filaVazia(Fila* fila) {
    return fila->inicio == nullptr;
}

// Libera memoria da fila
void limparFila(Fila* fila) {
    while (!filaVazia(fila)) {
        desenfileirar(fila);
    }
}

int main() {
    Fila senhasGeradas, senhasAtendidas;
    inicializar(&senhasGeradas);
    inicializar(&senhasAtendidas);

    int opcao;
    int contadorSenhas = 0;

    do {
        cout << "\n===== MENU DE ATENDIMENTO =====\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar senha\n";
        cout << "2 - Realizar atendimento\n";
        cout << "Senhas aguardando: " << senhasGeradas.tamanho << "\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                contadorSenhas++;
                enfileirar(&senhasGeradas, contadorSenhas);
                cout << "Senha gerada: " << contadorSenhas << endl;
                break;
            case 2:
                if (!filaVazia(&senhasGeradas)) {
                    int senha = desenfileirar(&senhasGeradas);
                    enfileirar(&senhasAtendidas, senha);
                    cout << "Atendendo senha: " << senha << endl;
                } else {
                    cout << "Nenhuma senha aguardando atendimento." << endl;
                }
                break;
            case 0:
                if (!filaVazia(&senhasGeradas)) {
                    cout << "Ainda ha senhas aguardando atendimento. Nao e possivel sair.\n";
                    opcao = -1;
                } else {
                    cout << "Programa encerrado. Total de senhas atendidas: " << senhasAtendidas.tamanho << endl;
                }
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }

    } while (opcao != 0);

    limparFila(&senhasGeradas);
    limparFila(&senhasAtendidas);

    return 0;
}
