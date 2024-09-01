#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    queue <int64_t> red2,red3,red5;
    red2.push(2);
    red3.push(3);
    red5.push(5);
    int64_t tmp=1;
    for(int i=0; i<n; i++){
        tmp = min({red2.front(), red3.front(), red5.front()});
        red2.push(2*tmp);
        red3.push(3*tmp);
        red5.push(5*tmp);
        while(red2.front() == tmp)
            red2.pop();
        while(red3.front() == tmp)
            red3.pop();
        while(red5.front() == tmp)
            red5.pop();
    }
    cout << tmp << endl;
    return 0;
}

/*
 prvo cemo ubaciti nase delioce u redove:
 red2: 2
 red3: 3
 red5: 5
 pocecemo od prvog elementa do ntog
 t=1
 odredjujemo minimum od nasih elemenata koji ce nam biti t, mnozimo ga sa deliocima i duplikat uklanjamo sa vrha kako bismo dosli do ntog elementa (front deque)
 */
