#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t s,n;
    cin >> s;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t numPair=0;
    sort(begin(a),end(a));
    for(int i=0; i<n; i++){
        int64_t elem = s-a[i];
        if(binary_search(begin(a), begin(a)+i, elem))
            numPair++;
    }
    cout << numPair << endl;
    return 0;
}
