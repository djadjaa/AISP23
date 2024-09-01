#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    multiset<int64_t> array;
    int64_t x;
    while(n--){
        cin >> x;
        array.insert(x);
    }
    for(auto a:array){
        cout << a << endl;
    }
    return 0;
}
