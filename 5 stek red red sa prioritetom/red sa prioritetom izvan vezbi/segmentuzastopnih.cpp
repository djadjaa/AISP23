#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t maxseg=0;
    for(int i=0; i<n; i++){
        priority_queue<int64_t> numsInc;
        priority_queue<int64_t,vector<int64_t>,greater<int64_t>>numsDec;
        for(int j=i; j<n; j++){
            numsInc.push(a[j]);
            numsDec.push(a[j]);
            int64_t lenght = j-i+1;
            int64_t segment = numsInc.top() - numsDec.top() +1;
            if(lenght==segment)
                maxseg=max(maxseg,segment);
        }
    }
    cout << maxseg << endl;
    return 0;
}
/*
 imacemo dva reda gde u jednom cuvamo elemente u rastucem, a u drugom u opadajucem poretku:
 55 56 58 57 90 92 94 93 91 59 60
 {55} {55} - duzina = 1, segment = 1
 {55,56} {56,55} - duzina=2, segment = 2
 itd
 ukoliko se duzina i velicina segmenta poklapaju racunamo njegov maksimum
 ne bismo mogli tehniku dva pokazivaca zato sto bismo svaki put resetovali nas pocetni element
 */
