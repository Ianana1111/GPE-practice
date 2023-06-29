#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pb push_back

void solve(){
    ll x, y; cin >> x >> y;
    vvl path(x, vl(y));
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++){
            cin >> path[i][j];
         }   
    
    // for(int i=0; i<x; i++)
    //     for(int j=0; j<y; j++)
    //         cout << path[i][j] << " \n"[j==y-1];
    vvl dp(x, vl(y));
    dp[0][0] = path[0][0];
    for(int i=0 ; i<x; i++){
        for(int j=0; j<y; j++){
            if(i==0 && j==0) continue;
            else if(i==0) dp[i][j] = path[i][j]+dp[i][j-1];
            else if(j==0) dp[i][j] = path[i][j]+dp[i-1][j];
            else dp[i][j] = path[i][j]+min(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[x-1][y-1] << '\n';
}

int main(){
    ios;
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}
// 12 1 2 3 4 6 12