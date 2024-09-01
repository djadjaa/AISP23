#include <bits/stdc++.h>

using namespace std;
//prosledjujemo levu i desnu granicu zbog merge sort algoritma
int akcije(int l, int d, vector<int64_t>& v, int& vmax, int& vmin){
    if(l==d){
        vmax= vmin = v[l]; //jedina vr u ovom segmentu
        return 0;
    }
    //inace:
    int s = (l+d)/2;
    int maxL,minL;
    int zaradaL = akcije(l,s,v,maxL,minL); //[l,s] leva polovina niza
    int maxD,minD;
    int zaradaD = akcije(s+1, d, v, maxD, minD); //[s+1,d] desna polovina niza
    vmax = max(maxL,maxD);
    vmin = min(minL,minD);
    return max({zaradaL, zaradaD, maxD-minL});
}

int main(){
    int n;
    cin >> n;
    vector<int64_t> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    int vmax,vmin;
    cout << akcije(0,n-1,v,vmax,vmin) << endl;
    return 0;
}
/*
 3 5 8 4 2 6 9
 maksimalna zarada = maksimalna razlika izmedju najmanjeg i najveceg s tim da uvek idemo napred kroz niz

 podelicemo niz na dva dela, racunamp razlike i poredimo je sa razlikom iz druge polovine niza

 medjutim fali nam parovi gde nam je jedan elem iz leve a drugi iz druge polovine, i njih moramo razmatrati => mozemo uzeti minimum iz leve a maksimum iz desne polovine

 izvrsicemo rek poziv kako za levu tako za desnu polovinu i time dobiti resenje za svaku od njih; zatim odrediti minimalni element iz leve polovine, maksimalni element iz desne polovine, njih oduzeti i odrediti najbolju zaradu od te tri razlike (za ceo niz)

 slozenost je: T(n) = 2T(n/2)+n tj O(nlogn) jer koristimo merge sort algoritam

 za neki deo niza trazimo: maksimalnu zaradu, maksimalni i minimalni element
 sve ove zeljene stvari naci cemo rekurzivnim putem rekurzivnim formulama i tako poboljsati slozenost:

 rez=max(rezL,rezD, maxD-minL)
 min = min(minL,minD)
 max = max(maxL,maxD);
 */
