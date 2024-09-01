#include <bits/stdc++.h>
using namespace std;
void boj(map<int64_t, int64_t> &map_snaga, vector<int> &snageDesniSmer, vector<int> &pozicijeDesniSmer, int tekuca_pozicija, int tekuca_snaga, vector<int64_t> pozicije){

    int s = snageDesniSmer.size(); //dimenzija niza sa vojnicima koji idu desno
    int x=0; //konstanta za koju cemo izmeniti nas tekuci niz
    int dpoz = s-1; //tekuca pozicija vojnika koji ide desno
    //cout << "boj" << endl;
    for(int i = snageDesniSmer.size()-1; i >= 0; i--){
        if(tekuca_snaga > snageDesniSmer[i]){
            //tada umire vojnik desno i azurira se snaga levog
            x++;
            map_snaga[pozicijeDesniSmer[dpoz]] = 0;
            dpoz--;
            tekuca_snaga--;
            map_snaga[pozicije[tekuca_pozicija]] = tekuca_snaga;
        }
        else if(tekuca_snaga == snageDesniSmer[i]){
            //umiru oboje, azuriraju im se snage
            x++;
            //cout << Dindex[dpoz] << endl;
            map_snaga[pozicijeDesniSmer[dpoz]] = 0;
            dpoz--;
            tekuca_snaga = 0;
            map_snaga[pozicije[tekuca_pozicija]] = tekuca_snaga;
            break;
        }
        else{
           //umire vojnik levo (tekuci vojnik (ako su im razliciti smerovi)) i azurira se snaga desnog
            snageDesniSmer[i]--;
            map_snaga[pozicijeDesniSmer[dpoz]] = snageDesniSmer[i];
            tekuca_snaga = 0;
            map_snaga[pozicije[tekuca_pozicija]] = tekuca_snaga;
            break;
        }
    }
    if(x == s){
        snageDesniSmer.clear();
        pozicijeDesniSmer.clear();
    }
    else{
        snageDesniSmer.resize(s-x);
        pozicijeDesniSmer.resize(s-x);
    }
    return;
}


int main() {

    int64_t n;
    cin >> n;
    vector<int64_t> pozicije(n);
    map<int64_t,int64_t> map_pozicije;

    for(int i=0; i<n; i++){
        cin >> pozicije[i];
        map_pozicije[i] = pozicije[i];
    }

    vector<int64_t> snaga(n);
    map<int64_t,int64_t> map_snaga;

    for(int i=0; i<n; i++){
        cin >> snaga[i];
        map_snaga[pozicije[i]] = snaga[i];
    }

    string smer;
    map<int64_t,char> map_smer;

    cin >> smer;

    for(int i=0; i<n; i++)
        map_smer[pozicije[i]] = smer[i];

    sort(begin(pozicije),end(pozicije));

    vector<int> snageDesniSmer;
    vector<int> pozicijeDesniSmer;

    for(int i = 0; i < n; i++){
        if(map_smer[pozicije[i]] == 'D'){ //ako je desni smer
            snageDesniSmer.push_back(map_snaga[pozicije[i]]);
            pozicijeDesniSmer.push_back(pozicije[i]);
        }
        else{ //ako je levi
            if(snageDesniSmer.size() > 0) //ako postoji barem jedan vojnik koji ide u desno, krecemo u dvoboj sa ostalim ratnicima
                boj(map_snaga, snageDesniSmer, pozicijeDesniSmer, i, map_snaga[pozicije[i]], pozicije);
        }
    }

   // cout << "ovde ide resenje:" << endl;
    int indikator = 0;
    for(int i = 0; i < n; i++){
        if(map_snaga[map_pozicije[i]] > 0)
            cout << map_snaga[map_pozicije[i]] << " ";

        else
            indikator++;

    }
    //cout << mapp[3];

    //ako su svi pandrknuli
    if(indikator == n)
        cout << " ";

    return 0;
}
