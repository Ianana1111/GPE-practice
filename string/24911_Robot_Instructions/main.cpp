#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
    int q; cin >> q;
    string rec = "";
    int ans = 0;
    while(q--){
        string s; cin >> s;
        if(s[0]=='L'){
            rec+=s[0];
            ans--;
        }else if(s[0]=='R'){
            rec+=s[0];
            ans++;
        }else{
            string d; cin >> d;
            int num; cin >> num;
            if(rec[num-1]=='L'){
                ans--;
                rec+='L';
            }else{
                ans++;
                rec+='R';
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios;
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}