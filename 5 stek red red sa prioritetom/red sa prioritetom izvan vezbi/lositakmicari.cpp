#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    int64_t n,k;
    cin >> k >> n;
    int64_t x;
    priority_queue<int64_t, deque<int64_t>> pq;
    for(int i=0; i<n; i++){
        cin >> x;
        if(i<k){
            cout << "0 ";
            pq.push(x);
        }else if(x<=pq.top()){
            pq.pop();
            pq.push(x);
            cout << "0 ";
        }else if(x>pq.top()){
            cout << "1 ";
        }
    }
    cout << endl;
    return 0;
}
