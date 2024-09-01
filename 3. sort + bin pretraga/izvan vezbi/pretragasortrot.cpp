#include <bits/stdc++.h>

using namespace std;

int64_t pronadji(vector<int64_t>&a, int64_t n, int64_t x){
    int64_t l=0, d=n-1;
    while(l<=d){
        int64_t s= (l+d)/2;
        if(a[s]==x){
            return 1;
        }
        if(a[l]<=a[s]){
            if(a[l]<=x && x<a[s]){
                d=s-1;
            }else{
                l=s+1;
            }
        }else{
            if(a[s]<x && x<=a[d]){
                l=s+1;
            }else{
                d=s-1;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t>a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t upiti;
    cin >> upiti;
    while(upiti--){
        int64_t x;
        cin >> x;
        cout << pronadji(a,n,x) << endl;
    }
    return 0;
}
