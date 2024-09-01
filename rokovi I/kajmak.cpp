#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n,t;
    cin >> n >> t;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t j=0, sum=0, maxsum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
        while(sum>=t){
            sum-=a[j++];
        }
        maxsum = max(sum,maxsum);
    }
    cout << maxsum << endl;
    return 0;
}
