#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    int64_t preServisiranja=0;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        preServisiranja += a[i];
    }
    int64_t levaPol = 0, desnaPol = preServisiranja;

    for(int i=0; i<n; i++){
        levaPol += a[i];
        desnaPol -= a[i];
        auto it
    }
    return 0;
}
