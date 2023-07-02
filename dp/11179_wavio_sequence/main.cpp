#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

void LIS(vl rec, vl &pos, int n){
    vl tmp;
    for(int i=0; i<n; i++){
        if(tmp.empty()){
            tmp.pb(rec[i]);
            pos[i] = tmp.size();
        }
        else{
            if(rec[i]>tmp.back()){
                tmp.pb(rec[i]);
                pos[i] = tmp.size();
            }else{
                int now = lower_bound(tmp.begin(), tmp.end(), rec[i])-tmp.begin();
                tmp[now] = rec[i];
                pos[i] = now+1;
            }
        }
    }
}

int main(){
    ios;
    int n;
    while(cin >> n){
        vl rec(n), pos1(n), pos2(n);
        for(int i=0; i<n; i++) cin >> rec[i];
        LIS(rec, pos1, n);
        reverse(rec.begin(), rec.end());
        LIS(rec, pos2, n);
        reverse(pos2.begin(), pos2.end());
        int mx = -1;
        // for(int i=0; i<n; i++) cout << pos1[i] << " \n"[i==n-1];
        // for(int i=0; i<n; i++) cout << pos2[i] << " \n"[i==n-1];
        for(int i=0; i<n; i++){
            int tmp = min(pos1[i], pos2[i]);
            mx = max(mx, tmp);
        }
        cout << 2*(mx-1)+1 << '\n';
    }
    return 0;
}