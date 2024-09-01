#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n,m;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a));
    cin >> m;
    vector<int64_t> b(m);
    for(int i=0; i<m; i++)
        cin >> b[i];
    sort(begin(b),end(b));
    int64_t budzet;
    cin >> budzet;
    int64_t i=0, j=m-1;
    int64_t rez=INT_MIN;
    while(i<n && j>=0){
        if(a[i]+b[j]<=budzet){
            rez=max(rez,a[i]+b[j]);
            i++;
        }
        else{
            j--;
        }
    }
    cout << rez << endl;
    return 0;
}
