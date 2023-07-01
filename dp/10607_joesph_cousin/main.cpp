#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back



int main(){

    
    bool check[40001];
    vl arr;  // 這位啥不能放在check前面，沙小
    
    memset(check, false, sizeof(check));
    for(int i=2; i<=40001; i++){
        if(!check[i]){
            arr.pb(i);
            for(int j=i*2; j<=40001; j+=i)
                check[j] = true;
        }
    }
    //cout << check[2];
    for(int i=0; i<10; i++) cout << arr[i] << " ";
    //cout << arr[0] << " " << arr[1];
    int n;
    while(cin >> n && n){
        int ans=0;
        for(int i=2; i<=n; i++){
            ans = (ans+ arr[n-i])%i;
        }
        cout << ans+1 << '\n';
    }
}