#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    map<int64_t,int64_t> mp;//kljuc je prefiksna suma koja se nalazi na tom indeksu, a vrednost je indeks
    vector<int64_t> pres(n);
    pres[0]=a[0];
    for(int i=1; i<n; i++){
        pres[i]=pres[i-1]+a[i];
        mp[pres[i]]=i;
    }
    //postfiksne sume
    vector<int64_t> posts (n);
    int64_t maks=INT_MIN;
    posts[n-1]=a[n-1];
    for(int i=n-2; i>=0; i--){
        posts[i] = posts[i+1]+a[i];
        if(mp.find(posts[i])!=mp.end() && i>mp[posts[i]]){
            maks = max(maks,posts[i]);
        }
    }
    cout << maks << endl;

    return 0;
}

/*
 "Потребно је поделити низ на три дела, тако да сваки део садржи узастопне елементе низа и да је збир првог и трећег дела једнак."
 ovaj deo cemo uzeti zdravo za gotovo, zato sto je potrebno da ulaz bude takav
 mi cemo posmatrati samo prefiksne i postfiksne sume i da vidimo koje su jednake i pritom da nadjemo maksimalnu od njih

 i>mp[posts[i]] - postavljamo ovaj uslov pri pretrazi, da bi se ispunio uslov da zbir prvog i treceg dela moraju biti jednaki
 da nema ovog uslova, kod primera
 7
3 2 2 -1 9 4 2
bio bi rezultat 15 ali tada podnizovi nisu ispravno podeljeni (podeljeni na dva dela, zbir 15 je na jednakim indeksima)

3 5 7 6 15 19 21

2 6 15 14 16 18 21
 */
