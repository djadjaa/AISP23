#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t m,n;
    cin >> m;
    vector<int64_t> male(m);
    for(int i=0; i<m; i++)
        cin >> male[i];
    sort(begin(male),end(male));
    cin >> n;
    vector<int64_t> female(n);
    for(int i=0; i<n; i++)
        cin >> female[i];
    sort(begin(female),end(female));
    int64_t minRazlika = INT_MAX,tmpRazlika;
    int64_t i=0, j=0;
    while(i<m && j<n){
        tmpRazlika = abs(male[i]-female[j]);
        minRazlika = min(minRazlika,tmpRazlika);
        if(male[i] < female[j]) //posto su nizovi sortirani na osnovu toga koji elem je manji uvecavamo pokazivac
            i++;
        else
            j++;
    }
    cout << minRazlika << endl;
    return 0;
}
