#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define vll vector<pll>
#define mp make_pair
#define pb push_back
#define f first 
#define s second

void solve(){
    int n; cin >> n;
    int x, y;
    vll record;
    while(cin >> x >> y){
        if(x==0 && y==0) break;
        record.pb(mp(x, y));
    }
    sort(record.begin(), record.end());
    ll now = 0, pos=0, mx=-1000000;
    vll ans;
    int size = record.size();
    while(now<n){
        for(int i=pos; i<size; i++){
            if(record[i].f<=now){
                if(record[i].s>mx){
                    mx = record[i].s;
                    pos = i;
                }
            }else
                break;
        }
        if(mx==now){
            cout << 0 << '\n';
            return;
        }
        ans.pb(record[pos]);
        now = mx;
    }
    size = ans.size();
    cout << size << '\n';
    for(int i=0; i<size; i++){
        cout << ans[i].f << " " << ans[i].s << '\n';
    }
}

int main(){
    ios;
    int n; cin >> n;
    string line;
    getline(cin, line);
    getline(cin, line);
    while(n--){
        solve();
        if(n) cout << '\n';
    }
    return 0;
}
// 10
// -6, 10, -5 4, -3 1, -2 7, 2 10, 3 15, 

// -5 -3, -1 0, 2 5