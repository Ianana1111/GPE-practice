#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define ll long long

int main(){
    int dp[10001];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for(int i=4; i<=10000; i++){
        dp[i]=2*dp[i-4]+3;
    }
    int n;
    while(cin >> n){
        cout << dp[n] << '\n';
    }
    return 0;
}