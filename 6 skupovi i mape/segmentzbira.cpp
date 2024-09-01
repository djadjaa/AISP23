#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n,s;
    cin >> s >> n;
    map<int64_t, int64_t> ps;
    ps[0]=1;
    int64_t x;
    int64_t tmpsum=0,numseg=0;
    while(n--){
        cin >> x;
        tmpsum += x;
        numseg += ps[tmpsum-s];
        ps[tmpsum]++;
    }
    cout << numseg << endl;
    return 0;
}
/*
 * neka je dat niz
 * 1 3 2 -4 3 -2
 * i zbir=1

 vidimo da su u pitanju segmenti 1, 3,2,-4,  2,-4,3,  3,-2

 * napravicemo mapu koja ce kao kljuc da ima prefiksnu sumu a vrednost broj pojavljivanja te sume, a mi cemo da izracunamo broj segmenata gde se pojavljuje nasa trazena suma

x=   1 3 2 -4 3 -2
ps= 0 1 4 6 2  5  3

 nasa baza je ps[0]=1

 x=1, tmpsum=1, numseg+=ps[tmpsum-sum]=ps[1-1]=ps[0]=1, ps[1]=1;
 x=3, tmpsum=4, numseg+=ps[4-1]=ps[3] X , ps[4]=1;
 x=2, tmpsum=6, numseg+=ps[6-1]=ps[5] X, ps[6]=1;
 x=-4, tmpsum=2, numseg+=ps[2-1]=ps[1]+=1=2, ps[2]=1;
 x=3, tmpsum=5, numseg+=ps[5-1]=ps[4]+=1=3, ps[5]=1;
 x=-2, tmpsum=3, numseg+=ps[3-1]=ps[2]+=1=4, ps[3]=1;

 zaista vidimo da ima 4 segmenta
 */
