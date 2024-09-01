#include <bits/stdc++.h>

using namespace std;

int64_t tempRazlIgraca(vector<int64_t>&fig, int64_t n, int64_t k){
    int64_t minRazl= INT_MAX;
    for(int i=0; i+k-1<n; i++){
        minRazl=min(minRazl,k*(fig[i+k-1]-fig[i]));
    }
    return minRazl;
}

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> fig(n);
    for(int i=0; i<n; i++)
        cin >> fig[i];
    int64_t jacina;
    cin >> jacina;
    sort(begin(fig),end(fig));
    int64_t l=1, d=n; //maksimalno mozemo n igraca da imamo sa po jednom figuricom
    int64_t brIgraca,razlika;
    while(l<=d){
        int64_t s=l+(d-l)/2;
        int64_t tmprazlika = tempRazlIgraca(fig,n,s);
        if(tmprazlika<=jacina){
            l=s+1;
            brIgraca=s;
            razlika = tmprazlika;
        }else
            d=s-1;
    }
    cout << brIgraca << ' ' << razlika << endl;

    return 0;
}


/*
 neka nam je dato 5 figurica i granica>
 5
 5 4 2 7 3
 15
 potrebno je naci najveci br igraca tako da razlika izmedju svih figurica izmedju ta dva igraca ne predju granicu
 formula je:
     k*jacina1 - k*jacina2 <= granica
k(jacina1 - jacina 2) <= granica
biramo jacine do k jer ako naidjemo na ktog igraca koji ne ispunjava uslov nece ni oni koji su >k jer k nam je granica
ovo mozemo bin pr po resenju
 */
