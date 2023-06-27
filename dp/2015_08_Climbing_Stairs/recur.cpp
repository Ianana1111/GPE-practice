#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
int ans = 0;

void recur(int n){
    if(n==0){
        ans++;
    }else if(n>0){
        for(int i=1; i<=2; i++){
            recur(n-i);
        }
    }
    return;
}

int main(){
    int n; cin >> n;
    recur(n);
    cout << ans << '\n';
}