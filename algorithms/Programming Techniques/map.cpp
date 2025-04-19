#include<bits/stdc++.h>

using namespace std;

int main(){
    map<char,int> mymap;
    
    string test = "Hello this is a test";



    for(auto itr = test.begin(); itr != test.end(); itr++) mymap[*itr]++;

    for(auto itr = mymap.begin(); itr != mymap.end(); itr++) cout << itr->first << ": " << itr->second << endl;

}