#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

bool isprime[1000001];
int sum[1000001];
vl arr;

int calcu(int i){
    int ans=0;
    while(i){
        ans+=(i%10);
        i/=10;
    }
    return ans;
}

bool check(int x){
    if(x<=1000) return !isprime[x];
    int size = arr.size();
    for(int i=0; i<size; i++){
        if(x%arr[i]==0) return false;
    }
    return true;
}

void solve(){
    int a, b; scanf("%d%d", &a, &b);
    printf("%d\n", sum[b]-sum[a-1]);
}

int main(){
    ios;
    memset(isprime, false, sizeof(isprime));
    arr.pb(2);
    for(int i=4; i<=1000000; i+=2) isprime[i] = true;
    for(int i=3; i<=1000; i+=2){
        if(!isprime[i]){
            arr.pb(i);
            for(int j=i*2; j<=1000; j+=i)
                isprime[j] = true;
        }
    }
    memset(sum, 0, sizeof(sum));
    for(int i=1; i<=1000000; i++){
        int num = calcu(i);
        if(!isprime[num] && check(i))
            sum[i] = sum[i-1]+1;
        else
            sum[i] = sum[i-1];
    }
    int n; scanf("%d", &n);
    while(n--){
        solve();
    }
}