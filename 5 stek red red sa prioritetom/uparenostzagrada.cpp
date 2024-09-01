#include <bits/stdc++.h>

using namespace std;

bool uparene(const string& izraz){
    stack<char> zagrade;
    char otvorena;
    for(char c : izraz){
        if(c=='(' || c=='[' || c=='{'){
            zagrade.push(c);
        }
        else if(c==')' || c==']' || c=='}'){
            if(zagrade.empty())
                return false;
            otvorena = zagrade.top();
            cout << "otvorena: " << otvorena << endl;
            zagrade.pop();
        }
        if((c==')' && otvorena!='(') || (c==']' && otvorena!='[') || (c=='}' && otvorena!='{'))
            return false;
    }
    return zagrade.empty();
}

int main(){

    string izraz;
    cin >> izraz;
    if(uparene(izraz))
        cout << "da\n";
    else
        cout << "ne\n";

    return 0;
}

/*
 dat nam je string [3*(2+4)*5]
 idemo kroz svaki karakter
 ako je otvorena zagrada ubacujemo je u stek
 stek: [
 ...
 stek: [(
 ako je zatvorena, zapamticemo otvorenu zagradu i izabcujemo je sa steka -> tako u medjuvremenu praznimo stek
 otvorena : ( c= )
 poredimo da li uparene tako sto poredimo otvorenu zagradu sa zatvorenim da li su razlicite
 napomena: poslednji element je vrh steka
 */
