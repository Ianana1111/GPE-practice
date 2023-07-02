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

vector<pll> road[10001];
int ans = 0;

int find(int to, int from){
    int aroad = 0, tmp;
    for(auto &c: road[to]){
        if(c.f != from){
            tmp = find(c.f, to) + c.s;
            ans = max(ans, tmp+aroad);
            aroad = max(aroad, tmp);
        }
    }
    return aroad;
}

int main(){
    ios;
    string b;
    while(getline(cin, b) && b!= ""){  
        for(int i=1; i<=10000; i++) road[i].clear();
        int v1, v2, dis;
        stringstream ss;
        ss << b; ss >> v1 >> v2 >> dis;
        road[v1].pb(mp(v2, dis));
        road[v2].pb(mp(v1, dis));
        string a;
        while(getline(cin, a) && a!=""){
            int v1, v2, dis;
            stringstream ss;
            ss << a; ss >> v1 >> v2 >> dis;
            road[v1].pb(mp(v2, dis));
            road[v2].pb(mp(v1, dis));
        }
        ans = 0;
        find(1, -1);
        cout << ans << '\n';
    }
    return 0;
}