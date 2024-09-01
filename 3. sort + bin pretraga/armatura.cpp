#include <bits/stdc++.h>
using namespace std;

bool provera(vector<int64_t>& armature, int64_t brojPostojecihArmatura, int64_t delovi, int64_t komadi){
    int64_t maxDuzinaTempStuba=0;
    for(int i=0; i<brojPostojecihArmatura; i++){
        maxDuzinaTempStuba += (armature[i]/delovi);
    }
    return maxDuzinaTempStuba >= komadi;
}

int main(){

    int64_t n,k;
    cin >> n;
    vector<int64_t> armature(n);
    for(int i=0; i<n; i++)
        cin >> armature[i];
    cin >> k;
    int64_t l=1, d=*max_element(begin(armature),end(armature));
    int64_t rezultat;
    while(l<=d){
        int64_t s=(l+d)/2;
        if(provera(armature,n,s,k)){
            l=s+1;
            rezultat=s;
        }else
            d=s-1;
    }
    cout << rezultat << endl;
    return 0;
}

/*
 neka nam je dato n armatura i k komada na koliko minimalno treba da podelimo armature tako da dobijemo maksimalnu mogucu duzinu stuba:
 5
 100 80 60 90 70
 10
 primenicemo bin pretragu po resenju
 ili mozemo napraviti stub od armature duzine 1 ili mozemo uzeti cak armaturu duzine 100
 leva granica ce nam biti 1 a desna najduza armatura a to je 100
 trazimo optimalnu sredinu sa kojom cemo deliti svaku od ovih armatura, tj trazimo na koliko delova mozemo maksimalno da delimo postojece armature
 napravicemo potencijalni stub i proveriti da li ga cine barem k delova
 zatim trazimo takav najveci stub i to ce nam biti resenje
 */
