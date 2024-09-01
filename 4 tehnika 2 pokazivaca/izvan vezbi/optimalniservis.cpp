#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    int64_t sumapreobrade=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sumapreobrade += a[i];
    }
    int64_t obradjeno=0, neobradjeno=sumapreobrade;
    int64_t minrazl=INT_MAX, danzaservis;
    for(int i=0; i<n; i++){
        obradjeno += a[i];
        neobradjeno -= a[i];
        if(abs(obradjeno-neobradjeno)<minrazl){
            minrazl=abs(obradjeno-neobradjeno);
            danzaservis=i;
        }
    }
    cout << danzaservis << endl;
    return 0;
}


/*
 neka nam je dat ovaj niz
 1 1 5 5 1 1
 kada bismo servisirali izmedju drugog i treceg dana razlika bi bila 0

 trazimo minimalnu razliku izmedju sume pre servisa i posle servisa; obradicemo zasebno levu i desnu polovinu: intuitivno gledano, kada idemo od prvog dana sa leve strane to ce da budu dani koji se najpre obradjuju, dok preostali koji nisu jos uvek obradjeni su sa desne strane
 */
