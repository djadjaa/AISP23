#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t m,k;
    cin >> m;
    while(m--){
        cin >> k;
        /*
        if(k<a[0])
            cout << k << endl;
        */
        int64_t l=0, d=n-1;
        while(l<=d){
            int64_t s=(l+d)/2;
            if(a[s]-(s+1) < k){ //broj onih koji fale levo od tekuceg elementa
                /*
                 0 1 2 3 4
                2 3 4 7 11 a
                1 2 3 4 5 b (i+1)
                1 1 1 3 6 c
                 */
                l = s+1;
            }else{
                d = s-1;
            }
        }
        cout << l+k << endl; //a[l]-(a[l]-l-k)
    }

    return 0;
}
/*
 GRUBA SILA
 kada bismo brojali respektivno, primetili bismo da brojimo i one koje fale; u tom slucaju bismo imali nas interni inkrementor u kom bismo sacuvali broj onih koji fale u datom nizu; tada bismo paralelno uvecali inkrementor i brojali respektivno
 npr niz 2 3 4 7 11
 1 => inkrementor++
 2 => inkrementor = 1
 3 => inkrementor = 1
 4 => inkrementor = 1
 5 => inkrementor++
 6 => inkrementor++
 7 => inkrementor = 3
 itd
 s tim da inkrementor uvecavamo do k. cim smo stigli do k, stigli smo i do naseg zeljenog broja: u ovom slucaju 11
 dakle, dokle god je inkrementor razlicit od k, idemo kroz petlju i trazimo nas kti broj

OPTIMIZOVANO RESENJE
ideja je da preko binarne pretrage nadjemo kti nedostajuci broj
za dati niz imamo:
-niz brojeva koji predstavlja prvih k uzastopnih brojeva
-niz brojeva koji predstavljaju broj nedostajucih za svaki od datog
0 1 2 3 4
2 3 4 7 11 a
1 2 3 4 5 b (i+1)
1 1 1 3 6 c
kako to radimo:
3-2=1
4-3=1
7-4=3
11-5=6
sada trazimo prvi najmanji broj veci od k (a[i]-b[i]=c[i] <= k)
granicu uvecavamo ako je razlika manja od k, inace je smanjujemo
resenje je tamo gde je leva granica
dobijemo zvanican rezultat => l+k
npr l=4 (11) => 4+5=9
dakle:
trazimo koliko elemenata fali levo od 11 tako sto ga oduzmemo od naseg rezultata binarne pretrage:
a[l]-(l+1) = 11-4-1=6 - ovoliko fali brojeva levo od 11
trazimo potom koliko koraka unazad nam treba da pronadjemo dati broj
a[l]-(l+1)-k+1 = 11-4-1-5+1=2
dakle dva puta idemo unazad kroz niz respektivnih brojeva od 1 do 11 kako bismo nasli zeljeni broj
11-2=9
=> oduzecemo od a[l] broj koji predstavlja vrednost koliko puta idemo unazad od tog broj kako bismo nasli zeljeni broj
a[l]-(a[l]-l-k) = zaista dobijamo 11-(11-4-5) = 11-2 = 9
mada kada bismo sredili ovaj izraz dobijamo kao rezulat l+k o cemu je napisano odozgo

gornje ogranicenje nam je k, zato sto trazimo prvi najmanji broj koji je veci od k
 */
