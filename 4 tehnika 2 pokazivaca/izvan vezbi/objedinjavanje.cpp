#include <bits/stdc++.h>
using namespace std;
int main(){

    int64_t n,m;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    cin >> m;
    vector<int64_t>b(m);
    for(int i=0; i<m; i++)
        cin >> b[i];

    vector<int64_t> c(n+m);
    int64_t i=0, j=0, k=0; //k nam je indeks za nas niz c
    while(i<n && j<m){

        c[k++] = a[i] < b[j] ? a[i++] : b[j++];

        /*
        if(a[i] < b[j]){
            c[k++] = a[i++];
        }
        else if(b[j] < a[i]){
            c[k++] = b[j++];
        }*/
    }
    while(i<n)
        c[k++] = a[i++];
    while(j<m)
        c[k++] = b[j++];

    for(int i=0; i<c.size(); i++)
        cout << c[i] << ' ';
    cout << endl;

    return 0;
}
