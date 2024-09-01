#include <bits/stdc++.h>

using namespace std;

int main(){

    int k;
    cin >> k;
    vector<string> str;
    string s;
    while(getline(cin,s)){
        str.push_back(s);
    }
    int start = max(0, static_cast<int>(str.size()) - k);
    for(int i=start; i<str.size(); i++){
        cout << str[i] << endl;
    }

    return 0;
}
