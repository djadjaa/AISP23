#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<int64_t> sortiran = a;
    sort(begin(sortiran),end(sortiran));
    for(int i=0; i<n; i++){
        auto it = lower_bound(begin(sortiran),end(sortiran),a[i]);
        cout << it-begin(sortiran) << ' ';
    }
    cout << endl;
    return 0;
}
