#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int64_t> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    int l=0, d=n-1; //particionisacemo ceo niz a posle idemo segment po segment
    while(l<=d){
        //particionisi niz u odnosu na pivot
        //pivot se nakon toga nalazi na poziciji s
        int s=l;
        for(int i=l+1; i<=d; i++){
            if(v[i]>=v[l]){ //ako je element veci od pivota
                s++;
                swap(v[i],v[s]);
            }
        }
        swap(v[l],v[s]); //doveli smo pivot na svoje mesto
        if(s<k)
            l=s+1;
        else if(s>k)
            l=s-1;
        else
            break; //zavrsili smo algoritam, nasli pivot koji se nalazi na odgovarajucoj poziciji
    }
    int sum=0;
    for(int i=0; i<k; i++)
        sum += v[i];
    cout << sum << endl;
    return 0;
}
/*
 quick select:
 5 2 10 3 8
 k=3
 od nas se trazi element koji se nalazi na ktom mestu posle sortiranja
 => 2 3 5 8 10

 odabracemo pivot tako da elementi manji od njega su sa leve, a veci od njega sa desne strane -> isto uzimamo pivot za levu i desnu stranu

 razlika ce biti samo u tome sto cemo ici u jednu polovinu niza, gde nam se i nalazi  potencijalni kti element
 želimo obrnuti polovinu tako da sa leve str budu elementi veci od ktog i nadjemo zbir k najboljih

 s nam ukazuje na to gde se nalazi poslednji element <= pivota (od obradjenih)  pa tako imamo sledecu invarijantu petlje:
 segmenti:
 [l,s] - elementi <= pivot
 [s,i] - elementi > pivot
 [i,d] - neobradjeni

 */
