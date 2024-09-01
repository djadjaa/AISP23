#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;

    vector<int64_t> kasnjenja(n);
    vector<int64_t> a(n);
    for (int64_t i = 0; i < n; i++) {
        cin >> a[i];
        kasnjenja[i] = a[i] - i;
    }
    sort(begin(kasnjenja),end(kasnjenja));
    int64_t numPair=0;
    for(int i=0; i<n; i++){
        auto it = lower_bound(begin(kasnjenja),end(kasnjenja), a[i] - i); //trazimo broj koji je <= a[j]-j
        it = kasnjenja.erase(it); //brisemo ga da ne bi bilo ponovnog racuna; sledbenik u nizu kasnjenja
        numPair += distance(it, end(kasnjenja));
    }
    cout << numPair << endl;
    return 0;
}
