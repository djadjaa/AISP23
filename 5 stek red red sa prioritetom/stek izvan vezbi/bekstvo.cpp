#include <bits/stdc++.h>
using namespace std;

char suprotan(char c){
    switch(c){
        case 'U':
            return 'D';
        case 'D':
            return 'U';
        case 'L':
            return 'R';
        case 'R':
            return 'L';
    }
    return 0;
}

int main(){

    string s;
    cin >> s;
    string stack;
    for(int i=0; i<s.size(); i++){
        if(suprotan(s[i])==stack.back() && !stack.empty())
            stack.pop_back();
        else
            stack.push_back(s[i]);
    }
    cout << stack << endl;
    return 0;
}
