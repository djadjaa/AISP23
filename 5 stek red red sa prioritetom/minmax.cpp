#include <bits/stdc++.h>
using namespace std;

int main(){

    char c;
    stack<char>izraz;
    stack<char>op;
    int64_t a,b;
    while(cin >> c){
        if(c>='0' && c<='9'){
            izraz.push(c);
        }
        else if(c=='m' || c=='M'){
            op.push(c);
        }
        else if(c==')'){
            //cout << izraz.top() << endl;
            a=izraz.top();
            izraz.pop();
          // cout << izraz.top() << endl;
            b=izraz.top();
            izraz.pop();
            //porede se ascii kodovi; u oba slucaja bice isti rezultat
            if(op.top()=='m'){
                izraz.push(min(a,b));
            }else{ //(op.top()=='M')
                izraz.push(max(a,b));
            }
            op.pop();
        }
    }

    cout << izraz.top() << endl;

    return 0;
}

/*
 neka nam je dat izraz:
 ((3m5)M(4m(2M6)))
 u stek dodajemo polako karaktere ovog stringa dok ne dodjemo do zatvorene zagrade; sacuvacemo vrednosti izraza, poredimo ih i idemo dalje
 */
