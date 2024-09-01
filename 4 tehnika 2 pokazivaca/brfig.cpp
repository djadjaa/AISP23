#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> fig(n);
    for(int i=0; i<n; i++)
        cin >> fig[i];
    sort(begin(fig),end(fig));
    int64_t jacina;
    cin >> jacina;
    int j=0;
    int64_t rezultat=0, razlika=0;
    for(int i=0; i<n; i++){
        while((i-j+1)*(fig[i]-fig[j])>jacina){
            j++;
        }
        int64_t tmpRazlika = (i-j+1)*(fig[i]-fig[j]);
        if(i-j+1>rezultat || (i-j+1==rezultat && tmpRazlika<jacina)){ //ako nam se tekuci rezultat razlikuje (nije neophodno da u prvom uslovu proverimo razliku (lenjo izracunavanje)) ili ako nam se razlika razlikuje
            rezultat=i-j+1;
            razlika=tmpRazlika;
        }
    }
    cout << rezultat << ' ' << razlika << '\n';
    return 0;
}

/*
 neka nam je dato 5 figurica i granica>
 5
 5 4 2 7 3
 15
 potrebno je naci najveci br igraca tako da razlika izmedju svih figurica izmedju ta dva igraca ne predju granicu
 formula je:
     k*jacina1 - k*jacina2 <= granica
k(jacina1 - jacina 2) <= granica
biramo jacine do k jer ako naidjemo na ktog igraca koji ne ispunjava uslov nece ni oni koji su >k jer k nam je granica
u ovom slucaju radimo tehniku dva pokazivaca, sortiracemo niz i ici cemo od pocetka i racunacemo razliku sve dok ne prestigne granicu;
kada prestigne granicu, idemo na drugi niz, ali necemo ispocetka racunati razlike, nego nastaviti od prethodnog umanjilaca, jer intuitivno gledano ako je prvi umanjenik i umanjioci pre poslednjeg prethodnog daju razliku koja ne prolazi granicu, nece ni naredni umanjenik sa istim umanjiocima:

npr
2 3 4 5 7
ako su 2 i 5 dali rezultat koji ne prelazi granicu, nece ni 3 i 5 jer se broj igraca smanjio pa je razlika za nijansu smanjena ili uvecana ali opet ne prelazi granicu
stoga racunamo 3 i 7 itd sve do kraja

brigraca(jacina1-jacina2) <= granica

br igraca racunamo kao razliku indeksa izmedju data dva elementa
 */
