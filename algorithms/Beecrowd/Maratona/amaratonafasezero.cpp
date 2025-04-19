#include <bits/stdc++.h>

using namespace std;

typedef struct Aluno
{
    string nome;
    float p1 = 0;
    float p2 = 0;
    float trab = 0;
    float vs = 0;
};

int main()
{
    int N, media, cont = 0;
    cin >> N;

    Aluno aluno[N];

    for(int i = 0; i < N; i++)
    {
        cin >> aluno[i].nome;
        cin >> aluno[i].p1;
        cont++;
        cin >> aluno[i].p2;
        cont++;
        cin >> aluno[i].trab;
        cont++;
        cin >> aluno[i].vs;
        cont++;

    }


    for(int i = 0; i < N; i++)
    {
        media = (aluno[i].p1 + aluno[i].p2 + aluno[i].trab + aluno[i].vs) / cont;
        cout << aluno[i].nome << ": " << media << endl;
    }

    return 0;
}