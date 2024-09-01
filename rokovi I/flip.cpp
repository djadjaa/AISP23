#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n,k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    int64_t i=0, numflips=0, maxlenght=0;
    for(int j=0; j<n; j++){
        if(a[j]==0){
            numflips++;
        }

        while(numflips>k){
            if(a[i]==0)
                numflips--;
            i++;
        }

        maxlenght = max(maxlenght,j-i+1);
    }
    cout << maxlenght << endl;
    return 0;
}
/*
 neka nam je dat niz:
 1 1 0 0 1 0 1 1
 i 2 flipa ukupno
 vidimo da je a[0] 1 pa idemo dalje (pritom brflipova<=k)
 a[2] vec ce biti 0 pa uvecavamo br flipova
 paralelno cemo odrediti da li se bit moze flipovati i maksimalnu duzinu niza jedinica
 cim se prekoraci broj flipa, pomeramo levi pokazivac i umanjujemo broj flipa, jer posmatramo u tom slucaju drugi deo niza
 */
