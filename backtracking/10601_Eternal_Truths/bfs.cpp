#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define f first 
#define s second

char arr[307][307];
pll se[2];
pll dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(pll st, pll en){
    queue<int> X, Y, V;
    int dp[307][307][3] = {};
    int tx, ty, tv;
    for(int i=0; i<4; i++){
        tx = st.f+dir[i].f; ty = st.s+dir[i].s;
        if(arr[tx][ty]=='.'){
            dp[tx][ty][0] = 1;
            X.push(tx); Y.push(ty); V.push(0);
        }
    }
    while(!X.empty()){
        int x = X.front(), y = Y.front(), v = V.front();
        X.pop(); Y.pop(); V.pop();
        tv = (v+1)%3;
        for(int i=0; i<4; i++){
            bool check = false;
            tx = x; ty=y;
            for(int j=0; j<=tv; j++){
                tx += dir[i].f; ty += dir[i].s;
                if(arr[tx][ty]=='#') check = true;
            }
            if(!check){
                if(dp[tx][ty][tv]==0){
                    dp[tx][ty][tv] = dp[x][y][v] + 1;
                    X.push(tx); Y.push(ty); V.push(tv);
                }
                if(tx==en.f && ty==en.s){
                    return dp[tx][ty][tv];
                }
            }
        }
    }
    return -1;
}

void solve(){
    int x, y; cin >> x >> y;
    memset(arr, '#', sizeof(arr));
    for(int i=3; i<=x+2; i++){
        for(int j=3; j<=y+2; j++){
            cin >> arr[i][j];
            if(arr[i][j]=='S')
                se[0] = mp(i, j) ;
            if(arr[i][j]=='E')
                se[1] = mp(i, j);
        }
    }
    // arr[se[0].f][se[0].s] = '@';
    int ans = bfs(se[0], se[1]);
    if(ans==-1) cout << "NO" <<'\n';
    else cout << ans << '\n';
    return;
}

int main(){
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}