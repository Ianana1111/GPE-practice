#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

void find(ll n){
    if(n>=10000000){
        find(n/10000000);
        cout << " kuti";
        n%=10000000;
    }
    if(n>=100000){
        find(n/100000);
        cout << " lakh";
        n%=100000;
    }
    if(n>=1000){
        find(n/1000);
        cout << " hajar";
        n%=1000;
    }
    if(n>=100){
        find(n/100);
        cout << " shata";
        n%=100;
    }
    if(n) cout << " " << n;
}

int main(){
    ll n, t=1;
    while(cin >> n){
        cout << setw(4) << t++ << '.';
        if(n==0){
            cout << ' ' <<0;
        }else{
            find(n);
        }
        cout << '\n';
    }
}
// 1 4 7 6 5 6  