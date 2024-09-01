#include <bits/stdc++.h>

using namespace std;

string postfiks(string prefiks, string infiks){

    if(prefiks=="")
        return "";

    //koren je prvi karakter u prefiksnom stablu
    char koren = prefiks[0];
    int duzinaLevo = infiks.find(koren); //indeks prvog pojavljivanja korena
    string prefiksLevo = prefiks.substr(1,duzinaLevo); //pocinjemo od prve pozicije jer preskacemo koren sve do kraja njegove duzine
    string infiksLevo = infiks.substr(0,duzinaLevo);

    string prefiksDesno = prefiks.substr(1+duzinaLevo); //idemo do kraja
    string infiksDesno = infiks.substr(1+duzinaLevo);

    return postfiks(prefiksLevo, infiksLevo)+ postfiks(prefiksDesno, infiksDesno) + koren;
}

int main(){

    string prefiks, infiks;
    cin >> prefiks >> infiks;
    cout << postfiks( prefiks, infiks) << endl;

    return 0;
}

/*
 neka nam je dato stablo:

       a
    /     \
    b       c
    /       /\
   e        f  g

imamo tri vrste obilaska: KLD, LKD i LDK

KLD: a be cfg
LKD: be a fcg

mozemo pretpostaviti da je koren stabla prvi karakter KLD stringa, a da je levo podstablo string koji ide do prvog karaktera KLD stringa
ostatak je u tom slucaju desno podstablo
poredimo karaktere, odredjujemo im duzine i na osnovu infiksnog i prefiksnog levog dela dobijamo postfiksan levi deo (analogno i za desni)
spajanjem tih delova i korena dobijamo LDK obilazak

npr
be - preL
be - infL

cfg - preD
fcg - infD

odredjujemo koren, na osnovu njega odredjuemo rekurzivno
dalje levo i desno podstablo i spajamo polako

 */
