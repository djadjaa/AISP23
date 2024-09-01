#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    set<int64_t> s;
    int64_t threesome=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s.find(-a[i]-a[j])!=s.end()){
                threesome++;
            }
        }
        s.insert(a[i]);
    }
    cout << threesome << endl;
    return 0;
}
