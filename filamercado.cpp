#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void printvector(vector<int> v){
    for(int i: v){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    vector<int> n, m, resp;
    int N, M;

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        int push;
        cin >> push;
        n.push_back(push);
    }
    for(int i=0; i<M; i++) {
        int push;
        cin >> push;
        m.push_back(push);
    }

    for(int i=0; i<M; i++){
        if(i<N){
            int prod = m[i]*n[i];
            resp.push_back(prod);
        }
        else{
            auto melhor = min_element(begin(resp), end(resp));
            int indn = melhor - begin(resp);
            int prod = m[i]*n[indn];

            *melhor += prod;
        }
    }

    auto maximo = max_element(begin(resp), end(resp));
    cout << *maximo << endl;
}