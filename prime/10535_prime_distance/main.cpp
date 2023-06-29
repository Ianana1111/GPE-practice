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

bool check[47000];
vl arr;
vl prime;

void primes(){
    for(int i=4; i<47000; i+=2) check[i] = 1;
    arr.pb(2);
    for(int i=3; i<47000; i+=2){
        if(!check[i]){
            arr.pb(i);
            for(int j=i*2; j<47000; j+=i)
                check[j]=1;
        }
    }
}

void calcu(ll a, ll b){
    prime.clear();
    for(ll i=a; i<=b; i++){
        if(i<47000){
            if(!check[i]) prime.pb(i);
        }else{
            ll size = arr.size();
            bool test = false;
            for(ll j=0; j<size && arr[j]<i; j++){
                if(i%arr[j]==0) {
                    test = true;
                    break;
                }
            }
            if(!test) prime.pb(i);
        }
    }
}

int main(){
    ios;
    memset(check, 0, sizeof(check));
    primes();
    ll a, b;
    while(cin >> a >> b){
        calcu(a, b);
        int size = prime.size();
        pll rec[2];
        ll mx = -1, mn = 1e9;
        if(size<=1){
            cout << "There are no adjacent primes." << '\n';
            continue;
        } 
        for(ll i=1; i<size; i++){
            if(prime[i]-prime[i-1]>mx){
                mx = prime[i]-prime[i-1];
                rec[0] = mp(prime[i-1], prime[i]);
            }
            if(prime[i]-prime[i-1]<mn){
                mn = prime[i]-prime[i-1];
                rec[1] = mp(prime[i-1], prime[i]);
            }
        }
        cout << rec[1].f << ',' << rec[1].s << " are closest, ";
        cout << rec[0].f << ',' << rec[0].s << " are most distant."<< '\n';
        
    }
    return 0;
}