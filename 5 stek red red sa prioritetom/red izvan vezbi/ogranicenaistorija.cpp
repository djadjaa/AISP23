#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    string s;
    deque<string>hist;
    while(cin >> s){
        if(s=="back"){
            while(hist.size() > n){
                hist.pop_front();
            }
            if(hist.empty()){
                cout << "-" << endl;
            }else{
                hist.pop_back();
                if(hist.empty()){
                    cout << "-" << endl;
                }else{
                    cout << hist.back() << endl;
                }
            }
        }else{
            hist.push_back(s);
            cout << hist.back() << endl;
        }
    }


    return 0;
}
