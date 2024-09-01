#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    long long tempsum=0;
    long long x;
    for(long long i=0; i<n; i++){
        cin >> x;
        tempsum += x;
    }

    cout << (n*(n+1))/2 - tempsum << endl;

    return 0;
}
