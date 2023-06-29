#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vl vector<ll>
#define pb push_back

int arr[50001];

int main(){
    memset(arr,0 ,sizeof(arr));
    vl prim;
    for(int i=2; i<=50000; i++){
        if(!arr[i]){
            prim.pb(i);
            for(int j=2*i; j<=50000; j+=i){
                arr[j]=1;
            }
        }
    }
    int n;
    while(cin >> n){
        if(!n) return 0;
        int m = n, count=0;
        vl influ;
        int size = prim.size();
        while(n>1 && count < size){
            if(n%prim[count]==0){
                influ.pb(prim[count]);
                while(n%prim[count]==0)
                    n/=prim[count];
            }
            count++;
        }
        cout << n << '\n';
        if(n>1) influ.pb(n);
        size = influ.size();
        ll ans = m;
        for(int i=0; i<size; i++){
            ans = ans/influ[i] * (influ[i]-1);
        }
        cout << ans << '\n';
    }
}