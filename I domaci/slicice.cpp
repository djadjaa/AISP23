#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t cena, n;
    cin >> cena >> n;
    vector<int64_t>a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<int64_t> psum(n+1);
    for(int i=0; i<n; i++){
        psum[i+1]=psum[i]+(cena%a[i]==0);
    }
    int64_t m;
    cin >> m;
    while(m--){
        int64_t a,b;
        cin >> a >> b;
        cout << psum[b+1]-psum[a] << endl;
    }

    return 0;
}
/*
 ideja je da prefiksne sume protumacimo kao broj kolekcija koje moze da kupi a da potrosi sav novac, s tim da je broj kolekcija zapravo broj nacina na koji moze da potrosi sav novac tako sto ce da kupi samo jednu kolekciju od datih
 formalno gledano, zelimo da nadjemo brojeve koji kao niz jedne te istih sabiraka daju kao sumu bas dati novac
 npr: 3+3+3+3+3 = 5+5+5 = 1+...+1 = 15

 18 5
 2 9 3 6 1

 ono sto mozemo uraditi je:
 prefix.sum[i] = prefix.sum[i-1]+(cena%element[i]==0)
 drugi sabirak predstavlja istinitosnu vrednost, tačnije ona predstavlja da li postoji kolekcija slicica koju moze da kupi tako da potrosi sav novac
 stoga dobijamo:

 p.sum[0] = 0
 p.sum[1] = p.sum[0]+(18%2==0) = 0+1 = 1 => imamo 1 kolekciju jer 2+...+2=18
 p.sum[2] = p.sum[1]+(18%9==0) = 1+1 = 2 => imamo 2 kolekcije jer 9+9=18
 p.sum[3] = p.sum[2]+(18%3==0) = 2+1 = 3 => imamo 3 kolekcije jer 3+3+3+3+3+3=18
 itd

 i za dati segment samo cemo izracunati ukupan broj kolekcija
 */
