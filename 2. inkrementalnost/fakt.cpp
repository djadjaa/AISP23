#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    long long product = 1;
    for(int64_t i=1; i<=n; i++){
        product *= i;
        cout << product << endl;
    }

    return 0;
}
