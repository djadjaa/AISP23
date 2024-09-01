#include <bits/stdc++.h>

using namespace std;

int main(){

    int a,b,k;
    cin >> a >> b >> k;
    int levagr;
    if(a%k==0)
        levagr = a/k;
    else
        levagr = a/k+1; //+1 zato sto je interval zatvoren (osvrni se na promenljivu rez)
    int desnagr = b/k;
    int rez;
    if(desnagr < levagr) //ako vazi ovaj uslov, interval je nemoguc pa u tom slucaju nemamo broj brojeva deljivih sa dato k
        rez = 0;
    else
        rez = desnagr - levagr + 1;

    cout << rez << endl;
    return 0;
}

/*
 kada bi neki broj bio deljiv sa k, mora da bude oblika x=n*k
 taj broj pripada intervalu [a,b] pa vazi da je broj veći jednak od a, a manji jednak od b
 dakle:
 x >= a V x<= b
 odnosno kada bismo x zamenili sa izrazom koji nam godi:
 n*k >= a V n*k <= b / *1/k
 dobijamo levu i desnu granicu:
 nl = a/k V nd = b/k (koji moraju biti celi brojevi)
 interval [nl,nd] predstavlja interval svih kolicnika nekog broja sa k, a njihova kardinalnost je nd-nl+1 (+1 jer je interval zatvoren)
 */
