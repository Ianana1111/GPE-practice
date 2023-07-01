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
int step[3] = {1, 2, 3};
int ans;

void find(pll now, pll end, int pos){
    int stp = step[pos%3], x = now.f, y = now.s;
    if(x==end.f && y==end.s){
        ans = min(ans, pos);
        return;
    }
    bool test = false;
    //cout << x << " " << y << '\n';
    if(arr[x - stp][y]=='.' || arr[x - stp][y] == 'E'){
        for(int i=0; i<stp; i++){
            if(arr[x - i][y]=='#') test = true;
        }
        if(!test){
            pll tmp = mp(x-stp, y);
            arr[x - stp][y]='@';
            find(tmp, end, pos+1);
            arr[x - stp][y]='.';
        }
    }
    test = false;
    if(arr[x][y+stp]=='.' || arr[x][y+stp] == 'E'){
        for(int i=0; i<stp; i++){
            if(arr[x][y+i]=='#') test = true;
        }
        if(!test){
            pll tmp = mp(x, y+stp);
            arr[x][y+stp]='@';
            find(tmp, end, pos+1);
            arr[x][y+stp]='.';
        }
    }
    test = false;
    if(arr[x + stp][y]=='.' || arr[x + stp][y] == 'E'){
        for(int i=0; i<stp; i++){
            if(arr[x + i][y]=='#') test = true;
        }
        if(!test){
            pll tmp = mp(x+stp, y);
            arr[x + stp][y]='@';
            find(tmp, end, pos+1);
            arr[x + stp][y]='.';
        }
    }
    test = false;
    if(arr[x][y - stp]=='.' || arr[x][y - stp] == 'E'){
        for(int i=0; i<stp; i++){
            if(arr[x][y - i]=='#') test = true;
        }
        if(!test){
            pll tmp = mp(x, y - stp);
            arr[x][y - stp]='@';
            find(tmp, end, pos+1);
            arr[x][y - stp]='.';
        }
    }
    return;
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
    ans = INT_MAX;
    arr[se[0].f][se[0].s] = '@';
    find(se[0], se[1], 0);
    if(ans==INT_MAX) cout << "NO" <<'\n';
    else cout << ans << '\n';
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