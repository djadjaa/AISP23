#include <bits/stdc++.h>
using namespace std;

int main(){

    string str;
    cin >> str;
    int numunits=0;
    for(char c:str){
        if(c=='1')
            numunits++;
    }
    cout << (numunits*(numunits-1))/2 << endl;
    return 0;
}

/*
 neka nam je dat string 01001001
 izbrojacemo koliko jedinica ima, pa potom broj kombinacija stringova gde se krece i zavrsava od jedinice
 br jedinica: 3
 izvlacimo stringove sa 2 jedinice:
 3(3-1) = 3*2 = 6
 6/2 = 3 - ukupno tri stringa
 */
