#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t delilac;
    while(cin >> delilac){
        int64_t l=0, d=n-1;
        while(l<=d){
            int64_t s=(l+d)/2;
            if(a[s]%delilac==0){
                l=s+1;
            }else{
                d=s-1;
            }
        }
        cout << l << endl;
    }

    return 0;
}
