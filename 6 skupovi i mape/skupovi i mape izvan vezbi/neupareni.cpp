#include <bits/stdc++.h>
using namespace std;
int main(){

    int64_t n;
    cin >> n;
    map<int64_t,int64_t> stolice;
    int64_t x;
    while(n--){
        cin >> x;
        stolice[x]++;
    }
    int64_t rez=0;
    for(auto it : stolice){
        if(it.second == 1){
            rez = it.first;
        }
    }
    if(rez==0)
        cout << "ne postoji neupareni element\n";
    else
        cout << rez << endl;
    return 0;
}
