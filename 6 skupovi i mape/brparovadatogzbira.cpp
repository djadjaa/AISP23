#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t z,n;
    cin >> z >> n;
    int64_t x,numpair=0;
    set<int64_t> s;
    while(n--){
        cin >> x;
        if(s.find(z-x) != s.end()){
            numpair++;
        }
        s.insert(x);
    }
    cout << numpair << endl;
    return 0;
}
