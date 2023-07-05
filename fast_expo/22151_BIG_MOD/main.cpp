#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

ll fast_epo(ll b, ll p, ll m){
    ll a = b, ans = 1;
    for(;p; a = (a*a)%m, p>>=1)
        if(p&1) ans = (ans*a)%m;
    return ans;
}

int main(){
    ios;
    ll b, p, m;
    while(cin >> b){
        cin >> p >> m;
        ll ans = fast_epo(b, p, m);
        cout << ans << '\n';
    }
    return 0;
}