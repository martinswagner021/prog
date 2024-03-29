#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// void printvector(vector<Piloto> &v){
//     for(int i: v){
//         cout << i.tt << ' ';
//     }
//     cout << endl;
// }

struct piloto{
    int pid;
    vector<float> tv;
    float bestturn;
    float tt = 0;
};

typedef struct piloto Piloto;

int main(){

    Piloto plts[105];

    int n, v;

    cin >> n >> v;

    for(int i=0; i<n; i++){
        cin >> plts[i].pid;
        for(int j=0; j<v; j++){
            float time[3];
            float temp=0;
            scanf("%f:%f:%f", &time[0], &time[1], &time[2]);
            temp+=time[0]*60;
            temp+=time[1];
            temp+=time[2]/1000;
            plts[i].tv.push_back(temp);
            plts[i].tt += temp;
        }
        plts[i].bestturn = *min_element(plts[i].tv.begin(), plts[i].tv.end());
    }

    vector<Piloto> pltvec;

    for(int i=0; i<n; i++) pltvec.push_back(plts[i]);


    sort(pltvec.begin(), pltvec.end(), [](Piloto a, Piloto b) {
		return a.tt < b.tt;
	});
    auto melhor = min_element(pltvec.begin(), pltvec.end(), [](Piloto a, Piloto b){
        return a.bestturn < b.bestturn;
    });

    if(melhor<pltvec.begin()+10){
        int ind = melhor - pltvec.begin();
        cout << pltvec[ind].pid << endl;
    }
    else{
        cout << "NENHUM" << endl;
    }
}
