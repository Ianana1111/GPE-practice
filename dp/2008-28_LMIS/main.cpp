#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pb push_back

int len[10];
vl num;
vvl tot;
int ans;

void find(int pos, vl rec, int l, int n){
    if(rec.size()==l){
        tot.pb(rec);
        ans++;
        return;
    }
    for(int i = pos; i<n; i++){
        if(rec.empty()){
            rec.pb(num[i]);
            find(i+1, rec, l, n);
            rec.pop_back();
        }else{
            if(num[i]>rec.back()){
                rec.pb(num[i]);
                find(i+1, rec, l, n);
                rec.pop_back();
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    num.clear();
    num.resize(n);
    for(int i=0; i<n; i++) cin >> num[i];

    vl tmp;
    int mx=0;
    ans = 0;
    tot.clear();

    for(int i=0; i<n; i++){
        if(tmp.empty()){
            tmp.pb(num[i]);
            mx++;
        }else{
            if(num[i]>tmp.back()){
                tmp.pb(num[i]);
                mx++;
            }else{
                int pos = lower_bound(tmp.begin(), tmp.end(), num[i])-tmp.begin();
                tmp[pos] = num[i];
            }
        }
    }
    find(0, {}, mx, n);
    cout << ans << '\n';
    for(int i=0; i<ans; i++){
        for(auto c:tot[i]){
            cout << c << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios;
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}
