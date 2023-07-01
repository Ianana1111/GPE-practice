#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

char arr[103][103];

void dfs(int x, int y){
    arr[x][y] = '*';
    if(arr[x-1][y]=='@')
        dfs(x-1, y);
    if(arr[x-1][y+1]=='@')
        dfs(x-1, y+1);
    if(arr[x][y+1]=='@')
        dfs(x, y+1);
    if(arr[x+1][y+1]=='@')
        dfs(x+1, y+1);
    if(arr[x+1][y]=='@')
        dfs(x+1, y);
    if(arr[x+1][y-1]=='@')
        dfs(x+1, y-1);
    if(arr[x][y-1]=='@')
        dfs(x, y-1);
    if(arr[x-1][y-1]=='@')
        dfs(x-1, y-1);
}

int main(){
    ios;
    int x, y;
    while(cin >> x >> y){
        memset(arr, '#', sizeof(arr));
        if(x==0 && y==0) return 0;
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
                cin >> arr[i][j];
            }  
        }
        int ans = 0;
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
                if(arr[i][j]=='@'){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        
        cout << ans << '\n';
    }
}