#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    int64_t num;
    set<int64_t>ip;
    while(n--){
        cin >> num;
        ip.insert(num);
    }
    cout << ip.size() << endl;

    return 0;
}
