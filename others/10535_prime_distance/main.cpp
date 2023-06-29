#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

int rec[4] = {2, 3, 5 ,7};
bool check[10000002];

int main(){
    vl arr;
    memset(check, false, sizeof(check));
    for(int i=2; i<=100; i++){
        for(int j=0; j<4; j++){
            if(i%rec[j]==0 && i/rec[j]!=1) check[i]=true;
        }
        if(!check[i]) arr.pb(i);
    }
    int size = arr.size();
    for(int i=100; i<=1000; i++){
        for(int j=0; j<size; j++){
            if(i%arr[j]==0 && i/arr[j]!=1) check[i]=true;
        }
        if(!check[i]) arr.pb(i);
    }
    size = arr.size();
    for(int i=1000; i<=100000; i++){
        for(int j=0; j<size; j++){
            if(i%arr[j]==0 && i/arr[j]!=1) check[i]=true;
        }
        if(!check[i]) arr.pb(i);
    }
    ll a, b;
    while(cin >> a >> b){
        vl tmp;
        for(ll i=a; i<=b; i++){
            
        }
        int pos1 = lower_bound(arr.begin(), arr.end(), a)-arr.begin();
        int pos2 = lower_bound(arr.begin(), arr.end(), b)-arr.begin();
        ll mx = -1, mn = 100000;
        if(pos1==pos2){
            cout << "There are no adjacent primes." << '\n';
            continue;
        }
        if(b==arr[pos2]) pos2--;
        //for(int i=pos1; i<=pos2;)
        cout << pos1 << " " << pos2 << '\n';
    }
}