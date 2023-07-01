#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

vl arr;
int check[45001];

int main(){
    ios;
    memset(check, 0, sizeof(check));
    for(int i=2; i<=45000; i++){
        if(!check[i]){
            arr.pb(i);
            for(int j = i*2; j<=45000; j+=i)
                check[j] = true;
        }
    }
    ll n, size = arr.size(); 
    //for(int i=0; i<size; i++) cout << arr[i] << " \n"[i==size-1];
    while(cin >> n && n){
        ll ans = 1;
        for(int i=0; i<size; i++){
            if(n%arr[i]==0){
                ll tmp = 0;
                while(n%arr[i]==0){
                    n/=arr[i];
                    tmp++;
                }
                ans*=(tmp+1);
            }
            if(n==1) break;
        }
        if(n>1) ans*=2;
        if(ans%2) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}