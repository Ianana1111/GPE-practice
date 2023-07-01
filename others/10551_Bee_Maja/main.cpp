#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define mp make_pair
#define f first
#define s second  

pll dir[5] = {{-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};
pll pos[100001];

int main(){
    pos[1]={0, 0};
    for(int i=1, j=2; j<=100000; j+=(6*i+1), i++){
        pos[j] = mp(0, i);
        int count = 1;
        for(int k=0; k<5; k++){
            for(int t=0; t<i; t++){
                int n = j+count;
                pos[n] = mp(pos[n-1].f+dir[k].f, pos[n-1].s+dir[k].s);
                count++;
            }
        }
        for(int k=0 ; k<i; k++){
            pos[j-k] = mp(k, i-k);
        }
    }
    int n;
    while(cin >> n) {
        cout << pos[n].f << " " << pos[n].s << '\n';
    }
}