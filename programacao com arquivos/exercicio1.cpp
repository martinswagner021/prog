#include "iostream"
#include "fstream"
#include "map"

using namespace std;

int main(){
    string nome_do_arquivo;
    cout << "Digite o nome do arquivo a ser lido: ";
    cin >> nome_do_arquivo;

    ifstream arquivo(nome_do_arquivo);
    string linha;

    if (!arquivo.is_open()) return -1;

    map<char, int> aparicao;

    while(getline(arquivo, linha)){
        for(char it: linha){
            if(aparicao.find(it)==aparicao.end()){
                aparicao.insert(make_pair(it,1));
            }
            else{
                aparicao[it]++;
            }
        }
    }

    for(auto it: aparicao) cout << it.first << " " << it.second << endl;
}