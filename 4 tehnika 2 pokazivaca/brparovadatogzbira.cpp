#include <bits/stdc++.h>
using namespace std;
int main(){

    int64_t sum, n;
    cin >> sum >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a));
    int64_t i=0,j=n-1;
    int64_t numpair=0;
    while(i<j){
        if(a[i]+a[j]==sum){
            numpair++;
            i++;
            j--;
        }
        else if(a[i]+a[j]>sum){
            j--;
        }else{
            i++;
        }
    }
    cout << numpair << endl;

    return 0;
}

/*
 7 6
 2 5 4 7 0 6
 i         j
 => 0 2 4 5 6 7
    i         j
    0+7=7 i++ j--
    2+6=8 j--
    2+5=7 i++ j--
    4+4=8 kraj!!!
 */
