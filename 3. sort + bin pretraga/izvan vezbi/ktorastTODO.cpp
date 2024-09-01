#include <bits/stdc++.h>
using namespace std;

int64_t numDist(vector<int64_t>&a, int64_t n, int64_t potGr){
    int64_t rez=0, j=0;
    for(int i=0; i<n; i++){
        while(a[j]-a[i]<=potGr && j<n){ //pomaže da se pronađe indeks j takav da je a[j] prvi element koji je veći od a[i] + potgr; ovaj korak se radi kako bi se odredio broj elemenata u opsegu koji imaju razlike manje ili jednake potgr u odnosu na trenutni element a[i]
            j++;
        }
        rez += j-i+1;
    }
    return rez;
}

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t k;
    cin >> k;
    sort(begin(a),end(a));
    int64_t l=0, d=a[n-1]-a[0]; //granice ce da nam budu rastojanja izmedju elemenata
    while(l<=d){
        int64_t s=(l+d)/2;
        if(numDist(a,n,s) < k){ //trenutna vrednost rastojanja nije dovoljno velika da bi bila k-ta po redu u sortiranom nizu rastojanja; to znači da treba tražiti veće vrednosti rastojanja, pa se leva granica inkrementira kako bi se pokušalo sa većim vrednostima rastojanja
            l = s+1;
        }else{
            d = s-1;
        }
    }
    cout << l << endl;
    return 0;
}

/*
 da ne bismo racunali apsolutno sva rastojanja, mozemo odrediti potencijalnu granicu preko binarne pretrage do koje ce se racunati rastojanja (rastojanja racunamo preko tehnike dva pokazivaca) -> ako im je rastojanje <= potencijalna granica onda ga uzimamo u obzir i racunamo uk broj takvih rastojanja
 ova potencijalna granica ce nam biti ujedno potencijalno kto rastojanje koje mi trazimo
 */
