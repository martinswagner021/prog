#include "iostream"
#include "fstream"
#include "sstream"

using namespace std;

bool is_float(string s){
    for(char it: s){
        if (it == '.') return true;
    }
    return false;
}
bool is_decimal(string s){
    for(char it: s){
        
    }
}

int main(){
    ifstream arquivo("valores.txt");
    string linha;
    int inteiros = 0, floats = 0, strings = 0;

    while(getline(arquivo, linha)){
        stringstream ss(linha);
        string campo;
        while(getline(ss, campo, ',')){
            if(is_float(campo)) floats++;
            else inteiros++;
        }
    }

    cout << inteiros << endl;
    cout << floats << endl;
    cout << strings << endl;
}