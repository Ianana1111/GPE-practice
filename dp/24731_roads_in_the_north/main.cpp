#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define vll vector<pll>
#define pb push_back
#define mp make_pair
#define f first 
#define s second 

vll tree[10001];
int ans = 0;

int dfs(int tar, int from){
    int road1 = 0, tmp = 0;
    for(auto Pair: tree[tar]){
        if(Pair.f!=from){
            tmp = dfs(Pair.f, tar) + Pair.s;
            ans = max(ans, tmp+road1);
            road1 = max(road1, tmp);
        }
    }
    return road1;
}

int main(){
    while(1){
        for(int i=0; i<10001; i++) tree[i].clear();
        ans = 0;
        string s;
        getline(cin, s);
        while(s.size()>0 && !cin.eof()){
            int x, y, v;
            stringstream ss;
            ss<<s;
            ss>>x>>y>>v;
            tree[x].pb(mp(y, v));
            tree[y].pb(mp(x, v));
            getline(cin, s);
        }
        dfs(1, 0);
        cout << ans << '\n';
    }
    return 0;
}