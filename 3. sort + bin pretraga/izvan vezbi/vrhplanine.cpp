#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t>a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t l=0, d=n-1;
    while(l<=d){
        int64_t s=(l+d)/2;
        if(a[s]<a[s+1]) //idemo na desnu pol
            l=s+1;
        else //idemo na levu pol
            d=s-1;
    }
    cout << a[l] << endl;
    return 0;
}
