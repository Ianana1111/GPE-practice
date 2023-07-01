#include<bits/stdc++.h>
using namespace std;
#define ios ios:sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
    int dp[28][28][353];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=26; i++) dp[i][1][i] = 1;
    for(int i=1; i<=26; i++){
        for(int j=1; j<=i; j++){
            for(int k=1; k<=351; k++){
                dp[i][j][k]+=dp[i-1][j][k];
                if(k>=i) dp[i][j][k]+=dp[i-1][j-1][k-i];
            }
        }
    }
    int l, s, count=1;
    while(cin >> l >> s && l && s){
        cout << "Case " << count++ << ": ";
        if(l>26 || s>351) cout << 0 << '\n';
        else cout << dp[26][l][s] << '\n';
    }
    return 0;
}