#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long

int main(){
    ll arr[1002];
    arr[1] = 1;
    for(int i=2; i<=1000000000000; i++){
        arr[i] = (3*arr[i-1]+4)%1000000009;
    }
    ll input;
    while(cin >> input){
        cout << arr[input] << '\n';
    }
    return 0;
}