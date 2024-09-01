#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n,razlika;
    cin >> razlika >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(begin(a),end(a));
    for(int i=0; i<n; i++){
        cout << a[i] << endl;
    }
    int64_t i=0,j=1,numch=0;
    while(j<n){
        if(a[j]-a[i]==razlika){
            numch++;
            i++;
            j++;
        }
        else if(a[j]-a[i]<razlika)
            j++;
        else
            i++;
        cout << a[j]-a[i] << endl;
    }
    cout << numch << endl;
    return 0;
}
