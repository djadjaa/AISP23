#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t k,n;
    cin >> k >> n;
    queue<double> array;
    double x,sum=0.0;
    for(int i=0; i<k; i++){
        cin >> x;
        array.push(x);
        sum += x;
    }
    int64_t pocetakSeg=0;
    double maxSum = sum;
    for(int i=1; i<=n-k; i++){
        cin >> x;
        double tmp = array.front();
        sum = sum - tmp + x;
        array.pop();
        array.push(x);
        if(sum >= maxSum){
            maxSum = sum;
            pocetakSeg = i;
        }
    }
    cout << pocetakSeg << endl;
    return 0;
}
