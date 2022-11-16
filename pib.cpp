#include<bits/stdc++.h>

using namespace std;

int main() {
    double f1, f2;
    double c=1;


    cin >> f1 >> f2;

    c = c*(1+(f1/100));
    c = c*(1+(f2/100));

    c = (c-1)*100;

    printf("%.6f\n",c);
}