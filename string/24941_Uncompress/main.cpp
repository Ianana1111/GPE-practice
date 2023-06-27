#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

int main(){
    string s;
    vector<string> record;
    while(getline(cin, s)){
        if(s=="0") break;
        int size = record.size();
        for(int i=0; i<size; i++){
            string tmp;
            if((s[i]<='z' && s[i]>='a' )|| (s[i]<='Z' && s[i]>='A')){
                tmp+=s[i];
            }else if(tmp.size()>0){
                record.pb(tmp);
                tmp.clear();
            }
            
        }
    }
}