#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a));
    auto it=unique(begin(a),end(a)); //vraca iterator na pocetak duplikata
    a.erase(it,end(a)); //uklanja duplikate od pocetka njegovog pojavljivanja pa sve do kraja
    n=a.size(); //nova dimenzija niza
    int64_t duzinaNiza=1, start=0, maxDuzinaNiza=1, maxStart=0;
    //niz ima barem jedan element i krecemo od nultog elementa
    for(int i=1; i<n; i++){
        if(a[i]-a[i-1]==1){
            duzinaNiza++;
        }else{
            duzinaNiza=1; //biramo sledeci niz koji ispunjava kriterijume
            start=i; //i pocinjemo od itog elementa
        }
        if(duzinaNiza > maxDuzinaNiza){
            maxDuzinaNiza=duzinaNiza;
            maxStart = start;
        }
    }
    for(int i=maxStart; i<maxStart+maxDuzinaNiza; i++){
        cout << a[i] << endl;
    }
    return 0;
}
