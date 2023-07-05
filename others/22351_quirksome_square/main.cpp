#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<ll, ll>
#define vll vector<pll>
#define mp make_pair
#define pb push_back
#define f first 
#define s second

map<ll, int> rec;
vector<ll> quirk[9];

int find(int n, int num){
    int ans = num/n, rem = num%n;
    return ans+rem;
}

void calcu(int n){
    if(n==2){
        for(auto &c: rec){
            if(c.f<100){
                int tmp = sqrt(c.f);
                int div = find(10, c.f);
                if(tmp==div) quirk[2].pb(c.f);
            }
        }
    }else if(n==4){
        for(auto &c: rec){
            if(c.f<10000){
                int tmp = sqrt(c.f);
                int div = find(100, c.f);
                if(tmp==div) quirk[4].pb(c.f);
            }
        }
    }else if(n==6){
        for(auto &c: rec){
            if(c.f<1000000){
                int tmp = sqrt(c.f);
                int div = find(1000, c.f);
                if(tmp==div) quirk[6].pb(c.f);
            }
        }
    }else if(n==8){
        for(auto &c: rec){
            if(c.f<100000000){
                int tmp = sqrt(c.f);
                int div = find(10000, c.f);
                if(tmp==div) quirk[8].pb(c.f);
            }
        }
    }
}

int main(){
    ios;
    for(int i=0; i<=10000; i++){
        rec[i*i] = 1;
    }
    for(int i=2; i<=8; i+=2) 
        calcu(i);
    int n;
    while(cin >> n){
        for(auto &c: quirk[n]){
            cout << setw(n) << setfill('0') << c << '\n';
        }
    }
    return 0;
}