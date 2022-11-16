#include<bits/stdc++.h>

using namespace std;

int main(){
    char temp;
    string linha;

    vector<string> victims;
    map<string, int> murderers;

    while(scanf("%c", &temp)!=EOF){
        if(temp != '\n'){
            linha.push_back(temp);
        }
        else{
            auto space = linha.find(' ');
            murderers[linha.substr(0,space)]++;
            victims.push_back(linha.substr(space+1));
            linha.clear();
        }
    }

    for(auto i = victims.begin(); i != victims.end(); i++){
        murderers.erase(*i);
    }

    cout << "HALL OF MURDERERS" << endl;

    for(auto i = murderers.begin(); i != murderers.end(); i++) cout << i->first << " " << i->second << endl;

}