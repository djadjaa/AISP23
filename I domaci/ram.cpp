#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n;
    cin >> n;
    cout << 2*n*n*n-2*n*n-2*n+2 << endl;

    return 0;
}

/*
 * neka je dat sledeci kvadrat:
 * 0 1   2  3   4
 * 5            9
 * 10          14
 * 15          19
 * 20 21 22 23 24
 * primetimo sledece: ako je n=5, tada je 4=5-1 odnosno n-1; 9 je 10-1 odnosno 2*n-1
 * prvi red je niz od 0 do n (a0 = 1 jer 0 svakako ne pripada zbiru kako god pogledas, an = n-1, n=n-1 (ne racunamo 0))
 * leva kolona predstavlja niz: n,2n,3n ... (n-1)*n (a0=n, an=(n-1)n, n=n-1 (ne racunamo element [0][0])
 * desna kolona 2n-1,3n-1,...,n*n-1 (a0=2n-1, an=n*n-1, n=n-1 (ne racunamo element [0][n-1])
 * ostatak predstavlja niz od (n-1)*n + 1 do n*n-2 (a0=(n-1)*n + 1, an=n*n-2, n=n-2 (ne racunamo element (n-1)*n i element n*n-1)
 * ubacimo sve ove info u formulu za sumu aritmetickog niza, u ovom slucaju imamo 4 aritmeticka niza; sredjujemo izraz i dobijamo adekvatnu formulu
 */
