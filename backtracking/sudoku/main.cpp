#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_wtidh_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>

bool visit = false;

bool check(int arr[10][10], int pos, int now){
    int x = pos/9, y = pos%9;
    for(int i=0; i<9; i++){
        if(arr[x][i]==now) return false;
    }
    for(int i=0; i<9; i++){
        if(arr[i][y]==now) return false;
    }
    int reg_x = (x/3)*3, reg_y = (y/3)*3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[reg_x+i][reg_y+j]==now)
                return false;
        }
    }
    return true;
}

void keyin(int arr[10][10], int pos){
    if(pos==81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << arr[i][j] << " \n"[j==8];
            }
        }
        visit = true;
        return;
    }else{
        int x = pos/9, y = pos%9;
        if(arr[x][y]==0){
            for(int i=1; i<=9; i++){
                if(check(arr, pos, i)){
                    arr[x][y] = i;
                    keyin(arr, pos+1);
                    //cout << pos << '\n';
                }
                arr[x][y] = 0;
            }
        }else{
            keyin(arr, pos+1);  
        }
    }
    return;
}

void solve(){
    int arr[10][10];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> arr[i][j];
        }
    }
    keyin(arr, 0);
}

int main(){
    int n; cin >> n;
    while(n--){
        visit = false;
        solve();
        if(!visit) cout << "NO" << '\n';
    }
    return 0;
}