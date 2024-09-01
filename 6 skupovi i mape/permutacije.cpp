#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    multiset<int64_t> s1;
    multiset<int64_t> s2;
    int64_t x;
    while(n--){
        cin >> x;
        s1.insert(x);
    }
    cin >> n;
    while(n--){
        cin >> x;
        s2.insert(x);
    }
    cout << (s1 == s2 ? "da\n" : "ne\n");
    return 0;
}
