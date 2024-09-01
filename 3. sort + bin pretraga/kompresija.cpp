#include <bits/stdc++.h>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<int64_t> tmp = a;
    sort(begin(tmp),end(tmp));
    for(int i=0; i<n; i++){
        auto it = lower_bound(begin(tmp),end(tmp),a[i]);
        cout << it-begin(tmp) << ' ';
    }
    cout << endl;
    return 0;
}
/*
 neka nam je dat sledeći niz:
 4 -20 8 4 6

 ideja je sledeća:
 sortiraćemo i tada imamo dva niza:

 4 -20 8 4 6
 -20 4 4 6 8

 zatim u sortiranom nizu trazimo element strogo manji od elementa prvobitnog niza:

1) 4
lowerbound(4) = -20

tada trazimo poziciju gde se -20 nalazi u prvobitnom nizu i to je pozicija 1

2) -20
lowerbound(-20) = 0

-||- 0 -||-, posto je nema, pozicija je 0

3) 8
lowerbound(8) = 6

-||- 6 -||- i to je pozicija 4

4) 4
lowerbound(4) = -20

ista prica kao pod 1)

5) 6
lowerbound(6) = 4

-||- 4 -|| - i to je pozicija 3

=> 1 0 4 1 3
 */
