#include <bits/stdc++.h>

using namespace std;

int main(){
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

    for(int i=0; i<n; i++){
        if(ratnici[i].smer == 'D'){
            if(ratnici[i+1].smer == 'L'){
                if(ratnici[i].snaga == ratnici[i+1].snaga){
                    preostali.erase(ratnici[i+1].snaga);
                    preostali.erase(ratnici[i].snaga);
                }
                else if(ratnici[i].snaga <= ratnici[i+1].snaga){
                    ratnici[i+1].snaga--;
                    preostali.erase(ratnici[i].snaga);
                }
                else{
                    ratnici[i].snaga--;
                    preostali.erase(ratnici[i+1].snaga);
                }
            }else{
                preostali.insert(ratnici[i].snaga);
            }
        }else{
            preostali.insert(ratnici[i].snaga);
        }
    }
}
