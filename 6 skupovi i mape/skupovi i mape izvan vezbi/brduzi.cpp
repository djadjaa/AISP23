#include <bits/stdc++.h>

using namespace std;

struct Duz{
    int64_t x1,y1,z1,x2,y2,z2;
    Duz(int x1, int y1, int z1, int x2, int y2, int z2)
        : x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2) {}

    // Метод за рачунање дужине дужи
    double length() const {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    }

    // Поређење за коришћење у std::set
    bool operator<(const Duz& other) const {
        return length() < other.length();
    }
};

int main(){

    int64_t x1,y1,z1,x2,y2,z2;
    int64_t n;
    cin >> n;
    set<double> duzine;
    for(int i=0; i<n; i++){
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        Duz duz(x1,y1,z1,x1,y2,z2);
        duzine.insert(duz.length());
    }
    cout << duzine.size() << endl;
    return 0;
}
