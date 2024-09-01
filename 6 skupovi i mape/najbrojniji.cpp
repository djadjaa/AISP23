#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    map<string,int> ucesnici;
    string s;
    while(n--){
        cin >> s;
        ucesnici[s]++;
    }
    int rez=0;
    for(auto u : ucesnici){
        rez = max(rez,u.second);
    }
    cout << rez << endl;
    return 0;
}
