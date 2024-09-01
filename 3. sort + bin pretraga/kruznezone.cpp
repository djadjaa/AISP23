#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    vector<double> prstenovi(n);
    for(int i=0; i<n; i++){
        cin >> prstenovi[i];
    }
    vector<double> poluprecnici(n);
    poluprecnici[0] = prstenovi[0];
    for(int i=1; i<n; i++){
        poluprecnici[i]=poluprecnici[i-1]+prstenovi[i];
    }
    int64_t m;
    cin >> m;
    double x,y;
    while(m--){
        cin >> x >> y;
        double dist=sqrt(x*x+y*y);
        auto it = lower_bound(begin(poluprecnici),end(poluprecnici),dist);
        if(it==end(poluprecnici))
            cout << "izvan\n";
        else
            cout << it-begin(poluprecnici) << endl;
    }
    return 0;
}

/*
 za n kruznih prstenova su nam date njihove sirine:
 3
 2 3 7
 izracunacemo poluprecnik svakog od kruga
 0 2 5 12
 dato nam je 7 tacaka
 1 1
 2 3
 8 7
 13,2 14,5
 0 12
 potom racunamo rastojanje date tacke od koordinatnog pocetka i provericemo da li je >= od nekog od poluprecnika i u zavisnosti od poluprecnika, upada u datu zonu;a inace je izvan zone
 */
