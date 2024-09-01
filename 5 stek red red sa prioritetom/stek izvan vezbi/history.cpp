#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    stack<string> sajt;
    while(cin >> s){
        if(s=="back"){

            if(sajt.empty()){
                cout << "-" << endl;
            }else{
                sajt.pop();
                if(sajt.empty()){
                    cout << "-" << endl;
                }else{
                    cout << sajt.top() << endl;
                }
            }
            /*
            sajt.pop();
            if(sajt.empty()){
               sajt.push("-");
            }
            cout << sajt.top() << endl;*/
        }else{
            sajt.push(s);
            cout << sajt.top() << endl;
        }
    }


    return 0;
}
