#include <bits/stdc++.h>
using namespace std;

struct stablo{
    long long pocetak,kraj,debljina;
};

long long foo(long long x, vector<stablo>&stabla){
    long long rezultat=0;
    for(stablo& s : stabla){
        if(x<s.pocetak){
            rezultat += s.debljina*(s.kraj-s.pocetak);
        }if(x>=s.pocetak && x<s.kraj){
            rezultat += s.debljina*(s.kraj-x);
        }
    }
    return rezultat;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,n;
    cin >> t >> n;
    vector<stablo> stabla(n);
    for(int i=0; i<n; i++)
        cin >> stabla[i].pocetak >> stabla[i].kraj >> stabla[i].debljina;
    //trazenje maksimalne koordinate
    long long maxcoord = 0;
    for(int i=0; i<n; i++)
        maxcoord = max(maxcoord, stabla[i].kraj);
    long long l=0, d=maxcoord-1,s,rez;
    while(l<=d){
        s=l+(d-l)/2;
        if(foo(s,stabla)==t){
            rez=s;
            break;
        }
        if(foo(s,stabla) < t){
            rez = s;
            d = s-1;
        }
        else
            l = s+1;
    }
    cout << rez << ' '  << foo(rez,stabla) << endl;
    return 0;
}
