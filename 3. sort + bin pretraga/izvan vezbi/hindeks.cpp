#include <bits/stdc++.h>
using namespace std;

int64_t rez(vector<int64_t>citati, int64_t brRadova){
    int64_t l=0, d=brRadova-1; //posmatracemo radove jer mora da se ispuni uslov koliko radova barem toliko citata
    while(l<=d){
        int64_t s=(l+d)/2; //potencijalni kandidat za broj citata
        if(citati[s]==brRadova-s)
            return citati[s];
        else if(citati[s]<brRadova-s)
            l=s+1;
        else
            d=s-1;
    }
    return brRadova-l;
}

int main(){

    int64_t brRadova;
    cin >> brRadova;
    vector<int64_t> citati(brRadova);
    for(int i=0; i<brRadova; i++)
        cin >> citati[i];
    sort(begin(citati),end(citati));
    cout << rez(citati,brRadova) << endl;
    return 0;
}
