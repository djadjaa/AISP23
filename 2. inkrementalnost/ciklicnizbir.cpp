#include <bits/stdc++.h>

using namespace std;

const int mod = 1234567;

// zbir x i y po modulu mod
int64_t zm(int64_t x, int64_t y, int mod) {
  return (x % mod + y % mod) % mod;
}

// razlika x i y po modulu mod
int64_t rm(int64_t x, int64_t y, int64_t mod) {
  return (x % mod - y % mod + mod) % mod;
}

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int sum=0, ciklsum=0;
    for(int i=0; i<n; i++){
        ciklsum = zm(ciklsum, i*a[i], mod);
        sum = zm(sum,a[i],mod);
    }
    int maxciklsum=ciklsum;
    for(int i=1; i<n; i++){
        ciklsum=zm(rm(ciklsum,sum,mod),n*a[i-1],mod);
        if(ciklsum>maxciklsum)
            maxciklsum=ciklsum;
    }

    cout << maxciklsum << endl;

    return 0;
}

/*
 neka nam je dat niz od 3 elem:
 5 4 1
 ciklicni zbir ide 0*a0+1*a1+...+(n-1)*an-1
 z0: 0*5+1*4+2*1 = 6
 z1: 0*4+1*1+2*5 = 11
 z2: 0*1+1*5+2*4 = 13
 primecujemo sledecu vezu (oduzimanjem ove dve sume):
 zbir za itu rotaciju dobijamo tako sto od zbira za i-1tu rotaciju oduzmemo od ukupnog zbira svih elem i dodamo n*itielem:
 npr i=2
 ( 1  5  4 ):
  ali posmatramo pozicije prvobitnog niza ( dakle ako je prvobitni niz bio 5 4 1, tada ce pozicije tekuceg niza biti a2 a0 a1)
 z1: 0*4+1*1+2*5
 z2: 0*1+1*5+2*4
 z1 - z2 = 0*4+1*1+2*5 - (0*1+1*5+2*4) = 1*1 + 1*5 -2*4 = 1+5-(3-1)*4 = 1+5-3*4+1*4 = 1+5+4-3*4
 => z1-z2 = a2+a0+a1-n*a1
 z2 = z1 - zn + n*a1
 zi = zi-1 -zn + n*ai-1
 */
