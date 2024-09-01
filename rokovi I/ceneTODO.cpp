//#define N 1000000
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    uint32_t n;
    cin >> n;
    vector<uint32_t> cena(n);
    uint32_t maxdim=1;
    for(uint32_t i=0; i<n; i++){
        cin >> cena[i];
        maxdim = max(maxdim,cena[i]);
    }
    vector<uint32_t> numProd(maxdim+1);
    /*
    if(maxdim < n)
        numProd.resize(n+1);
    */
    for(uint32_t i=0; i<n; i++)
        numProd[cena[i]]++;
    /*
    for(uint32_t i=0; i<numProd.size(); i++)
        cout << numProd[i] << endl;
    */
    vector<uint32_t> ukBrArt(maxdim+2,0);
    if(maxdim<n){
        ukBrArt.resize(n+1,0);
    }
    for(uint32_t i=1; i<ukBrArt.size(); i++)
        ukBrArt[i] = ukBrArt[i-1]+numProd[i-1];
/*
    for(uint32_t i=0; i<ukBrArt.size(); i++)
        cout << ukBrArt[i] << endl;
*/
    uint32_t upiti;
    cin >> upiti;
    while(upiti--){
        uint32_t cena1,cena2;
        cin >> cena1 >> cena2;
        cout << ukBrArt[cena2+1]-ukBrArt[cena1]<< endl;
    }
    return 0;
}
/*
 cene mogu biti od 1 do milion pa ce dimenzija vektora biti do milion
 radicemo prefiksne sume koje ce predstaviti ukupan broj artikla izmedju cene a i b
 */
