#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vl vector<ll>
#define pb push_back
#define f first 

map<string, string> anes;
map<string, vector<string>> rec;

void find(vector<string> out, int num_spa){
    if(out.empty()) return;
    for(int i=0; i<num_spa; i++)
        cout << " ";
    sort(out.begin(), out.end());
    for(auto &c: out){
        cout << c <<'\n';
        find(rec[c], num_spa+1);
    }
    return;
}

int main(){
    int n; cin >> n;
    string s;
    getline(cin, s);
    while(n--){
        getline(cin, s);
        int size = s.size();
        string last = "";
        string tmp = "";
        for(int i=0; i<size; i++){
            if(s[i]!='\\'){
                tmp+=s[i];
            }else{
                anes[tmp] = last;
                if(last!=""){
                    rec[last].pb(tmp);
                }
                last = tmp;
                tmp = "";
            }
        }
        if(last=="") anes[tmp] = last;
        else{
            anes[tmp] = last;
            rec[last].pb(tmp);
        }    
    }
    vector<string> check;
    for(auto &c: rec){
        if(anes[c.f]=="")
            check.pb(c.f);
    }
    find(check, 0);
    return 0;
}