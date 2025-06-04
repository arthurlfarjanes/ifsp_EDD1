#include <iostream>
using namespace std;

const int TAMANHO_MAX = 100;

struct Fila {
    int dados[TAMANHO_MAX];
    int inicio;
    int fim;
    int tamanho;
};

// Inicializa a fila
void inicializar(Fila& fila) {
    fila.inicio = 0;
    fila.fim = 0;
    fila.tamanho = 0;
}

// Enfileira um elemento
bool enfileirar(Fila& fila, int valor) {
    if (fila.tamanho == TAMANHO_MAX) {
        cout << "Fila cheia!" << endl;
        return false;
    }
    fila.dados[fila.fim] = valor;
    fila.fim = (fila.fim + 1) % TAMANHO_MAX;
    fila.tamanho++;
    return true;
}

// Desenfileira um elemento
int desenfileirar(Fila& fila) {
    if (fila.tamanho == 0) {
        return -1; // Fila vazia
    }
    int valor = fila.dados[fila.inicio];
    fila.inicio = (fila.inicio + 1) % TAMANHO_MAX;
    fila.tamanho--;
    return valor;
}

// Verifica se a fila esta vazia
bool filaVazia(Fila& fila) {
    return fila.tamanho == 0;
}

int main() {
    Fila senhasGeradas, senhasAtendidas;
    inicializar(senhasGeradas);
    inicializar(senhasAtendidas);

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
                enfileirar(senhasGeradas, contadorSenhas);
                cout << "Senha gerada: " << contadorSenhas << endl;
                break;
            case 2:
                if (!filaVazia(senhasGeradas)) {
                    int senha = desenfileirar(senhasGeradas);
                    enfileirar(senhasAtendidas, senha);
                    cout << "Atendendo senha: " << senha << endl;
                } else {
                    cout << "Nenhuma senha aguardando atendimento." << endl;
                }
                break;
            case 0:
                if (!filaVazia(senhasGeradas)) {
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

    return 0;
}
