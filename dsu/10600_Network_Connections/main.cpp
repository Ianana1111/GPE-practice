#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

vector<ll> anes;


int find(int now){
    if(anes[now]<0)
        return now;
    return find(anes[now]);
}

void solve(){
    int n;
    cin >> n;
    anes.clear();
    vector<ll> counting(2);
    anes.resize(n+1);
    for(int i=1; i<=n; i++) anes[i]=-1;
    string s;
    getline(cin, s);
    getline(cin, s);
    while(s.size()>0){
        char a;
        int i, j;
        stringstream ss;
        ss<<s;
        ss>>a>>i>>j;
        int a1 = find(i);
        int a2 = find(j);
        if(a=='c'){
            if(a1!=a2){
                if(abs(anes[a1])<abs(anes[a2])){
                    anes[a1] = a2;
                    anes[a2]--;
                }else{
                    anes[a2] = a1;
                    anes[a1]--;
                }
            }
        }else{
            a1==a2? counting[0]++: counting[1]++; 
        }
        getline(cin, s);
    }
    cout << counting[0] << ',' << counting[1] << '\n';
    return;
}

int main(){
    int n; cin >> n;
    while(n--){
        solve();
        cout << '\n';
    }
    return 0;
}