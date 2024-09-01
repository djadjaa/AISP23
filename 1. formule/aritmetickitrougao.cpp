#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int64_t k;
    for(int i=0; i<n; i++){
        cin >> k;
        cout << (2*k-1)*(k*k-k+1) << endl;
    }

    return 0;
}

/*
 k=1: 1
 k=2: 2 3 4
 k=3: 5 6 7 8 9
 posmatrajmo recimo k=3:
 primetimo da je prvi clan za 1 veci od poslednjeg clana kod k=2, koji predstavlja k²
 razlika izmedju susedna dva clana je 1
 broj sabiraka je 2k-1 => 2*3-1 = 6-1 = 5
 kada bismo sve ovo ubacili u formulu za racunanje sume aritmetickog niza i sredili isti izraz, dobili bismo formulu koja se nalazi u kodu gore
 */
