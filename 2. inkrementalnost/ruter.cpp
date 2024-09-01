#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    /*
     baza indukcije:
     k=0;
     levo=0;
     desno=suma svih stanara;
     duzina=suma poz*brstanara
     */
    int64_t levo = 0, desno = 0, duzina=0;
    for(int i=0; i<n; i++){
        duzina += i*a[i];
        desno += a[i];
    }
    int64_t minduzina = duzina;
    for(int i=1; i<n; i++){
        levo += a[i-1];
        desno -= a[i-1];
        duzina += (levo-desno);
        if(duzina < minduzina)
            minduzina = duzina;
    }
    cout << minduzina << endl;

    return 0;
}

/*
 neka nam je dato 6 zgrada i u svakoj zgradi odredjen br stanara:
 6
     3 5 1 6 2 4
poz {0 1 2 3 4 5}
kada bismo postavili ruter u zgradi na poziciji 2:
od zgrade 2 do 1 nam je potrebno 5 kablova duzine 1
od zgrade 2 do 0 nam je potrebno 3 kablova duzine 2
od zgrade 2 do 3 -||- 6 kablova duzine 1
-||- 2 do 4 -||- 2 kabla duzine 2
-||- 2 do 5 -||- 4 kabla duzine 3
kada bismo od pocetne zgrade pa do krajnje racunali minimalnu duzinu kabla isli bismo redom po sledecoj formuli:

suma(od i=0 do n-1) |pozicija tekuce zgrade-pozicija svake zgrade|*broj stanara u itoj zgradi

primetimo da kada dodjemo do zgrade u kojoj zelimo da postavimo ruter pri sabiranju velicine kablova, imamo k sabiraka levo od te zgrade i n-k sabiraka desno:

npr k=2:
2*3+1*5+0*1+1*6+2*2+3*4
-------     -----------
k sab         n-k sab

takodje primetimo sledecu vezu:

k=1:
1*3+0*5+1*1+2*6+3*2+4*4
k=2:
2*3+1*5+0*1+1*6+2*2+3*4
duzinu kablova za ruter u k+1-toj zgradi racunamo tako sto duzinu kablova za ruter u zgradi k uvecamo za uk br stanara zakljucno sa ktom zgradom i umanjimo za uk br stanara pocevsi od k+1te zgrade:

k=2                        k=1
2*3+1*5+0*1+1*6+2*2+3*4 - (1*3+0*5+1*1+2*6+3*2+4*4)
= 1*3+1*5-1*1-1*6-1*2-1*4
=> br stanara levo od kte zgrade - br stanara desno od kte zgrade = duzina(i)-duzina(i-1)

dakle:
sum(i) = sum(i-1)+(levo(i) - desno(i))
levo(i) = levo(i-1)+ brstanara(i)
desno(i) = desno(i-1) - brstanara(i)

intuitivno, sto se pomeramo za jedno mesto u vise,vise kablova ce nam trebati za levu stranu, a manje za desnu stranu
 */
