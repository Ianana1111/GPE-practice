#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define f first 
#define s second 

char maze[12][12];
pll dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(pll now, pll end){
    int x = now.f, y = now.s;
    if(x == end.f && y == end.s){
        for(int i=1; i<=10; i++){
            for(int j=1; j<=10; j++){
                cout << maze[i][j];
            }
            cout << '\n';
        }
        return;
    }
    for(int i=0; i<4; i++){
        if(maze[x+dir[i].f][y+dir[i].s]=='.' || maze[x+dir[i].f][y+dir[i].s]=='G'){
            maze[x+dir[i].f][y+dir[i].s]='+';
            pll tmp = mp(x+dir[i].f, y+dir[i].s);
            dfs(tmp, end);
            maze[x+dir[i].f][y+dir[i].s]='.';
        }
    }
    return;
}

int main(){
    pll se[2];
    memset(maze,'#', sizeof(maze));
    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            cin >> maze[i][j];
            if(maze[i][j]=='S'){
                se[0] = mp(i, j);
            }else if(maze[i][j]=='G'){
                se[1] = mp(i, j);
            }
        }
    }
    maze[se[0].f][se[0].s] = '+';
    dfs(se[0], se[1]);
    return 0;
}