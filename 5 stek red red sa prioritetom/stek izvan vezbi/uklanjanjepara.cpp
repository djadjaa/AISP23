#include <bits/stdc++.h>

using namespace std;

int main(){

    char c;
    string babadui;

    while(cin >> c){
        if(!babadui.empty()){
            if(c==babadui.back()){
                babadui.pop_back();
            }else{
                babadui.push_back(c);
            }
        }else{
            babadui.push_back(c);
        }
    }

    /*
    while(!babadui.empty()){
        cout << babadui.top();
        babadui.pop();
    }*/
    cout << babadui << endl;
    return 0;
}
