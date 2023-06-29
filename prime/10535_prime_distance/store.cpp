#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define f first 
#define s second 

int check[10000002];

int main(){
    vl arr;
    
    memset(check, 0, sizeof(check));
    for(int i=2; i<=50000; i++){
        if(!check[i]){
            arr.pb(i);
            for(int j=i; j<=50000; j+=i)
                check[j]=1;
        }
    }
    int size = arr.size();
    ll a, b;
    while(cin >> a >> b){
        for(int i=a; i<=b; i++){
            if(!check[i]){
                arr.pb(i);
                for(int j=i; j<=b; j+=i)
                    check[j]=1;
            }
        }
        int size = arr.size();
        int pos = lower_bound(arr.begin(), arr.end(), a)-arr.begin();
        pll rec[2];
        int mx = -1, mn = 1e+7;
        pos++;
        while(pos<size){
            if(arr[pos]<=b){
                if(arr[pos]-arr[pos-1]>mx){
                    mx = arr[pos]-arr[pos-1];
                    rec[0] = mp(arr[pos-1], arr[pos]);
                }
                if(arr[pos]-arr[pos-1]<mn){
                    mn = arr[pos]-arr[pos-1];
                    rec[1] = mp(arr[pos-1], arr[pos]);
                }
                pos++;
            }else
                break;
        }
        if(mx==-1) cout << "There are no adjacent primes." << '\n';
        else{
            cout << rec[1].f << ',' << rec[1].s << " are closest, ";
            cout << rec[0].f << ',' << rec[0].s << " are most distant."<< '\n';
        }
    }
    return 0;
}