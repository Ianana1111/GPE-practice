#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back

int st_x, st_y, st_z, en_x, en_y, en_z;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
char arr[32][32][32];

int find(){
    queue<int> X, Y, Z;
    X.push(st_x); Y.push(st_y); Z.push(st_z);
    int ans = 1;
    while(!X.empty()){
        int size = X.size();
        for(int k=0; k<size; k++){
            int tx = X.front(), ty = Y.front(), tz = Z.front(); 
            X.pop(); Y.pop(); Z.pop();
            for(int i=0; i<6; i++){
                int new_x = tx+dx[i], new_y = ty+dy[i], new_z = tz + dz[i];

                if(arr[new_z][new_x][new_y]=='.'){
                    arr[new_z][new_x][new_y] = '#';
                    X.push(new_x); Y.push(new_y); Z.push(new_z);
                }
                if(arr[new_z][new_x][new_y]=='E')
                    return ans;
            }
        }
        ans++;
    }
    return -1;
}

int main(){
    ios;
    int z, x, y;
    while(cin >> z >> x >> y && x && y && z){
        memset(arr, '#', sizeof(arr));
        for(int i=1; i<=z; i++){
            for(int j=1; j<=x; j++){
                for(int k=1; k<=y; k++){
                    cin >> arr[i][j][k];
                    if(arr[i][j][k] == 'S'){
                        st_x = j; st_y = k; st_z = i;
                    }
                    if(arr[i][j][k] == 'E'){
                        en_x = j; en_y = k; en_z = i;
                    }
                }
            }
        }
        arr[st_x][st_y][st_z] = '#';
        int ans = find();
        if(ans==-1) cout << "Trapped!" << '\n';
        else cout << "Escaped in " << ans <<" minute(s)."<< '\n';
    }
    return 0;
}