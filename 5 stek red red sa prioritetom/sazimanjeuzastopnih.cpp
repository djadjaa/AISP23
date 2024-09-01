#include <bits/stdc++.h>

using namespace std;

int main(){
    int64_t n,k;
    cin >> k >> n;
    vector<int64_t> vr;
    vector<int64_t> occ;
    int64_t x;
    while(n--){
        cin >> x;

        if(!vr.empty() && occ.back() >= k && vr.back() != x){
            vr.pop_back();
            occ.pop_back();
        }
        if(!vr.empty() && x == vr.back())
            occ.back()++;
        else{
            vr.push_back(x);
            occ.push_back(1);
        }

    }

    if(!vr.empty() && occ.back() >= k){
        vr.pop_back();
        occ.pop_back();
    }

    for(int i=0; i<vr.size(); i++){
        while(occ[i]>0){
            cout << vr[i] << ' ';
            occ[i]--;
        }
    }
    cout << endl;
    return 0;
}
