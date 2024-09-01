#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    set<int64_t> s;
    int64_t x,maxnum=0;
    while(n--){
        cin >> x;
        if(s.find(x)!=s.end()){
            maxnum = max(maxnum,x);
        }
        s.insert(x);
    }
    if(maxnum==0)
        cout << "nema\n";
    else
        cout << maxnum << endl;
    return 0;
}
