#include<bits/stdc++.h>
using namespace std;
#define ios ios:;sync_with_sstdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back

int main(){
    int x, y;
    int map[102][102];
    int max_map[102][102];
    while(cin >> x >> y && (x||y)){
        memset(max_map, 0, sizeof(max_map));
        memset(map, 0, sizeof(map));
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
                cin >> map[i][j];
                if(map[i][j]==0)
                    max_map[i][j] = max_map[i-1][j] + 1;
                else   
                    max_map[i][j] = 0;
            }
        }
        for(int i=1; i<=x; i++) 
            max_map[i][0] = max_map[i][y+1] = -1;
        
        int ans = 0;
        for(int i=1; i<=x ; i++){
            vl tmp;
            int r[102], l[102];
            memset(r, 0, sizeof(r));
            memset(l, 0, sizeof(l));
            for(int j=1; j<=y+1; j++){
                while(tmp.size()>0 && max_map[i][tmp.back()] > max_map[i][j]){
                    r[tmp.back()] = j;
                    tmp.pop_back();
                }
                tmp.pb(j);
            }
            tmp.clear();
            for(int j=y; j>=0; j--){
                while(tmp.size()>0 && max_map[i][tmp.back()] > max_map[i][j]){
                    l[tmp.back()] = j;
                    tmp.pop_back();
                }
                tmp.pb(j);
            }
            for(int j=1; j<=y; j++)
                ans = max(ans, max_map[i][j]*(r[j]-l[j]-1));
        }
        cout << ans << '\n';
    }
}