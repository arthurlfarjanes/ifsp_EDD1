#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

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

// Função para formatar o nome para "Citação Bibliográfica"
string formatarCitaçãoBibliográfica(string nomeCompleto) {
    istringstream iss(nomeCompleto);
    string palavra, sobrenome, nomeFormatado = "";

    while (iss >> palavra) {
        sobrenome = palavra; // último será o sobrenome
    }

    // Retorna ao início para formar nome sem sobrenome
    iss.clear();
    iss.seekg(0, ios::beg);

    // Monta o restante do nome
    while (iss >> palavra) {
        if (palavra != sobrenome) {
            nomeFormatado += palavra + " ";
        }
    }

    // Remove espaço extra no final
    if (!nomeFormatado.empty()) {
        nomeFormatado.pop_back();
    }

    return sobrenome + ", " + nomeFormatado;
}

int main() {
    const int LIMITE = 10;
    Contato contatos[LIMITE];
    int somaIdades = 0;
    int maioresDeIdade = 0;

    // Cadastro dos contatos
    for (int i = 0; i < LIMITE; ++i) {
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "\nCadastro do contato #" << (i + 1) << ":\n";

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
        contatos[i] = Contato(email, nome, telefone, dtnasc);

        int idade = contatos[i].idade();
        somaIdades += idade;

        if (idade >= 18) {
            maioresDeIdade++;
        }
    }

    // Cálculo da média das idades
    double mediaIdades = static_cast<double>(somaIdades) / LIMITE;
    cout << "\nMédia das idades: " << mediaIdades << endl;

    // Listar contatos com idade maior que a média
    cout << "\nContatos com idade acima da média:\n";
    for (int i = 0; i < LIMITE; ++i) {
        if (contatos[i].idade() > mediaIdades) {
            cout << "- " << formatarCitaçãoBibliográfica(contatos[i].getNome()) << endl;
        }
    }

    // Mostrar quantidade de contatos maiores de idade
    cout << "\nQuantidade de contatos maiores de idade: " << maioresDeIdade << endl;

    // Encontrar o(s) mais velho(s)
    int maiorIdade = 0;
    for (int i = 0; i < LIMITE; ++i) {
        if (contatos[i].idade() > maiorIdade) {
            maiorIdade = contatos[i].idade();
        }
    }

    cout << "\nContato(s) mais velho(s):\n";
    for (int i = 0; i < LIMITE; ++i) {
        if (contatos[i].idade() == maiorIdade) {
            cout << "- Nome: " << formatarCitaçãoBibliográfica(contatos[i].getNome()) << endl;
            cout << "  Email: " << contatos[i].getEmail() << endl;
            cout << "  Telefone: " << contatos[i].getTelefone() << endl;
        }
    }

    return 0;
}
