#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define qp queue<pll>
#define pb push_back
#define mp make_pair
#define f first
#define s second 

char arr[103][103];

void solve(){
    ios;
    int m, n, q; cin >> m >> n >> q;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    cout << m << " " << n << " " << q << '\n';
    while(q--){
        int r, c; cin >> r >> c;
        r++; c++;
        char pos = arr[r][c];
        int ans = 0, record;
        bool check = false;
        for(int k=1; k<100; k+=2){
            for(int i = r-ans; i<r-ans+k; i++){
                for(int j = c-ans; j<c-ans+k; j++){
                    if(arr[i][j]!=pos){
                        check = true;
                        break;
                    }
                }
                if(check) break;
            }
            if(check) break;
            ans++;
            record = k;
        }
        cout << record << '\n';
    }
}

int main(){
    ios;
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}