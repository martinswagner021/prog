#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iterator>
#include <locale>
#include <sstream>
#include <utility>
#include <vector> 
#include <string>
#include <map>
#include <ctime>

using namespace std;

struct Transacao {
    int dia, mes, ano;
    int agencia_origem, conta_origem;
    double valor;
    int agencia_destino, conta_destino;
};

struct movimentacao_consolidada {
    int agencia, conta;
    double subtotal_dinheiro_vivo = 0.0;
    double subtotal_transacoes_eletronicas = 0.0;
    int total_transacoes = 0;
};

vector<Transacao> ler_transacoesCSV(const string &nome_arquivo) {
    vector<Transacao> transacoes;
    ifstream arquivo(nome_arquivo);
    string linha;

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo CSV." << endl;
        return transacoes;
    }

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string campo;
        Transacao transacao;
        
        getline(ss, campo, ','); transacao.dia = stoi(campo);
        getline(ss, campo, ','); transacao.mes= stoi(campo);
        getline(ss, campo, ','); transacao.ano = stoi(campo);
        getline(ss, campo, ','); transacao.agencia_origem = stoi(campo);
        getline(ss, campo, ','); transacao.conta_origem = stoi(campo);
        getline(ss, campo, ','); transacao.valor = stod(campo);
        getline(ss, campo, ','); transacao.agencia_destino = campo.empty() ? 0 : stoi(campo);
        getline(ss, campo, ','); transacao.conta_destino = campo.length() <= 1 ? 0 : stoi(campo);
        
        transacoes.push_back(transacao);
    }

    arquivo.close();
    return transacoes;
}

/*função recebe o vetor de transaçoes lidas na função anterior, mes & ano, um map de chaves agencia, conta guarda as movimentações consolidadas
checka-se se mes e ano de cada transação é o mes e ano passado no parâmetro, crias-se dois pair para 
chave origem e chave destino, se não acharmos a chave origem no map de consolidados inicia-se uma nova
movimentação consolidada, se a agencia/conta destino for != 0 a conta teve movimentação digital
então se inicia uma nova movimentação consolidada depois add a transação para o subtotal de transaçoes 
eletronicas OU se a agencia conta/destino for = 0 então é só add o valor para subtotal dinheiro vivo
add total de transações e retorna o map consolidados */

map<pair<int, int>, movimentacao_consolidada> consolidarTransacoes(const vector<Transacao>& transacoes, int mes, int ano){
    map<pair<int, int>, movimentacao_consolidada> consolidados;

    for ( const auto& transacao : transacoes) {
        if (transacao.mes == mes && transacao.ano == ano) {
        pair<int, int> chave_origem(transacao.agencia_origem, transacao.conta_origem);
        pair<int, int> chave_destino(transacao.agencia_destino, transacao.conta_destino);
        
    if (consolidados.find(chave_origem) == consolidados.end()) {
            consolidados[chave_origem] = movimentacao_consolidada{
            transacao.agencia_origem,
            transacao.conta_origem,
            0.0, 0.0, 0
            }; 
        }

        
        if (transacao.agencia_destino != 0 || transacao.conta_destino != 0) {
            if (consolidados.find(chave_destino) == consolidados.end()) {
            consolidados[chave_destino] = movimentacao_consolidada{
                transacao.agencia_destino,
                transacao.conta_destino,
                0.0, 0.0, 0
            };
            }
            consolidados[chave_destino].subtotal_transacoes_eletronicas += transacao.valor;
        }else {
            consolidados[chave_origem].subtotal_dinheiro_vivo += transacao.valor;
        }
        consolidados[chave_origem].total_transacoes++;
        }
    }
    return consolidados;
}

void salvarConsolidadoBinario(const string& nome_arquivo, const map<pair<int, int>, movimentacao_consolidada>& consolidados){
    ofstream arquivo(nome_arquivo, ios::binary);
    if(!arquivo.is_open()){
        cerr << "Erro ao abrir o arquivo binário para escrita." << endl;
        return;
    }

    for(const auto& [chave, consolidado] : consolidados){
        arquivo.write(reinterpret_cast<const char*>(&consolidado), sizeof(movimentacao_consolidada));
    }
    arquivo.close();
}

map<pair<int, int>, movimentacao_consolidada> carregarConsolidadoBinario(const string& nome_arquivo){
    map<pair<int, int>, movimentacao_consolidada> consolidados;
    ifstream arquivo(nome_arquivo, ios::binary);

    if(!arquivo.is_open()){
        cerr << "Erro ao abrir o arquivo binário para carregar." << endl;
        return consolidados;
    }
    movimentacao_consolidada consolidado;
    while(arquivo.read(reinterpret_cast<char*>(&consolidado), sizeof(movimentacao_consolidada))){
        pair<int, int> chave  = {consolidado.agencia, consolidado.conta};
        consolidados[chave] = consolidado;
    }

    arquivo.close();
    return consolidados;
}



int main(){
    vector<Transacao> t = ler_transacoesCSV("transacoes.csv");

    int N = 3;
    Transacao p = t[N];
    cout << p.dia << " " << p.mes << " " << p.ano << " " << p.agencia_origem << " " << p.conta_origem << " " << p.valor << " " << p.agencia_destino << " " << p.conta_destino << " " << endl;
}