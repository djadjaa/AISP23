#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t sum;
    cin >> sum;
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    /*JEDAN NACIN
     //idemo na prvi element i inicijalizujemo sumu na njega
    int64_t i=0,j=0;
    int64_t tmpsum = a[i];
    while(j<n){
        if(tmpsum==sum){ //ako su sume jednake ispisujemo segmente
            cout << i << ' ' << j << endl;
            tmpsum -= a[i]; //posto smo dosli do zeljene sume
            i++;
        }
        else if(tmpsum<sum){
            j++;
            if(j<n) //ako nismo jos stigli do kraja niza
                tmpsum += a[j];
        }
        else{
            tmpsum -= a[i];
            i++;
        }
    }
     */

    int64_t i=0;
    int64_t tmpsum = 0;
    for(int j=0; j<n; j++){
        tmpsum += a[j];
        while(tmpsum>sum){ //dokle god je suma veca od date, umanjicemo je do nama pogodne
            tmpsum -= a[i];
            i++;
        }
        if(tmpsum==sum){ //ako su sume jednake ispisujemo segmente
            cout << i << ' ' << j << endl;
            tmpsum -= a[i]; //posto smo dosli do zeljene sume
            i++;
        }
    }

    return 0;
}
/*
 neka nam je dat niz:
 1 2 3 5 15 1 2 5
 i zbir=21
 sabiramo elemente sve dok ne naidjemo na broj veci od zbira
 1+2+3+5+15=26
 vidimo da 1 ne moze nikako da formira segment elementa koji kao zbir daju 21
 26-1=25
 isti slucaj sa 2
 25-2=23
 isti slucaj sa 3
 23-3=20
 opet sabiramo dalje:
 20+1=21
 vidimo da odgovara datoj sumi i oduzimamo od prvog elementa iz konacnog segmenta
 21-5
 a sabiramo dalje ako je suma manja od date
 21-5+2
 itd...

 dakle element sa leve strane oduzimamo od sume ako je suma veca od date sume, a element sa desne strane dodajemo sumi ukoliko je suma manja od date
 kada nadjemo odgovarajucu sumu, oduzimamo levi element jer ako bismo dodali desni, sto posto ce biti suma veca od date
 */
