#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

int main(){
    int n; cin >> n;
    vector<int> ipt;
    for(int i=0; i<n; i++){
        int input; cin >> input;
        if(ipt.empty()) ipt.pb(input);
        else{
            if(input>ipt.back()) ipt.pb(input);
            else{
                int pos = lower_bound(ipt.begin(), ipt.end(), input)-ipt.begin();
                ipt[pos] = input;
            }
        }
    }
    cout << ipt.size() << '\n';
}