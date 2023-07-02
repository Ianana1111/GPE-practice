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
    memset(isprime, true, sizeof(isprime));
    for(int i=2; i<=1000000; i++){
        if(isprime[i])
            for(int j=2; j*i<=1000000; j++)
                isprime[i*j] = false;
    }
        memset(sum, 0, sizeof(sum));
    for(int i=2; i<=1000000; i++){
        int num = calcu(i);
        if(isprime[num] && isprime[i])
            sum[i] = 1;
    }
    for(int i=1; i<=1000000; i++) sum[i]+=sum[i-1];
    int n; scanf("%d", &n);
    while(n--){
        solve();
    }
}