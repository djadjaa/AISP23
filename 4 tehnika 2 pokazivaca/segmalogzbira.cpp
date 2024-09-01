#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t t;
    cin >> t;
    int64_t j=0,numseg=0,tmpsum=0;
    for(int i=0; i<n; i++){
        tmpsum += a[i];
        while(tmpsum>=t)
            tmpsum -= a[j++];
        numseg += i-j+1;
    }
    cout << numseg << endl;
    return 0;
}
