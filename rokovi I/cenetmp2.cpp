#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n;
    cin >> n;

    vector<uint32_t> cena(n);
    uint32_t maxdim = 1;

    for (uint32_t i = 0; i < n; i++) {
        cin >> cena[i];
        maxdim = max(maxdim, cena[i]);
    }

    vector<uint32_t> numProd(maxdim + 1, 0);

    for (uint32_t i = 0; i < n; i++)
        numProd[cena[i]]++;

    vector<uint32_t> prefiksni_zbir(n + 1, 0);
    prefiksni_zbir[0] = numProd[0];

    for (uint32_t i = 1; i <= maxdim; i++)
        prefiksni_zbir[i] = prefiksni_zbir[i - 1] + numProd[i];

    uint32_t upiti;
    cin >> upiti;

    while (upiti--) {
        uint32_t cena1, cena2;
        cin >> cena1 >> cena2;
        cout << prefiksni_zbir[cena2] - prefiksni_zbir[cena1 - 1] << endl;
    }

    return 0;
}
