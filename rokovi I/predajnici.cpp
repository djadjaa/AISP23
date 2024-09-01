#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a));
    int64_t d;
    cin >> d;
    int64_t j=0, maxrazd=INT_MIN;
    for(int i=0; i<n; i++){
        while(a[i]-a[j]>d && i>j)
            j++;
        maxrazd=max(a[i]-a[j],maxrazd);
    }
    cout << maxrazd << endl;
    return 0;
}
