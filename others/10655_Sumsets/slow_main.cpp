#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
    ios;
    ll n;
    while(cin >> n && n){
        vector<ll> num(n+1);
        map<int, int> rec;
        for(int i=1; i<=n; i++){
            cin >> num[i];
            rec[num[i]] = i;
        }
        sort(num.begin(), num.end());
        bool check = false;
        ll mx = -1;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                for(int z=j+1; z<=n; z++){
                    ll sum = num[i]+num[j]+num[z];
                    if(rec.count(sum)){
                        if(rec[sum]!=i && rec[sum]!=j && rec[sum]!=z){
                            mx = max(mx, sum);
                            check = true;
                        }
                    }
                }
            }
        }
        if(!check) 
            cout << "no solution" << '\n';
        else  
            cout << mx << '\n';
    }
    return 0;
}