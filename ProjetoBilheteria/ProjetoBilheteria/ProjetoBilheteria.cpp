#include <iostream>
#include <iomanip>

using namespace std;

const int FILEIRAS = 15;
const int POLTRONAS = 40;
const double PRECO_1_5 = 50.0;
const double PRECO_6_10 = 30.0;
const double PRECO_11_15 = 15.0;

void exibirMapa(char teatro[FILEIRAS][POLTRONAS]) {
    cout << "\
Mapa de Ocupacao:\n";
    for (int i = 0; i < FILEIRAS; i++) {
        cout << "Fileira " << setw(2) << (i + 1) << ": ";
        for (int j = 0; j < POLTRONAS; j++) {
            cout << teatro[i][j] << " ";
        }
        cout << endl;
    }
}

double calcularFaturamento(char teatro[FILEIRAS][POLTRONAS]) {
    int ocupados = 0;
    double faturamento = 0;
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            if (teatro[i][j] == '#') {
                ocupados++;
                if (i < 5)
                    faturamento += PRECO_1_5;
                else if (i < 10)
                    faturamento += PRECO_6_10;
                else
                    faturamento += PRECO_11_15;
            }
        }
    }
    cout << "\nQtde de lugares ocupados: " << ocupados << endl;
    cout << "Valor da bilheteria: R$ " << fixed << setprecision(2) << faturamento << endl;
    return faturamento;
}

void reservarPoltrona(char teatro[FILEIRAS][POLTRONAS]) {
    int fileira, poltrona;
    cout << "Digite o numero da fileira (1-15): ";
    cin >> fileira;
    cout << "Digite o numero da poltrona (1-40): ";
    cin >> poltrona;

    if (fileira < 1 || fileira > FILEIRAS || poltrona < 1 || poltrona > POLTRONAS) {
        cout << "\nErro: Fileira ou poltrona invalida!\n";
        return;
    }

    if (teatro[fileira - 1][poltrona - 1] == '#') {
        cout << "\nErro: Esse assento ja esta ocupado!\n";
    }
    else {
        teatro[fileira - 1][poltrona - 1] = '#';
        cout << "\nReserva efetuada com sucesso!\n";
    }
}

int main() {
    char teatro[FILEIRAS][POLTRONAS];
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            teatro[i][j] = '.'; // Inicializa todas as poltronas como vagas
        }
    }

    int opcao;
    do {
        cout << "\nMenu:\n";
        cout << "0 - Finalizar\n";
        cout << "1 - Reservar Poltrona\n";
        cout << "2 - Mapa de Ocupacao\n";
        cout << "3 - Faturamento\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            reservarPoltrona(teatro);
            break;
        case 2:
            exibirMapa(teatro);
            break;
        case 3:
            calcularFaturamento(teatro);
            break;
        case 0:
            cout << "Encerrando o sistema...\n";
            break;
        default:
            cout << "\nOpcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}