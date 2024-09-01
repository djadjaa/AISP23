#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    cin >> n;
    vector<int64_t> b(n);
    for(int i=0; i<n; i++)
        cin >> b[i];
    cin >> n;
    vector<int64_t> c(n);
    for(int i=0; i<n; i++)
        cin >> c[i];

    /*
     * JEDAN NACIN
    int64_t i=0, j=0, k=0;
    while (i<n && j<n && k<n){
        if(a[i]==b[j] && b[j]==c[k]){ //svojstvo tranzitivnosti
            cout << a[i] << endl;
            i++;
            j++;
            k++;
        }else if(a[i]<b[j]){ //poredimo da li je jedan manji od drugog zato sto su uredjeni nizovi u pitanju
            i++;
        }else if(b[j]<c[k]){
            j++;
        }else{
            k++;
        }
    }*/
    //DRUGI NACIN
    int64_t i=0,j=0;
    while(i<n && j<n){
        int64_t k=0; //pokazivac za treci niz
        if(a[i]==b[j]){ //ako su elementi iz prva dva niza jednaka prelazimo na poredjenje prvog elementa sa trecim
            while(k<n && c[k]<a[i]) //dokle god je element iz treceg manji od elementa iz prvog (uredjenje)
                k++;
            if(k<n && a[i]==c[k]) //ako smo naisli na jednake elemente
                cout << a[i] << endl;
            i++; //idemo dalje kroz prva dva niza
            j++;
        }
        else if(a[i]<b[j]) //poredimo da li je jedan manji od drugog zato sto su uredjeni nizovi u pitanju
            i++;
        else
            j++;
    }
    return 0;
}
