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
bool visit[103][103];
pll dir[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void solve(){
    int m, n, q;
    memset(arr, '#', sizeof(arr));
    memset(visit, false, sizeof(visit));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    while(q--){
        int r, c; cin >> r >> c; r++; c++;

        qp record;
        record.push(mp(r, c));
        char pos = arr[r][c];
        visit[r][c] = true;

        int ans = 0, count = 0, maxx = 1;
        while(!record.empty()){
            count++;
            pll now = record.front();
            record.pop();
            if(count==maxx){
                ans++;
                count = 0;
                maxx = (ans+1)*4;
            }
            for(int i=0; i<8; i++){
                if(!visit[now.f+dir[i].f][now.s+dir[i].s]){
                    if(arr[now.f+dir[i].f][now.s+dir[i].s] == pos){
                        record.push(mp(now.f+dir[i].f, now.s+dir[i].s));
                        visit[now.f+dir[i].f][now.s+dir[i].s] = true;
                    }else{
                        cout << ans << '\n';
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}