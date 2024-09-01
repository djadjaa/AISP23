#include <bits/stdc++.h>

using namespace std;

int main(){

    map<string, int64_t> st;
    string s;
    while(getline(cin,s)){
        st[s]++;
    }
    for(auto student : st){
        if(student.second == 2){
            cout << student.first << endl;
        }
    }

    return 0;
}
