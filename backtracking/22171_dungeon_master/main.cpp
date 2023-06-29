#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<ll, ll>
#define f first 
#define s second
#define tp tuple<int, int, int>
#define mt std::make_tuple
#define get(i) std::get<i>


char maze[32][32][32];
tp dir[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0},{0, 0, 1}, {0, -1, 0}, {0, 0, -1}};

int ans = -1;

void BTK(tp now, tp end, int rec){
    if(get(0)(now) == get(0)(end) && get(1)(now) == get(1)(end) && get(2)(now) == get(2)(end)){
        ans = rec;
        return;
    }
    for(int i=0; i<6; i++){
        if(maze[get(0)(now)+get(0)(dir[i])][get(1)(now)+get(1)(dir[i])][get(2)(now)+get(2)(dir[i])]=='.' || maze[get(0)(now)+get(0)(dir[i])][get(1)(now)+get(1)(dir[i])][get(2)(now)+get(2)(dir[i])]=='E'){
            maze[get(0)(now)+get(0)(dir[i])][get(1)(now)+get(1)(dir[i])][get(2)(now)+get(2)(dir[i])]='+';
            BTK(mt(get(0)(now)+get(0)(dir[i]), get(1)(now)+get(1)(dir[i]), get(2)(now)+get(2)(dir[i])), end, rec+1);
            maze[get(0)(now)+get(0)(dir[i])][get(1)(now)+get(1)(dir[i])][get(2)(now)+get(2)(dir[i])]='.';
        }
    }
}

int main(){
    ios;
    int l, r, c;
    while(cin >> l >> r >> c){
        if(l==0 && r==0 && c==0) return 0;
        memset(maze, '#', sizeof(maze));

        tp se[2];
        for(int i=1; i<=l ;i++){
            for(int j=1; j<=r; j++){
                for(int k=1; k<=c; k++){
                    cin >> maze[i][j][k];
                    if(maze[i][j][k] == 'S'){
                        se[0] = mt(i, j, k);
                    }
                    if(maze[i][j][k] == 'E'){
                        se[1] = mt(i, j, k);
                    }
                }
            }
        }
        ans = -1;
        maze[get(0)(se[0])][get(1)(se[0])][get(2)(se[0])] = '+';
        BTK(se[0],se[1], 0);
        if(ans==-1) cout << "Trapped!" << '\n';
        else cout << "Escaped in "<< ans <<" minute(s)." << '\n';
    }
}