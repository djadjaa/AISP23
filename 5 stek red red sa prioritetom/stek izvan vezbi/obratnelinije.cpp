#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    stack<string> linije;
    while(cin >> s){
        linije.push(s);
    }
    while(!linije.empty()){
        cout << linije.top() << endl;
        linije.pop();
    }

    return 0;
}

/*
 posto se stek zasniva na LIFO strukturi, ubacicemo ove stringove u stek i citamo ih od pocetka
 */
