#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

int prime[10] = {2, 3, 5, 7};

int main(){
    //ios;
    vl rec;
    bool check[10001];
    memset(check, false, sizeof(check));
    for(int i=0; i<4; i++){
        for(int j=2; j<=100; j++){
            if(j%prime[i]==0 && j/prime[i]!=1) check[j] = true;
        }
    }
    for(int i=2; i<=100; i++) if(!check[i]) rec.pb(i);
    
    int size = rec.size();
    for(int i=0; i<size; i++){
        for(int j=2; j<=10000; j++){
            if(j%rec[i]==0 && j/rec[i]!=1) check[j] = true;
        }
    }
    for(int i=100; i<=10000; i++) if(!check[i]) rec.pb(i);
    size = rec.size();
    int n; 
    while(cin >> n){
        if(n==0) return 0;
        if(n==2 || n==3){
            cout << 1 << '\n';
            continue;
        }
        int i=0, j=1, record = 0;
        int ans = rec[i]+rec[j];
        while(1){
            if(ans==n){
                record++;
                if(i==j) break;
                j++;
                ans+=rec[j];
            }else if(ans < n){
                j++;
                if(j==size) break;
                ans+=rec[j];
            }else{
                ans-=rec[i];
                i++;
            }
            if(rec[i]>n) break;
        }
        cout << record << '\n';
    }
    return 0;
} //2 3 5 7 11 13 17 19
// 9931 9973     10000