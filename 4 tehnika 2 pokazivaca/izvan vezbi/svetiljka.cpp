#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t d;
    cin >> d;
    sort(begin(a),end(a));
    int64_t j=0, numhouse=INT_MIN;
    for(int i=0; i<n; i++){
        while(a[i]-a[j]>2*d)
            j++;
        numhouse = max(numhouse, i-j+1);
    }
    cout << numhouse << endl;
    return 0;
}
