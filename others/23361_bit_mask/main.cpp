#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    string s;
    while(getline(cin, s)){
        if(s=="") return 0;
        ll n, m, l;
        stringstream ss;
        ss << s;
        ss >> n >> m >> l;
        ll mx = -1;
        ll pos = 0;
        for(int i=m; i<=l; i++){
            if((n|i) > mx){
                mx = n|i;
                pos= i;
            }
        }
        cout << pos << '\n';
    }
}