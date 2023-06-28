#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

// 1 2 3 4 5

ll find_max(vl num, string ope){
    ll size = ope.size();
    ll rec = num[0];
    vl tot;
    for(int i=0; i<size; i++){
        if(ope[i]=='+'){
            rec+=num[i+1];
        }else{
            tot.pb(rec);
            rec = num[i+1];
        }
    }
    tot.pb(rec);
    size = tot.size();
    ll ans = 1;
    for(int i=0; i<size; i++) ans *= tot[i];
    return ans;
}

ll find_min(vl num, string ope){
    ll size = ope.size();
    ll rec = num[0];
    vl tot;
    for(int i=0; i<size; i++){
        if(ope[i]=='*'){
            rec*=num[i+1];
        }else{
            tot.pb(rec);
            rec = num[i+1];
        }
    }
    tot.pb(rec);
    size = tot.size();
    ll ans = 0;
    for(int i=0; i<size; i++) ans += tot[i];
    return ans;
}

void solve(){
    string s; cin >> s;
    vl num;
    string ope = "";
    ll size = s.size();
    int tmp = 0;
    for(int i=0; i<size; i++){
        if(isdigit(s[i])){
            tmp*=10;
            tmp+=(s[i]-'0');
        }else{
            ope+=s[i];
            num.pb(tmp);
            tmp=0;
        }
    }
    num.pb(tmp);
    ll mx = find_max(num, ope);
    ll mn = find_min(num, ope);
    cout << "The maximum and minimum are ";
    cout << mx << " and " << mn << '.' << '\n';
}

int main(){
    ios;
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}