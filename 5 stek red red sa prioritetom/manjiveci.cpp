#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    int64_t x;
    deque<int64_t> array;
    cin >> x;
    array.push_back(x);
    for(int i=1; i<n; i++){
        cin >> x;
        if(x>array.back())
            array.push_back(x);
        else
            array.push_front(x);
    }
    for(int64_t x : array)
        cout << x << ' ';
    cout << endl;
    return 0;
}

/*
 red sa dva kraja:
 levo idu manji, desno veci brojevi; manji idu na pocetak a veci na kraj
 */
