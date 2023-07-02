#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>

int dp[55][55];
int sticks[55];

int solve(int l, int r){
    if(~dp[l][r]) return dp[l][r];
    if(l+1==r) return dp[l][r] = 0;
    int cost = INT_MAX;
    for(int i=l+1; i<r; i++){
        int tmp = solve(l, i) + solve(i, r);
        cost = min(tmp, cost);
    }
    return dp[l][r] = cost + (sticks[r]-sticks[l]);
}

int main(){
    //ios;
    int len;
    while(cin >> len && len){
        memset(dp, -1, sizeof(dp));
        memset(sticks, 0, sizeof(sticks));
        int n; cin >> n;
        sticks[n+1] = len;
        for(int i=1; i<=n; i++){
            cin >> sticks[i];
        }
        cout << "The minimum cutting is " << solve(0, n+1) << ".\n";
    }
    return 0;
}