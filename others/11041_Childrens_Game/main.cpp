#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vstr vector<string>
#define pb push_back

bool compare(string a, string b){
    return a+b>b+a;
}

int main(){
    int n;
    while(cin >> n){
        if(n==0) return 0;
        vstr rec;
        string ans = "";
        for(int i=0; i<n; i++){
            string input; cin >> input;
            if(ans.empty())ans+=input;
            rec.pb(input);
        }
        sort(rec.begin(), rec.end(), compare);
        int size = rec.size();
        for(int i=0; i<size; i++){
            cout << rec[i] << " \n"[i==size-1];
        }
    }
    return 0;
}