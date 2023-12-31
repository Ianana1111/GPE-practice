#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pb push_back
#define s second 
#define f first

void solve(int n){
    ios;
    map<vl, ll> record;
    map<vl, ll>::iterator iter;
    ll mx = -1;
    for(int i=0; i<n; i++){
        vl frosh(5);
        for(int j=0; j<5; j++){
            cin >> frosh[j];
        }
        sort(frosh.begin(), frosh.end());
        if(record.count(frosh))
            record[frosh]++;
        else 
            record[frosh]=1;
        mx = max(mx, record[frosh]);
    }
    int ans = 0;
    for(auto &c : record){
        if(c.s == mx) ans+=c.s;
    }
    cout << ans << '\n';
}

int main(){
    int n; 
    while(cin >> n){
        if(n==0) return 0;
        solve(n);
    }
}
// 25 50 75
//      |      |      |      |