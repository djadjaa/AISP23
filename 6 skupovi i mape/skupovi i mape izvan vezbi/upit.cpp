#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n,k;
    cin >> n >> k;
    string s;
    int64_t x;
    map<string,int64_t> korisnici;
    map<int64_t,int64_t> numOcc;
    numOcc[0]=k;
    for(int i=0; i<n; i++){
        cin >> s >> x;
        if(s=="upit"){
            cout << numOcc[x] << endl;
        }else{
            numOcc[korisnici[s]]--;
            korisnici[s]+=x;
            numOcc[korisnici[s]]++;
        }
    }

    return 0;
}
/*
imamo 4 korisnika koji imaju 0 dinara
1) marko 2 => numOcc[korisnici[marko]]-- = numOcc[0]=3 (ovo vazi ako i samo ako se nalazi uveliko u mapi); korisnici[marko]=2; numOcc[2]=1;
2) milan 5 => numOcc[korisnici[milan]]--= numOcc[0]=2; korisnici[milan]=5; numOcc[5]=1;
3) dragana 4 => -||- = numOcc[0]=1 ; korisnici[dragana]=4; numOcc[4]=1;
4) milan -1 => numOcc[korisnici[milan]]--=numOcc[5]=0 (nalazi se u mapi); korisnici[milan]=4; numOcc[4]=2;
 */
