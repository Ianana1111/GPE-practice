#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
    ios;
    int n;
    while(cin >> n){
        if(n==0) return 0;
        int start; cin >> start;
        vector<int> path[102];
        int a, b;
        while(cin >> a && cin >> b){
            if(a==0 && b==0) break;
            path[a].push_back(b);
        }
        priority_queue<ll> pq;
        vector<ll> dis(n+1, 0);
        pq.push(start);
        while(!pq.empty()){
            int now = pq.top();
            pq.pop();
            //cout << path[now].size();
            for(auto &c:path[now]){
                if(dis[now]+1>dis[c]){
                    dis[c] = dis[now]+1;
                    //cout << c << '\n';
                    pq.push(c);
                }
            }
        }
        ll mx = -1;
        int pos;
        for(int i=1; i<=n; i++){
            if(dis[i]>mx){
                mx = dis[i];
                pos = i;
            }
            //cout << dis[i] << '\n';
        }
        cout << mx << " "<< pos <<'\n';
    }
}