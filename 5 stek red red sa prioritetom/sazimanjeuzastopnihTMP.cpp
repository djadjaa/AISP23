У употреби је 81% меморијског простора …
Ако останете без меморијског простора, нећете моћи да правите, мењате и отпремате фајлове. Набавите 100 GB меморијског простора за 210 RSD 55 RSD месечно за 3 месеца.

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int k,n;
    cin>>k>>n;

    vector<int> stekVrednost;
    vector<int> stekPonavljanja;

    while(n>0){
        int x;
        cin>>x;

        if(!stekPonavljanja.empty() && x!=stekVrednost.back() && stekPonavljanja.back()>=k){
            stekPonavljanja.pop_back();
            stekVrednost.pop_back();
        }

        if(stekPonavljanja.empty() || stekVrednost.back()!=x){
            stekPonavljanja.push_back(1);
            stekVrednost.push_back(x);
        } else {
            stekPonavljanja.back()++;
        }
        n--;
    }

    if(stekVrednost.size()!=0 && stekPonavljanja.back()>=k){
        stekPonavljanja.pop_back();
        stekVrednost.pop_back();
    }

    for(int i=0;i<stekVrednost.size();i++){
        while(stekPonavljanja[i]>0){
            cout<<stekVrednost[i]<<" ";
            stekPonavljanja[i]--;
        }
    }
    cout<<"\n";
}
