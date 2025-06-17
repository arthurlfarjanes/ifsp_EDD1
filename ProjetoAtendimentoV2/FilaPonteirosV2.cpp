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

struct Guiche {
    int id;
    Fila senhasAtendidas;
    Guiche* proximo;
};

struct ListaGuiches {
    Guiche* inicio;
    int tamanho;
};

void inicializar(Fila* fila) {
    fila->inicio = nullptr;
    fila->fim = nullptr;
    fila->tamanho = 0;
}

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

bool filaVazia(Fila* fila) {
    return fila->inicio == nullptr;
}

void limparFila(Fila* fila) {
    while (!filaVazia(fila)) {
        desenfileirar(fila);
    }
}

void inicializarListaGuiches(ListaGuiches* lista) {
    lista->inicio = nullptr;
    lista->tamanho = 0;
}

void adicionarGuiche(ListaGuiches* lista, int idGuiche) {
    Guiche* novoGuiche = new Guiche;
    novoGuiche->id = idGuiche;
    inicializar(&novoGuiche->senhasAtendidas);
    novoGuiche->proximo = nullptr;

    if (lista->inicio == nullptr) {
        lista->inicio = novoGuiche;
    } else {
        Guiche* atual = lista->inicio;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novoGuiche;
    }
    lista->tamanho++;
    cout << "Guiche " << idGuiche << " aberto com sucesso!" << endl;
}

Guiche* encontrarGuiche(ListaGuiches* lista, int idGuiche) {
    Guiche* atual = lista->inicio;
    while (atual != nullptr) {
        if (atual->id == idGuiche) {
            return atual;
        }
        atual = atual->proximo;
    }
    return nullptr;
}

void limparGuiches(ListaGuiches* lista) {
    Guiche* atual = lista->inicio;
    while (atual != nullptr) {
        Guiche* proximo = atual->proximo;
        limparFila(&atual->senhasAtendidas);
        delete atual;
        atual = proximo;
    }
    lista->inicio = nullptr;
    lista->tamanho = 0;
}

int main() {
    Fila senhasGeradas;
    inicializar(&senhasGeradas);

    ListaGuiches guichesAbertos;
    inicializarListaGuiches(&guichesAbertos);

    int opcao;
    int contadorSenhas = 0;
    int proximoIdGuiche = 1;

    do {
        cout << "\n===== MENU DE ATENDIMENTO =====\n";
        cout << "Senhas aguardando: " << senhasGeradas.tamanho << "\n";
        cout << "Guiches abertos: " << guichesAbertos.tamanho << "\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar senha\n";
        cout << "2 - Abrir guichê\n";
        cout << "3 - Realizar atendimento\n";
        cout << "4 - Listar senhas atendidas\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                contadorSenhas++;
                enfileirar(&senhasGeradas, contadorSenhas);
                cout << "Senha gerada: " << contadorSenhas << endl;
                break;
            case 2:
                adicionarGuiche(&guichesAbertos, proximoIdGuiche);
                proximoIdGuiche++;
                break;
            case 3:
            {
                if (filaVazia(&senhasGeradas)) {
                    cout << "Nenhuma senha aguardando atendimento." << endl;
                    break;
                }
                if (guichesAbertos.tamanho == 0) {
                    cout << "Nenhum guiche aberto para atendimento." << endl;
                    break;
                }

                int idGuicheAtendimento;
                cout << "Digite o ID do guiche que ira realizar o atendimento: ";
                cin >> idGuicheAtendimento;

                Guiche* guicheDaVez = encontrarGuiche(&guichesAbertos, idGuicheAtendimento);
                if (guicheDaVez != nullptr) {
                    int senhaAtendida = desenfileirar(&senhasGeradas);
                    enfileirar(&guicheDaVez->senhasAtendidas, senhaAtendida);
                    cout << "Guiche com ID " << idGuicheAtendimento << " atendeu a senha " << senhaAtendida << endl;
                } else {
                    cout << "Guiche com ID " << idGuicheAtendimento << " nao encontrado." << endl;
                }
                break;
            }
            case 4:
            {
                if (guichesAbertos.tamanho == 0) {
                    cout << "Nenhum guiche aberto para atendimento." << endl;
                    break;
                }
                int idGuicheListar;
                cout << "Digite o ID do guiche para listar as senhas atendidas: ";
                cin >> idGuicheListar;

                Guiche* guicheParaListar = encontrarGuiche(&guichesAbertos, idGuicheListar);
                if (guicheParaListar != nullptr) {
                    if (filaVazia(&guicheParaListar->senhasAtendidas)) {
                        cout << "Guiche " << idGuicheListar << " ainda nao atendeu nenhuma senha." << endl;
                    } else {
                        cout << "Senhas atendidas pelo guiche " << idGuicheListar << ":\n";
                        No* atual = guicheParaListar->senhasAtendidas.inicio;
                        while (atual != nullptr) {
                            cout << "- Senha: " << atual->senha << endl;
                            atual = atual->proximo;
                        }
                    }
                } else {
                    cout << "Guiche com ID " << idGuicheListar << " nao encontrado." << endl;
                }
                break;
            }
            case 0:
                if (!filaVazia(&senhasGeradas)) {
                    cout << "Ainda ha senhas aguardando atendimento. Nao e possivel sair.\n";
                    opcao = -1;
                } else {
                    int totalSenhasAtendidas = 0;
                    Guiche* atualGuiche = guichesAbertos.inicio;
                    while (atualGuiche != nullptr) {
                        totalSenhasAtendidas += atualGuiche->senhasAtendidas.tamanho;
                        atualGuiche = atualGuiche->proximo;
                    }
                    cout << "Programa encerrado. Total de senhas atendidas: " << totalSenhasAtendidas << endl;
                }
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }

    } while (opcao != 0);

    limparFila(&senhasGeradas);
    limparGuiches(&guichesAbertos);

    return 0;
}