#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    string stack;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='i'){
            stack.push(s[i+1]);
        }
    }


    return 0;
}
