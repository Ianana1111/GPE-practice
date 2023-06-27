#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define vcl vector<pair<char, ll>>
#define pcl pair<char, ll>
#define mp make_pair
#define pb push_back
#define s second 
#define f first 

char mapp[22][22];
bool visit[22][22];
map<char, ll> record;
int counting = 1;

bool compare(pcl a, pcl b){
    return a.s>b.s;
}

void dfs(int x, int y, char now){
    visit[x][y] = true;
    if(!visit[x-1][y] && mapp[x-1][y]==now){
        dfs(x-1, y, now);
    }else if(!visit[x][y+1] && mapp[x][y+1]==now){
        dfs(x, y+1, now);
    }else if(!visit[x+1][y] && mapp[x+1][y]==now){
        dfs(x+1, y, now);
    }else if(!visit[x][y-1] && mapp[x][y-1]==now){
        dfs(x, y-1, now);
    }
}


void solve(){
    int x, y; cin >> x >> y;
    memset(mapp,'#', sizeof(mapp));
    memset(visit, false, sizeof(visit));
    record.clear();
    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            cin >> mapp[i][j];
        }
    }
    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(!visit[i][j]){
                dfs(i, j, mapp[i][j]);
                if(record.count(mapp[i][j]))
                    record[mapp[i][j]]++;
                else
                    record[mapp[i][j]] = 1;
            }
        }
    }
    vcl ans;
    for(const auto &item: record){    // 這招不錯 把map放進vector去sort 方便多了
        ans.pb(item);
    }
    sort(ans.begin(), ans.end(), compare);
    int size = ans.size();
    
    cout << "World #" << counting++ << '\n';
    for(int i=0; i<size; i++){
        cout << ans[i].f << ": " << ans[i].s <<'\n';
    }
    return;
}

int main(){
    ios;
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}