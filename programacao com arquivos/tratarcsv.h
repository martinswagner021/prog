#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector> 
#include <map>

using namespace std;

struct Transacao {
    int dia, mes, ano;
    int agencia_origem, conta_origem;
    double valor;
    int agencia_destino, conta_destino;
};

class movimentacao_consolidada {
    public:
        int agencia, conta;
        double subtotal_dinheiro_vivo;
        double subtotal_transacoes_eletronicas;
        int total_transacoes;

        movimentacao_consolidada(){
            this->agencia = agencia;
            this->conta = conta;
            this->subtotal_dinheiro_vivo = 0.0;
            this->subtotal_transacoes_eletronicas = 0.0;
            this->total_transacoes = 0;
        }
        movimentacao_consolidada(int agencia, int conta){
            this->agencia = agencia;
            this->conta = conta;
            this->subtotal_dinheiro_vivo = 0.0;
            this->subtotal_transacoes_eletronicas = 0.0;
            this->total_transacoes = 0;
        }
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

map<pair<int, int>, movimentacao_consolidada> consolidarTransacoes(const vector<Transacao> &transacoes, int mes, int ano){
    map<pair<int, int>, movimentacao_consolidada> consolidados;

    for(const auto &transacao : transacoes){
        if (transacao.mes == mes && transacao.ano == ano) {
            pair<int, int> chave_origem(transacao.agencia_origem, transacao.conta_origem);
            pair<int, int> chave_destino(transacao.agencia_destino, transacao.conta_destino);
            
            // se nao houver movimentacao na conta, inicializa uma nova
            if (consolidados.find(chave_origem) == consolidados.end())
                consolidados.emplace(chave_origem, movimentacao_consolidada(transacao.agencia_origem, transacao.conta_origem));

            // movimentacao digital
            if (transacao.agencia_destino != 0 || transacao.conta_destino != 0) {
                // se destino nao existir inicializa uma nova tambem
                if (consolidados.find(chave_destino) == consolidados.end())
                    consolidados.emplace(chave_destino, movimentacao_consolidada(transacao.agencia_destino, transacao.conta_destino));

                consolidados[chave_destino].subtotal_transacoes_eletronicas += transacao.valor;
                consolidados[chave_destino].total_transacoes++;
                consolidados[chave_origem].subtotal_transacoes_eletronicas += transacao.valor;
            }
            // movimentacao em dinheiro vivo
            else consolidados[chave_origem].subtotal_dinheiro_vivo += transacao.valor;

            consolidados[chave_origem].total_transacoes++;
        }
    }

    return consolidados;
}

string name_bin(int mes, int ano) {
    string nome_arquivo = "consolidadas";
    nome_arquivo.append((mes<10) ? "0" : "");
    nome_arquivo.append(to_string(mes));
    nome_arquivo.append(to_string(ano));
    nome_arquivo.append(".bin");
    return nome_arquivo;
}

void salvarConsolidadoBinario(const map<pair<int, int>, movimentacao_consolidada>& consolidados, int mes, int ano){
    string nome_arquivo = name_bin(mes, ano);
    ofstream arquivo(nome_arquivo, ios::binary);
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo binário para escrita." << endl;
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
        cout << "Erro ao abrir o arquivo binário para carregar." << endl;
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

void atualizarLog(const string& mensagem) {
    ofstream log("log.txt", ios::app);
    if (log.is_open()) {
        log << mensagem << " em " << __DATE__ << " " << __TIME__ << endl;
        log.close();
    }
}

map<pair<int, int>, movimentacao_consolidada> getConsolidados(int mes, int ano){
    string nome_arquivo = name_bin(mes, ano);
    map<pair<int, int>, movimentacao_consolidada> consolidados;

    ifstream arquivo_bin(nome_arquivo);
    if (arquivo_bin.is_open()) {
        arquivo_bin.close();
        consolidados = carregarConsolidadoBinario(nome_arquivo);
    }else {
        vector<Transacao> transacoes = ler_transacoesCSV("transacoes.csv");
        consolidados = consolidarTransacoes(transacoes, mes, ano);
        salvarConsolidadoBinario(consolidados, mes, ano);
        atualizarLog("Movimetação consolidada calculada para " + to_string(mes) + "/" + to_string(ano));
    }
    return consolidados;
}

void showMovimentacoes(movimentacao_consolidada consolidado){
    // cout << "Agência: " << consolidado.agencia << " Conta: " << consolidado.conta << endl;
    // cout << "Subtotal Dinheiro Vivo: " <<  consolidado.subtotal_dinheiro_vivo << endl;
    // cout << "Subtotal Transações Eletronicas: " << consolidado.subtotal_transacoes_eletronicas << endl;
    // cout << "Total Transações: " << consolidado.total_transacoes << endl;
    cout << left << setw(10) << "Agência"
        << setw(10) << "Conta"
        << setw(20) << "Dinheiro Vivo"
        << setw(30) << "Transações Eletrônicas"
        << setw(20) << "Total Transações"
        << endl;
    cout << left << setw(10) << consolidado.agencia
        << setw(10) << consolidado.conta
        << setw(20) << consolidado.subtotal_dinheiro_vivo
        << setw(30) << consolidado.subtotal_transacoes_eletronicas
        << setw(20) << consolidado.total_transacoes
        << endl;
}

void consultarMovimentação(int mes, int ano){
    map<pair<int, int>, movimentacao_consolidada> consolidados;

    consolidados = getConsolidados(mes, ano);

    for (const auto& [chave, consolidado] : consolidados) showMovimentacoes(consolidado);
}

void filtrarMovimentacao(int mes, int ano, double x, double y, bool tipoE) {
    map<pair<int, int>, movimentacao_consolidada> consolidados;

    // Verifica se o arquivo binário já existe
    consolidados = getConsolidados(mes, ano);

    // Filtragem
    vector<movimentacao_consolidada> resultado_filtrado;
    for (const auto& [chave, consolidado] : consolidados) {
        if (tipoE) {
            if (consolidado.subtotal_dinheiro_vivo >= x && consolidado.subtotal_transacoes_eletronicas >= y) {
                resultado_filtrado.push_back(consolidado);
            }
        } else {
            if (consolidado.subtotal_dinheiro_vivo >= x || consolidado.subtotal_transacoes_eletronicas >= y) {
                resultado_filtrado.push_back(consolidado);
            }
        }
    }

    // Mostra o resultado da filtragem
    for(const auto& consolidado: resultado_filtrado){
        showMovimentacoes(consolidado);
    }

    // Registrar log
    atualizarLog("Filtragem realizada em " + to_string(mes) + "/" + to_string(ano) + " com X=" + to_string(x) + ", Y=" + to_string(y) + ", Tipo=" + (tipoE ? "E" : "OU") + ". Registros mostrados: " + to_string(resultado_filtrado.size()));
}