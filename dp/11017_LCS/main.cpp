#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define vll vector<pll>
#define pb push_back
#define mp make_pair
#define f first 
#define s second 

int len[1002][1002];

int main(){
    string a, b;
    while(cin >> a >> b){
        memset(len, 0, sizeof(len));
        int size1 = a.size();
        int size2 = b.size();
        string s1 = '0'+a;
        string s2 = '0'+b;
        for(int i=1; i<=size1; i++){
            for(int j=1; j<=size2; j++){
                if(s1[i]==s2[j])
                    len[i][j] = len[i-1][j-1]+1;
                else{
                    len[i][j] = max(len[i-1][j],len[i][j-1]);
                }
            }
        }
        cout << len[size1][size2] << '\n';
    }
    return 0;
}