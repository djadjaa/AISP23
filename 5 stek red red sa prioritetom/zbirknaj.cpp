#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    int64_t k,x;
    cin >> k;
    priority_queue<int64_t> takmicari;
    for(int i=0; i<n; i++){
        cin >> x;
        takmicari.push(x);
    }
    int64_t sum=0;
    for(int i=0; i<k; i++){
        sum += takmicari.top();
        takmicari.pop();
    }
    cout << sum << endl;
    return 0;
}
