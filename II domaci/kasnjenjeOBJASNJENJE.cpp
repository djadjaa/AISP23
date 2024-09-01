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
    for(int i=0; i<n; i++){
        cout << kasnjenja[i] << ' ';
    }
    cout << endl;
    int64_t numPair=0;
    for(int i=0; i<n; i++){
        auto it = lower_bound(begin(kasnjenja),end(kasnjenja), a[i] - i); //trazimo broj koji je <= a[j]-j
        cout << "pre brisanja: " << *it << endl;
        it = kasnjenja.erase(it); //brisemo ga da ne bi bilo ponovnog racuna; sledbenik u nizu kasnjenja
        numPair += distance(it, end(kasnjenja));
        cout << "posle brisanja: " << *it << endl;
        cout << "broj parova: " << numPair << endl;
        cout << endl;
    }
    cout << numPair << endl;
    return 0;
}

/*
     for (uint32_t i = 0; i < n; i++) {
        cin >> kasnjenja[i];
        vektor[i] = kasnjenja[i] - i;
    }

    sort(begin(vektor), end(vektor));
    uint64_t brojacParova = 0;
    for (uint32_t i = 0; i + 1 < n; i++) {

        auto it = lower_bound(begin(vektor), end(vektor), kasnjenja[i] - i);
        it = vektor.erase(it);
        brojacParova += std::distance(it, end(vektor));

    }
 */

/*
 6
2 4 1 6 5 8 - ocekivana kasnjenja
-1 1 2 3 3 3 - razlika u minutima

trazimo broj u razlikama za koji vazi uslov a[i]-a[j] <= i-j odnosno a[i]-i <= a[j]-j

pre brisanja: 2
posle brisanja: 3 - brisemo trazeni broj da ne bi bilo suvisnih racuna
broj parova: 3 - zaista imamo 3 parova gde je kasnjenje vece od ocekivanog: (0,1), (0,3), (0,5)

pre brisanja: 3
posle brisanja: 3
broj parova: 5 - (1,3), (1,5)

pre brisanja: -1
posle brisanja: 1
broj parova: 8 - (2,3), (2,4), (2,5)

pre brisanja: 3
posle brisanja: 3
broj parova: 9 -  (3,5)

pre brisanja: 1
posle brisanja: 3
broj parova: 10 - (4,5)

pre brisanja: 3
posle brisanja: 3
broj parova: 10

 */
