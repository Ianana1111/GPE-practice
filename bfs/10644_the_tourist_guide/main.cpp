#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define vll vector<pll>
#define pb push_back
int mp[101][101];

int floyd(int a, int b, int n){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                mp[i][j] = max(mp[i][j], min(mp[i][k], mp[k][j]));
            }
        }
    }
    return mp[a][b];
}

int main(){
    ios;
    int n, k;
    int count = 1;
    while(cin >> n >> k && n && k){
        memset(mp, 0, sizeof(mp));
        for(int i=0; i<k; i++){
            int c1, c2, p; cin >> c1 >> c2 >> p;
            mp[c1][c2] = p;
            mp[c2][c1] = p;
        }
        int st, ed, num; cin >> st >> ed >> num;
        int ans = floyd(st, ed, n);
        ans--;
        cout << "Scenario #" << count++ << '\n';
        cout << "Minimum Number of Trips = ";
        if(num%ans){
            cout << num/ans+1 << '\n';
        }else{
            cout << num/ans << '\n';
        }
        cout << '\n';
    }
    return 0;
}