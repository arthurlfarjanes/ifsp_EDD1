#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Funcionario {
    int prontuario;
    string nome;
    double salario;
};

// Função para verificar se um prontuário já existe
bool prontuarioExiste(const vector<Funcionario>& funcionarios, int prontuario) {
    for (const auto& f : funcionarios) {
        if (f.prontuario == prontuario) {
            return true;
        }
    }
    return false;
}

// Função para incluir um funcionário
void incluirFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novo;
    cout << "Digite o prontuario: ";
    cin >> novo.prontuario;

    if (prontuarioExiste(funcionarios, novo.prontuario)) {
        cout << "Erro: prontuario ja cadastrado.\n";
        return;
    }

    cin.ignore(); // Limpar buffer
    cout << "Digite o nome: ";
    getline(cin, novo.nome);

    cout << "Digite o salario: ";
    cin >> novo.salario;

    funcionarios.push_back(novo);
    cout << "Funcionario cadastrado com sucesso!\n";
}

// Função para excluir um funcionário
void excluirFuncionario(vector<Funcionario>& funcionarios) {
    int pront;
    cout << "Digite o prontuario do funcionario a excluir: ";
    cin >> pront;

    for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == pront) {
            funcionarios.erase(it);
            cout << "Funcionario excluido com sucesso.\n";
            return;
        }
    }
    cout << "Funcionario nao encontrado.\n";
}

// Função para pesquisar um funcionário
void pesquisarFuncionario(const vector<Funcionario>& funcionarios) {
    int pront;
    cout << "Digite o prontuario do funcionario a pesquisar: ";
    cin >> pront;

    for (const auto& f : funcionarios) {
        if (f.prontuario == pront) {
            cout << "Nome: " << f.nome << "\n";
            cout << "Salario: R$ " << fixed << setprecision(2) << f.salario << "\n";
            return;
        }
    }
    cout << "Funcionario nao encontrado.\n";
}

// Função para listar todos os funcionários
void listarFuncionarios(const vector<Funcionario>& funcionarios) {
    double totalSalarios = 0.0;

    if (funcionarios.empty()) {
        cout << "Nenhum funcionario cadastrado.\n";
        return;
    }

    cout << "\nLista de Funcionarios:\n";
    for (const auto& f : funcionarios) {
        cout << "--------------------------\n";
        cout << "Prontuario: " << f.prontuario << "\n";
        cout << "Nome: " << f.nome << "\n";
        cout << "Salario: R$ " << fixed << setprecision(2) << f.salario << "\n";
        totalSalarios += f.salario;
    }
    cout << "--------------------------\n";
    cout << "Total de salarios: R$ " << fixed << setprecision(2) << totalSalarios << "\n";
}

int main() {
    vector<Funcionario> funcionarios;
    int opcao;

    do {
        cout << "\nMenu:\n";
        cout << "0 - Sair\n";
        cout << "1 - Incluir funcionario\n";
        cout << "2 - Excluir funcionario\n";
        cout << "3 - Pesquisar funcionario\n";
        cout << "4 - Listar funcionarios\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Saindo do programa...\n";
                break;
            case 1:
                incluirFuncionario(funcionarios);
                break;
            case 2:
                excluirFuncionario(funcionarios);
                break;
            case 3:
                pesquisarFuncionario(funcionarios);
                break;
            case 4:
                listarFuncionarios(funcionarios);
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}