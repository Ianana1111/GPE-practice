#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>

string a, b; 

void find(int pre, int l, int r){
    char root = a[pre];
    if(l<r){
        int mid = l;
        while(b[mid]!=root) mid++;
        if(mid>l) find(pre+1, l, mid-1);
        if(mid<r) find(pre+1+mid-l, mid+1, r);
    }
    cout << root << " ";
}

void solve(){
    int n; cin >> n;
    a=""; b="";
    for(int i=0; i<n; i++){
        char ip; cin >> ip;
        a+=ip;
    }
    for(int i=0; i<n; i++){
        char ip; cin >> ip;
        b+=ip;
    }
    find(0, 0, n-1);
    cout << '\n';
}

int main(){
    int n; cin >> n;
    while(n--){
        solve();
    }
}