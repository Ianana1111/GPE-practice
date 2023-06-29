#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define vll vecotr<pll>
#define pb push_back
#define f first 
#define s second 
#define eps 1e-10
#define MAXN 1e+6

int coin[6] = {1, 2, 4, 10, 20, 40}; //100
int arr[6];

int main(){
    double tar;
    int change[101];
    memset(change, 0, sizeof(change));
    change[0] = 0;

    //用greedy因為店員錢幣數量是無限大，代表找錢會得到的數量
    for(int i=1; i<=100; i++){
        int tmp = i;
        for(int j=5; j>=0; j--){
            if(tmp<coin[j]) continue;
            change[i]+=(tmp/coin[j]);
            tmp%=coin[j];
        }
    }
    
    while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> tar){
        if(arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]==0);

        int tmp = (tar+eps)*100, tot=0; tmp/=5;
        for(int i=0; i<6; i++) tot+=(arr[i]*coin[i]);

        //有限背包問題
        int dp[10001];
        for(int i=1; i<=10000; i++) dp[i]=MAXN;
        //cout << dp[0] << " " << dp[1]<< '\n';
        dp[0] = 0;
        for(int i=0; i<6; i++){
            int num = min(arr[i], tot/coin[i]);
            for(int k=1; num>0; k<<=1){
                if(k>num) k = num;
                num-=k;
                for(int j=tot; j>=coin[i]*k; j--){
                    dp[j] = min(dp[j], dp[j-coin[i]*k]+k);
                }
            }
        }
        int ans = 100000;
        for(int i=tmp; i<=tot; i++) ans = min(ans, dp[i]+change[i-tmp]);
        cout << ans << '\n';
    }
}