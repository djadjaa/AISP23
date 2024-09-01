#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n,q;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a));
    vector<int64_t> psum(n+1);
    for(int i=1; i<psum.size(); i++)
        psum[i] = psum[i-1]+a[i-1];
    /*
    for(int i=0; i<n+1; i++)
        cout << psum[i] << ' ';
    cout << endl;
    */
    cin >> q;
    int64_t upit;
    while(q--){
        cin >> upit;
        cout << *lower_bound(begin(psum),end(psum),upit) << endl;
    }

    return 0;
}
