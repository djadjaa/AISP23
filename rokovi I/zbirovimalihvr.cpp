#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a));
    vector<int64_t> psum(n+1);
    for(int i=1; i<psum.size(); i++){
        psum[i]= psum[i-1]+a[i-1];
    }/*
    for(int i=0; i<psum.size(); i++)
        cout << psum[i] << endl;*/
    int64_t upiti;
    cin >> upiti;
    while(upiti--){
        int64_t x;
        cin >> x;
        int64_t poz = upper_bound(begin(a),end(a),x)-begin(a); //it-begin(a)
        cout << psum[poz] << endl;
    }
    return 0;
}
/*
 int poz=upper_bound(begin(a),end(a),x)-begin(a); //trazimo poziciju gde se nalazi upperbound za br x
        //cout << poz << ' ';
        cout << niz_prefiksnih_suma[poz] << '\n'; //tamo gde je upperbound tamo je i prefiksna suma do tog broja
 */
