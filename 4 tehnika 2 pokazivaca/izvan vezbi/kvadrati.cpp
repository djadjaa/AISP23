#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t negativanIndeks=-1; //moze da se desi da nemamo nijedan negativan broj u nizu,eventualno nijedan pozitivan
    int64_t l=0, d=n-1;
    while(l<=d){
        int64_t s=(l+d)/2;
        if(a[s]<0){
            l=s+1;
            negativanIndeks = s;
        }else
            d=s-1;
    }
    int64_t nenegativanIndeks = negativanIndeks + 1;
    int64_t ind=0; //za novi niz
    vector<int64_t> newArray(n);
    while(negativanIndeks>=0 && nenegativanIndeks<n){ //negativan deo niza ide od 0 do prvog nenegativnog indeksa, a pozitivan deo ide do kraja
        if(-a[negativanIndeks] < a[nenegativanIndeks]){ //ovde ponistavamo negativnost i poredimo dva pozitivna broja
            newArray[ind++] = a[negativanIndeks]*a[negativanIndeks];
            negativanIndeks--; //manji brojevi su u levo
        }else{
            newArray[ind++] = a[nenegativanIndeks]*a[nenegativanIndeks];
            nenegativanIndeks++; //veci brojevi su u desno
        }
    }
    //ubacujemo ostatak niza
    while(negativanIndeks>=0){
        newArray[ind++] = a[negativanIndeks]*a[negativanIndeks];
        negativanIndeks--;
    }
    while(nenegativanIndeks<n){
        newArray[ind++] = a[nenegativanIndeks]*a[nenegativanIndeks];
        nenegativanIndeks++;
    }
    for(int i=0; i<newArray.size(); i++)
        cout << newArray[i] << ' ';
    cout << endl;
    return 0;
}
