#include <iostream>
#include <stdint.h>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    uint32_t n;
    cin >> n;

    vector <uint32_t> cene (n);
    uint32_t N = 1;
    for (uint32_t i = 0; i < n; i++) {
        cin >> cene[i];
        N = std::max(N, cene[i]);
    }

    vector <uint32_t> brojanje(N + 1, 0);
    for (uint32_t i = 0; i < n; i++) {
        brojanje[cene[i]]++;
    }

    if (N < n) {
        brojanje.resize(n + 1, 0);
    }
    for (uint32_t i = 1; i < n + 1; i++) {
        brojanje[i] += brojanje[i - 1];
    }

    uint32_t k;
    cin >> k;
    for (uint32_t i = 0; i < k; i++) {

        uint32_t a, b;
        cin >> a >> b;
        cout << brojanje[b] - (a > 0 ? brojanje[a - 1] : 0) << '\n';

    }
    return 0;

}
