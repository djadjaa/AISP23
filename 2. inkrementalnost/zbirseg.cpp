#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> zarade(n);
    for(int i=0; i<n; i++)
        cin >> zarade[i];
    vector<int64_t> newarray(n+1); //inicijalizovani su elementi na nulu
    for(int i=0; i<n; i++){
        newarray[i+1] = newarray[i]+zarade[i];
       // cout << newarray[i] << endl;
    }
    int64_t upiti;
    cin >> upiti;
    int64_t period1, period2;
    while(upiti--){
        cin >> period1 >> period2;
        cout << newarray[period2+1]-newarray[period1] << endl;
    }


    return 0;
}
