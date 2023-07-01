#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll fastex(ll n){
    ll ans = 1;
    ll a = 3;
    for(; n; n>>=1, a = (a*a)%1000000009)
        if(n&1) ans = (ans*a)%1000000009;
    return ans;
}

int main(){
    ll n;
    while(cin >> n){
        ll ans = fastex(n);
        cout << ans-2 << '\n';
    }
}