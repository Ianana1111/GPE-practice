#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

vl rec;
bool check[10001];

int main(){
    ios;
    memset(check, false, sizeof(check));
    for(int i=2; i<=10000; i++){
        if(!check[i]){
            rec.pb(i);
            for(int j=i*2; j<=10000; j+=i)
                check[j] = true;
        }
    }
    int size = rec.size();
    int n; 
    while(cin >> n && n){
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