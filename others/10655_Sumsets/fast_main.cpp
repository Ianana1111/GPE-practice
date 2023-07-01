#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define mp make_pair
#define f first 
#define s second

int main(){
    ios;
    ll n;
    while(cin >> n && n){
        vl num(n+1);
        map<ll, pll> rec;
        for(int i=1; i<=n; i++)
            cin >> num[i];
        sort(num.begin()+1, num.end());
        // for(auto &x : num) cout << x << " ";
        // cout <<'\n';

        for(int i=1; i<=n-1; i++){
            for(int j=i+1; j<=n; j++){
                ll sum = num[i]+num[j];
                rec[sum] = mp(i, j);
            }
        }
        // for(auto const &iter : rec){
        //     cout << iter.f <<  " ";
        // }
        // cout << '\n';
        bool check = false;
        ll mx = -1;
        for(int i=n; i>=2; i--){
            for(int j=i-1; j>=1; j--){
                ll dif = num[i] - num[j];
                if(rec.count(dif)){
                    ll x = rec[dif].f, y = rec[dif].s;
                    if(x!=i && x!=j && y!=i && y!=j){
                        mx = max(mx, num[i]);
                        check = true;
                    }
                }
            }
        }
        if(!check) cout << "no solution" << '\n';
        else cout << mx << '\n';
    }
}
