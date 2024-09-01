#include <bits/stdc++.h>
using namespace std;

bool provera(vector<int64_t>lokacije, int64_t n, int64_t brlok, int64_t tempRast){
    int64_t prvaKuca = lokacije[0]; //postavimo lokaciju na prvu kucu
    n--;
    for(int i=1; i<brlok && n>0; i++){
        if(lokacije[i]-prvaKuca >= tempRast){ //ako rastojanje barem ispunjava granicu idemo na tu kucu i od nje racunamo dalje i trazimo nasu zvanicnu granicu
            prvaKuca = lokacije[i];
            n--;
        }
    }
    return n==0;
}

int main(){

    int64_t n,brlok;
    cin >> n >> brlok;
    vector<int64_t> lokacije(brlok);
    for(int i=0; i<brlok; i++)
        cin >> lokacije[i];
    sort(begin(lokacije),end(lokacije));
    int64_t l=1, d=lokacije[brlok-1];
    int64_t rezultat;
    while(l<=d){
        int64_t s=(l+d)/2;
        if(provera(lokacije,n,brlok,s)){
            l=s+1;
            rezultat=s;
        }else
            d=s-1;
    }
    cout << rezultat << endl;
    return 0;
}

/*
 neka nam je dat br planiranih zgrada, kao i broj raspolozivih lokacija
 3
 4 raspolozive lokacije
 --*---*---*---*
    2   1    4
 ispod su rastojanja izmedju lokacija
 u ovom slucaju biramo prvu trecu i cetvrtu lokaciju, tada imamo najveca rastojanja 3 i 4, D(G) = min(3,4)=3

 --*---*---*---*
 medjutim ako izaberemo prvu drugu i cetvrtu lokaciju tada imamo rastojanja 2 i 3, D(G) = min(2,3) = 2

 D(G)=max(2,3) = 3

 posmatrajmo sad sledece raspolozive lokacije:
 2 4 6 9 10 12 14
  trazimo minimalno D koje mozemo dostici stavljanjem zgrada na raspolozive lokacije
  idemo postepeno dok ne nadjemo konacnu granicu
  kandidati 2 4 6, D>=2 (D je rastojanje izmedju kuca)
  kandidati 2 6 9, D>=3
  (Granica je minimalno rastojanje od rastojanja, a konacna granica maksimalna od pronadjenih granica)
 */
