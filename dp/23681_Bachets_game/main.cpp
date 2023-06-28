#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>

int main(){
    ios;
    int n;
    while(cin >> n){
        if(n==0) return 0;
        int input; cin >> input;
        vl rec(input);
        for(int i=0; i<input; i++){
            cin >> rec[i];
        }
        sort(rec.begin(), rec.end());
        bool win[1000001];
        memset(win, false, sizeof(win));
        for(int i=1; i<=1000000; i++){
            int pos = upper_bound(rec.begin(), rec.end(), i)-rec.begin();
            for(int j=0; j<pos; j++){
                if(win[i-rec[j]]==false){
                    win[i] = true;
                    break;
                }
            }
        }
        if(win[n]) cout << "Stan wins" << '\n';
        else cout << "Ollie wins" << '\n';
    }
    return 0;
}
// 1 3 8
// T F T F T F T 