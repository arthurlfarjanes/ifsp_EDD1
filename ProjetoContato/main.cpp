#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Classe Data
class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data() : dia(1), mes(1), ano(2000) {}

    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }
};

// Classe Contato
class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() : email(""), nome(""), telefone(""), dtnasc() {}

    Contato(string e, string n, string t, Data d)
        : email(e), nome(n), telefone(t), dtnasc(d) {}

    string getEmail() const { return email; }
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }
    Data getDataNascimento() const { return dtnasc; }

    void setEmail(const string& e) { email = e; }
    void setNome(const string& n) { nome = n; }
    void setTelefone(const string& t) { telefone = t; }
    void setDataNascimento(const Data& d) { dtnasc = d; }

    int idade() const {
        time_t t = time(0);
        struct tm* now = localtime(&t);
        int anoAtual = now->tm_year + 1900;
        return anoAtual - dtnasc.getAno();
    }
};

int main() {
    const int LIMITE = 5;
    Contato contatos[LIMITE];
    int cadastrados = 0;
    char resposta;

    do {
        if (cadastrados >= LIMITE) {
            cout << "\nLimite de contatos atingido.\n";
            break;
        }

        string nome, email, telefone;
        int dia, mes, ano;

        cout << "\nCadastro do contato #" << (cadastrados + 1) << ":\n";

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Email: ";
        getline(cin, email);

        cout << "Telefone: ";
        getline(cin, telefone);

        cout << "Data de Nascimento (dia mes ano): ";
        cin >> dia >> mes >> ano;
        cin.ignore(); // Limpa o buffer

        Data dtnasc(dia, mes, ano);
        contatos[cadastrados] = Contato(email, nome, telefone, dtnasc);

        cadastrados++;

        if (cadastrados < LIMITE) {
            cout << "\nDeseja cadastrar outro contato? (s/n): ";
            cin >> resposta;
            cin.ignore(); // Limpa o buffer
            resposta = tolower(resposta);
        } else {
            // Limite atingido, nem pergunta
            resposta = 'n';
        }

    } while (resposta == 's');

    // Exibir contatos cadastrados
    cout << "\n--- Contatos Cadastrados ---\n";
    for (int i = 0; i < cadastrados; ++i) {
        cout << "\nContato #" << (i + 1) << ":\n";
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl;
    }

    return 0;
}

