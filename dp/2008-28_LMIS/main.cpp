#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

int len[10];
vl num;

void find(int pos, vl rec, int l, int n){
    if(rec.size()==l){
        for(int i=0; i<l; i++){
            cout << rec[i] << " \n"[i==l-1];
        }
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
    int l=0;

    for(int i=0; i<n; i++){
        if(tmp.empty()){
            tmp.pb(num[i]);
            l++;
        }else{
            if(num[i]>tmp.back()){
                tmp.pb(num[i]);
                l++;
            }else{
                int pos = lower_bound(tmp.begin(), tmp.end(), num[i])-tmp.begin();
                tmp[pos] = num[i];
            }
        }
    }
    find(0, {}, l, n);
}

int main(){
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}
