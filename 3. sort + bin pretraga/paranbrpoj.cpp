#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector <int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a));
    int64_t numOcc=0, lenght=1;
    for(int i=1; i<n; i++){
        if(a[i]==a[i-1]){
            lenght++;
        }
        else{
            if(lenght%2==0){
                numOcc++;
            }
            lenght=1;
        }
    }
    if(lenght%2==0){
        numOcc++;
    }
    cout << numOcc << endl;
    return 0;
}
