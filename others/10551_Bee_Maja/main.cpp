#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define mp make_pair
#define f first
#define s second 

int direct[5][2] = {{-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};

int main(){
    pll cood[110000];
    for(int i=1, j=1, k=0; i<100000; i+=j, j+=6, k++){
        cood[i] = mp(0, k);
        for(int m=1; m<k; m++){
            cood[i-m] = mp(m, k-m); 
        }
        int cur = i;
        for(int m=0; m<5; m++){
            for(int j=0; j<k; j++){
                cood[cur+1].f = cood[cur].f + direct[m][0];
                cood[cur+1].s = cood[cur].s + direct[m][1];
                cur++;
            }
        }
    }
    int input;
    while(cin >> input){
        cout << cood[input].f << " " << cood[input].s << '\n';
    }
    return 0;
}